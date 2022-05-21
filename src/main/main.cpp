#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainApp.h"

int main(int argc, char** argv) {
    MainApp* app = new MainApp();

    wxApp::SetInstance( app );
    wxEntryStart(argc, argv);
    wxTheApp->CallOnInit();
    wxTheApp->OnRun();

    delete app;

    return 0;
}
