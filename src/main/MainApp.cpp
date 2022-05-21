//
// Created by rhys on 22/01/2022.
//

#include "MainApp.h"

extern "C" void gtk_tweak_setup();

MainApp::MainApp() : wxApp(){
    wxInitAllImageHandlers();

    conf = config_new("../yt_saves.json.small", 0);
    //conf = config_new("/home/rhys/.config/yt_saves.json.small", 0);
    //conf = config_new("/home/rhys/.config/yt_saves.json", 0);
    conf->use_threading = 1;

#if defined(__WXGTK3__) && USE_HEADERBAR
    gtk_tweak_setup();
#endif
}

bool MainApp::OnInit() {
    frame = new MainFrame(conf, NULL);

    frame->Show(true);

    return true;
}

MainApp::~MainApp() {
    config_save(conf);

    //config_free(conf);
}