//
// Created by rhys on 12/05/22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"
#include "VideoBox.h"
#include "ChannelSelectDlg.h"

#include "lib/librequest/include/request.h"
#include "PlayerDlg.h"

extern "C" void tweak(void* window);

pthread_mutex_t mutex;
MainFrame* frame;

void VideoCallback(Video_t* vid, void* ptr){
    pthread_mutex_lock(&mutex);
    //printf("Locked\n");

    MainFrame* app = (MainFrame*) app;

    frame->AddVideo(vid);

    //printf("Unlocked\n");
    pthread_mutex_unlock(&mutex);
}


MainFrame::MainFrame(Config* config, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : MainFrameBase(parent, id, title, pos, size, style){

    this->conf = config;
    frame = this;

    //printf("Frame: %x\n", frame);

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

void MainFrame::AddVideo(Video_t* video, bool sort) {
    VideoBox* box = new VideoBox(VidScrollWin, video, this);

    VideoList->Prepend(box, 1, wxALL, 5);

    VideoList->Layout();
    //VideoList->RecalcSizes();
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
    ClearList();
    config_get_vids(conf, VideoCallback, this);
}

void MainFrame::OnChannel(wxCommandEvent &event) {
    wxVector<Channel_t*> channels(conf->subs->length);

    for(int i=0 ; i<conf->subs->length ; i++){
        channels[i] = (conf->subs->arry[i]);
    }
    ChannelSelectDlg* dlg = new ChannelSelectDlg(this, channels);

    int ret = dlg->ShowModal();

    if(ret != wxID_OK){
        return;
    }

    if(dlg->IsAll()){
        LoadAll();
    }else{
        LoadChannel(dlg->Get());
    }
}

void MainFrame::ClearList() {
    for(int i=0 ; i<VideoList->GetChildren().GetCount() ; i++){
        VideoList->Remove(0);
    }

    VideoList->RecalcSizes();
}

void MainFrame::LoadAll() {
    ClearList();

    Videos_t* vids = config_get_vids_list(conf);

    for(int i=0 ; i<vids->length ; i++){
        AddVideo(vids->arry[i]);
    }
}

void MainFrame::LoadChannel(Channel_t *channel) {
    ClearList();

    //channel_get_vids(channel, conf, VideoCallback, this);
}
