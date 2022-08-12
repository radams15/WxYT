//
// Created by rhys on 12/05/22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"
#include "VideoBox.h"

#include "lib/librequest/include/request.h"
#include "SearchDlg.h"
#include "ChannelBox.h"

#ifdef WX_PLAYER
#include "VideoPlayers/Wx/PlayerDlg.h"
#endif

#ifdef VLC_PLAYER
#include "VideoPlayers/Vlc/PlayerDlg.h"
#endif

BEGIN_EVENT_TABLE( MainFrame, MainFrameBase )
                EVT_COMMAND(wxID_ANY, EVT_VID_THREAD_COMPLETED, MainFrame::OnVidThreadComplete)
END_EVENT_TABLE()

extern "C" void tweak(void* window);

static pthread_mutex_t mutex;

MainFrame::MainFrame(Config* config, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : MainFrameBase(parent, id, title, pos, size, style){

    this->conf = config;
    CurrentThread = NULL;

#if defined(__apple__)

#elif defined(__linux)
    MenuBar->Show(false);
#else
    ToolBar->Show(false);
#endif


#ifdef __WXCOCOA__
    NSWindow* win = MacGetTopLevelWindowRef();
    tweak((void*)win);
#endif
#ifdef __WXGTK3__
    tweak((void*) wxWindow::GetHandle());
#endif
#ifdef __WXQT__
    tweak((void*) GetQMainWindow());
#endif

    LoadAll();
}

void MainFrame::AddVideo(Video_t* video) {
    VideoBox* box = new VideoBox(VidScrollWin, video, this);

    VideoList->Prepend(box, 1, wxALL, 5);

    VideoList->Layout();
    //VideoList->RecalcSizes();
}

void MainFrame::AddChannel(Channel_t *channel) {
    ChannelBox* box = new ChannelBox(conf, VidScrollWin, channel, this);

    VideoList->Add(box, 1, wxALL, 5);

    VideoList->Layout();
}

void MainFrame::PlayVideo(Video_t *video) {
    ShowLoading();

    const char* CVideo = video_get_playable(video, conf);
    wxString url = wxString::FromUTF8(CVideo);
    free((void*) CVideo);

    //std::cout << "Raw URL: " << url.mb_str() << std::endl;

    PlayerDlg* player = new PlayerDlg(this, url);

    HideLoading();

    player->Show();
}

void MainFrame::OnHome(wxCommandEvent &event) {
    LoadAll();
}

void MainFrame::OnChannel(wxCommandEvent &event) {
    LoadChannels(conf->subs);
}

void MainFrame::ClearList() {
    for(int i=0 ; i<VideoList->GetChildren().GetCount() ; i++) {
        VideoList->GetChildren()[i]->Show(false);
    }

    for(int i=0 ; i<VideoList->GetChildren().GetCount() ; i++){
        VideoList->Remove(0);
    }

    VideoList->Clear();

    //VideoList->RecalcSizes();
}

void MainFrame::LoadAll() {
    if(CurrentThread == NULL) {
        ShowLoading();
        CurrentThread = new GetVidThread(this, conf, NULL);
        CurrentThread->Create();
        CurrentThread->Run();
    }
}

void MainFrame::LoadChannel(Channel_t *channel) {
    if(CurrentThread == NULL) {
        ShowLoading();

        CurrentThread = new GetVidThread(this, conf, channel);
        CurrentThread->Create();
        CurrentThread->Run();
    }
}

void MainFrame::OnSearch(wxCommandEvent &event) {
    SearchDlg* dlg = new SearchDlg(this);

    if(dlg->ShowModal() != wxID_OK){
        return;
    }

    wxString query = dlg->GetQuery();

    ShowLoading();

    switch(dlg->GetType()){
        case SearchDlg::TYPE_VIDEO: {
            List_t *vids = config_video_search_list(conf, query.ToUTF8(), 1);
            LoadVideos(vids);
        }
            break;
        case SearchDlg::TYPE_CHANNEL: {
            List_t *vids = channel_search_list(conf, query.ToUTF8(), 1);
            LoadChannels(vids);
        }
            break;

        default:
            break;
    }

    HideLoading();
}

void MainFrame::LoadVideos(List_t* list) {
    ClearList();

    for(int i=0 ; i<list->length ; i++){
        AddVideo(videos_get(list, i));
    }
}

void MainFrame::LoadChannels(List_t *list) {
    ClearList();

    for(int i=0 ; i<list->length ; i++){
        Channel_t* c = channels_get(list, i);

        if(c == NULL){
            continue;
        }

        AddChannel(c);
    }
}

void MainFrame::OnVidThreadComplete(wxCommandEvent &event) {
    List_t* lst = (List_t*) event.GetClientData();

    CurrentThread = NULL;

    LoadVideos(lst);

    HideLoading();
}

void MainFrame::ShowLoading() {
    busyInfo = new wxBusyInfo(wxT("Loading..."));
    wxWindow::SetCursor(*wxHOURGLASS_CURSOR);
}

void MainFrame::HideLoading() {
    delete busyInfo;
    wxWindow::SetCursor(*wxSTANDARD_CURSOR);
}
