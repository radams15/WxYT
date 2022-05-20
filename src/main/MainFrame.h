//
// Created by rhys on 12/05/22.
//

#ifndef GEMCLIENT_MAINFRAME_H
#define GEMCLIENT_MAINFRAME_H

#include <Config.h>
#include "UI.h"

class MainFrame : public MainFrameBase {
private:
    Config* conf;

    void ClearList();

    void LoadAll();
    void LoadChannel(Channel_t* channel);

protected:

    void OnHome( wxCommandEvent& event );
    void OnChannel( wxCommandEvent& event );

public:
    MainFrame( Config* config, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("YtClient"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,549 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    void AddVideo(Video_t* video, bool sort=true);

    void PlayVideo(Video_t* video);
};


#endif //GEMCLIENT_MAINFRAME_H
