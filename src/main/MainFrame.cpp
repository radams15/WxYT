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
#include "PlayerDlg.h"
#include "SearchDlg.h"
#include "ChannelBox.h"

extern "C" void tweak(void* window);

pthread_mutex_t mutex;

MainFrame::MainFrame(Config* config, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : MainFrameBase(parent, id, title, pos, size, style){

    this->conf = config;

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

    VideoList->Prepend(box, 1, wxALL, 5);

    VideoList->Layout();
}

void MainFrame::PlayVideo(Video_t *video) {
    const char* CVideo = video_get_playable(video, conf);
    wxString url = wxString::FromUTF8(CVideo);
    free((void*) CVideo);

    PlayerDlg* player = new PlayerDlg(this, url);

    //player->MediaPlayer->Play();

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

    VideoList->RecalcSizes();
}

void MainFrame::LoadAll() {
    List_t* vids = config_get_vids_list(conf);

    LoadVideos(vids);
}

void MainFrame::LoadChannel(Channel_t *channel) {
    List_t* vids = channel_get_vids_list(channel, conf);

    LoadVideos(vids);
}

void MainFrame::OnSearch(wxCommandEvent &event) {
    SearchDlg* dlg = new SearchDlg(this);

    if(dlg->ShowModal() != wxID_OK){
        return;
    }

    wxString query = dlg->GetQuery();

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
        AddChannel(channels_get(list, i));
    }
}
