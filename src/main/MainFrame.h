//
// Created by rhys on 12/05/22.
//

#ifndef GEMCLIENT_MAINFRAME_H
#define GEMCLIENT_MAINFRAME_H

#include <Config.h>

#include "UI.h"
#include "GetVidThread.h"

class MainFrame : public MainFrameBase {
DECLARE_EVENT_TABLE();

private:
    Config* conf;
    GetVidThread* CurrentThread;

    void ClearList();

    void AddVideo(Video_t* video);
    void AddChannel(Channel_t* channel);

    void LoadAll();
    void LoadVideos(List_t* list);

    void LoadChannels(List_t* list);

    void ShowLoading();
    void HideLoading();

protected:

    void OnHome( wxCommandEvent& event );
    void OnChannel( wxCommandEvent& event );
    void OnSearch( wxCommandEvent& event );

public:
    MainFrame( Config* config, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("WxYT"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,549 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

    void PlayVideo(Video_t* video);
    void LoadChannel(Channel_t* channel);
    void OnVidThreadComplete( wxCommandEvent& event );
};


#endif //GEMCLIENT_MAINFRAME_H
