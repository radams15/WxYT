//
// Created by rhys on 5/23/22.
//

#ifndef WXYT_PLAYERDLG_H
#define WXYT_PLAYERDLG_H

#include <wx/wx.h>
#include <vlc/vlc.h>

class PlayerDlg : public wxFrame {

private:
    void initVLC();

    void OnPlayPause(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnPositionChanged_USR(wxCommandEvent& event);
    void OnPositionChanged_VLC(wxCommandEvent& event);
    void OnEndReached_VLC(wxCommandEvent& event);
    void OnVolumeChanged(wxCommandEvent& event);
    void OnVolumeClicked(wxMouseEvent& event);
    void OnTimelineClicked(wxMouseEvent& event);

    void play();
    void pause();
    void stop();
    void setTimeline(float value);
    void connectTimeline();

    wxButton *playpause_button;
    wxButton *stop_button;
    wxSlider *timeline;
    wxSlider *volume_slider;
    wxWindow *player_widget;

    libvlc_media_player_t *media_player;
    libvlc_instance_t *vlc_inst;
    libvlc_event_manager_t *vlc_evt_man;

public:
    PlayerDlg(wxWindow *parent, wxString url);

    ~PlayerDlg();
};


#endif //WXYT_PLAYERDLG_H
