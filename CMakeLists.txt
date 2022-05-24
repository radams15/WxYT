cmake_minimum_required(VERSION 3.0)

#set(CMAKE_OSX_ARCHITECTURES ppc;x86_64)
#set(CMAKE_OSX_DEPLOYMENT_TARGET 10.4)
#set(CMAKE_OSX_SYSROOT "/Developer/SDKs/MacOSX10.4u.sdk")

project(WxYT C CXX)

set(CMAKE_CXX_STANDARD 11)

option(HEADERBAR "Uses unified titlebar and toolbar (OSX/Gtk3 Only)" OFF)
option(GTK_STYLE "Uses libhandy (Gtk3) / libgranite (Gtk3) styling" OFF)
option(WX_PLAYER "Uses wxMediaCtrl to play videos" OFF)
option(VLC_PLAYER "Uses libvlc to play videos" ON)


set(WX_COMPONENTS core base adv)

if(WX_PLAYER)
    set(WX_COMPONENTS media ${WX_COMPONENTS})
endif()

find_package(wxWidgets REQUIRED COMPONENTS ${WX_COMPONENTS})


find_package(PkgConfig REQUIRED)

add_subdirectory(lib/libyt)

include(${wxWidgets_USE_FILE})

set(SOURCE src/main/main.cpp src/main/MainApp.cpp src/main/UI.cpp src/main/UI.cpp src/main/MainFrame.cpp src/main/MainFrame.h src/main/VideoBox.cpp src/main/VideoBox.h src/main/specific/SearchDlg.cpp src/main/SearchDlg.h src/main/ChannelBox.cpp src/main/ChannelBox.h)
set(LIBS ${wxWidgets_LIBRARIES} -L${CMAKE_SOURCE_DIR}/lib pthread)
set(INCLUDE DIRS "")
set(LINK_DIRS "")

if(WX_PLAYER)
    set(SOURCE ${SOURCE} src/main/VideoPlayers/Wx/PlayerDlg.cpp src/main/VideoPlayers/Wx/WxPlayer.cpp)
endif()

if(VLC_PLAYER)
    set(SOURCE ${SOURCE} src/main/VideoPlayers/Vlc/PlayerDlg.cpp)
    set(LIBS ${LIBS} vlc)
endif()

if(APPLE)
    set(SOURCE ${SOURCE} src/main/specific/Cocoa.mm)
endif()

if(UNIX AND NOT APPLE)
    pkg_check_modules(GTK3 gtk+-3.0)
    pkg_check_modules(GTK2 gtk+-2.0)

    pkg_check_modules(GRANITE granite)
    pkg_check_modules(HANDY libhandy-1)

    find_package(Qt5 COMPONENTS Widgets)
    
    pkg_check_modules(GST gstreamer-video-1.0)
    
    set(LIBS ${LIBS} ${GST_LIBRARIES})
    set(INCLUDE_DIRS ${LIBS} ${GST_INCLUDE_DIRS})

    if(${GTK3_FOUND})
        set(SOURCE ${SOURCE} src/main/specific/Gtk.c)
    elseif(${Qt5_FOUND})
        set(SOURCE ${SOURCE} src/main/specific/Qt.cpp)
    endif()
endif()

if(${GTK3_FOUND})
    set(INCLUDE_DIRS ${INCLUDE_DIRS} ${GTK3_INCLUDE_DIRS})
    set(LINK_DIRS ${LINK_DIRS} ${GTK3_LIBRARIES})
    set(LIBS ${LIBS} ${GTK3_LIBRARIES})
elseif(${Qt5_FOUND})
    set(LIBS ${LIBS} Qt5::Widgets)
endif()

include_directories(${INCLUDE_DIRS} lib/libyt/include)
link_directories(${LINK_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/lib/vlc)

add_executable(WxYT MACOSX_BUNDLE ${SOURCE})

if(HEADERBAR)
    message("Using headerbar")
    target_compile_definitions(WxYT PUBLIC USE_HEADERBAR)
endif()

if("GTK_STYLE" AND "${GRANITE_FOUND}")
    message("Using elementary theming (granite)")
    target_compile_definitions(WxYT PUBLIC USE_GRANITE)

    set(LIBS ${LIBS} ${GRANITE_LIBRARIES})
    set(LINK_DIRS ${LINK_DIRS} ${GRANITE_LIBRARIES})
    set(INCLUDE_DIRS ${INCLUDE_DIRS} ${GRANITE_INCLUDE_DIRS})
elseif("GTK_STYLE" AND "${HANDY_FOUND}")
    message("Using gnome theming (libhandy)")
    target_compile_definitions(WxYT PUBLIC USE_HANDY)

    set(LIBS ${LIBS} ${HANDY_LIBRARIES})
    set(LINK_DIRS ${LINK_DIRS} ${HANDY_LIBRARIES})
    set(INCLUDE_DIRS ${INCLUDE_DIRS} ${HANDY_INCLUDE_DIRS})
endif()

if(WX_PLAYER)
    target_compile_definitions(WxYT PRIVATE WX_PLAYER)
endif()

if(VLC_PLAYER)
    target_compile_definitions(WxYT PRIVATE VLC_PLAYER)
endif()

target_include_directories(WxYT PRIVATE lib/libyt lib/vlc)

target_link_libraries(WxYT yt request ${LIBS})
