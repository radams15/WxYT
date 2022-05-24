#include <wx/wx.h>
#include <wx/filename.h>
#include <vlc/vlc.h>
#include <climits>

#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#define GET_XID(window) GDK_WINDOW_XWINDOW(GTK_PIZZA(window->m_wxwindow)->bin_window)
#endif

#include "PlayerDlg.h"

#define myID_PLAYPAUSE wxID_HIGHEST+1
#define myID_STOP wxID_HIGHEST+2
#define myID_TIMELINE wxID_HIGHEST+3
#define myID_VOLUME wxID_HIGHEST+4

#define TIMELINE_MAX (INT_MAX-9)
#define VOLUME_MAX 100

DECLARE_EVENT_TYPE(vlcEVT_END, -1)
DECLARE_EVENT_TYPE(vlcEVT_POS, -1)
DEFINE_EVENT_TYPE(vlcEVT_END)
DEFINE_EVENT_TYPE(vlcEVT_POS)

void OnPositionChanged_VLC(const libvlc_event_t *event, void *data);
void OnEndReached_VLC(const libvlc_event_t *event, void *data);

PlayerDlg::PlayerDlg(wxWindow *parent, wxString url) : wxFrame(parent, wxID_ANY, wxT("Video Player"), wxDefaultPosition) {
    // setup vbox
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(vbox);

    //setup player widget
    player_widget = new wxWindow(this, wxID_ANY);
    player_widget->SetBackgroundColour(wxColour(wxT("black")));
    vbox->Add(player_widget, 1, wxEXPAND | wxALIGN_TOP);

    //setup timeline slider
    timeline = new wxSlider(this, myID_TIMELINE, 0, 0, TIMELINE_MAX);
    timeline->Enable(false);
    vbox->Add(timeline, 0, wxEXPAND);
    connectTimeline();
    timeline->Connect(myID_TIMELINE, wxEVT_LEFT_UP, wxMouseEventHandler(PlayerDlg::OnTimelineClicked));

    //setup control panel
    wxPanel *controlPanel = new wxPanel(this, wxID_ANY);

    //setup hbox
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    controlPanel->SetSizer(hbox);
    vbox->Add(controlPanel, 0, wxEXPAND);

    //setup controls
    playpause_button = new wxButton(controlPanel, myID_PLAYPAUSE, wxT("Play"));
    stop_button = new wxButton(controlPanel, myID_STOP, wxT("Stop"));
    volume_slider = new wxSlider(controlPanel, myID_VOLUME, VOLUME_MAX, 0, VOLUME_MAX, wxDefaultPosition, wxSize(100, -1));
    playpause_button->Enable(false);
    stop_button->Enable(false);
    hbox->Add(playpause_button);
    hbox->Add(stop_button);
    hbox->AddStretchSpacer();
    hbox->Add(volume_slider);
    Connect(myID_PLAYPAUSE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PlayerDlg::OnPlayPause));
    Connect(myID_STOP, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PlayerDlg::OnStop));
    Connect(myID_VOLUME, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(PlayerDlg::OnVolumeChanged));
    volume_slider->Connect(myID_VOLUME, wxEVT_LEFT_UP, wxMouseEventHandler(PlayerDlg::OnVolumeClicked));

    //setup vlc
    vlc_inst = libvlc_new(0, NULL);
    media_player = libvlc_media_player_new(vlc_inst);
    vlc_evt_man = libvlc_media_player_event_manager(media_player);
    libvlc_event_attach(vlc_evt_man, libvlc_MediaPlayerEndReached, ::OnEndReached_VLC, this);
    libvlc_event_attach(vlc_evt_man, libvlc_MediaPlayerPositionChanged, ::OnPositionChanged_VLC, this);
    Connect(wxID_ANY, vlcEVT_END, wxCommandEventHandler(PlayerDlg::OnEndReached_VLC));
    Connect(wxID_ANY, vlcEVT_POS, wxCommandEventHandler(PlayerDlg::OnPositionChanged_VLC));

    Show(true);
    initVLC();

    libvlc_media_t *media;
    media = libvlc_media_new_location(vlc_inst, (const char*) url.mb_str());
    libvlc_media_player_set_media(media_player, media);
    play();
    libvlc_media_release(media);
}

PlayerDlg::~PlayerDlg() {
    libvlc_media_player_release(media_player);
    libvlc_release(vlc_inst);
}

void PlayerDlg::initVLC() {
#ifdef __WXGTK__
    libvlc_media_player_set_xwindow(media_player, gdk_x11_window_get_xid(gtk_widget_get_window(player_widget->GetHandle())));
#else
    libvlc_media_player_set_hwnd(media_player, this->player_widget->GetHandle());
#endif
}

void PlayerDlg::OnPlayPause(wxCommandEvent& event) {
    if(libvlc_media_player_is_playing(media_player) == 1) {
        pause();
    }
    else {
        play();
    }
}

void PlayerDlg::OnStop(wxCommandEvent& event) {
    stop();
}

void PlayerDlg::OnPositionChanged_USR(wxCommandEvent& event) {
    libvlc_media_player_set_position(media_player, (float) event.GetInt() / (float) TIMELINE_MAX);
}

void PlayerDlg::OnPositionChanged_VLC(wxCommandEvent& event) {
    float factor = libvlc_media_player_get_position(media_player);
    setTimeline(factor);
}

void PlayerDlg::OnEndReached_VLC(wxCommandEvent& event) {
    stop();
}

void PlayerDlg::OnVolumeChanged(wxCommandEvent& event) {
    libvlc_audio_set_volume(media_player, volume_slider->GetValue());
}

void PlayerDlg::OnVolumeClicked(wxMouseEvent& event) {
    wxSize size = volume_slider->GetSize();
    float position = (float) event.GetX() / (float) size.GetWidth();
    volume_slider->SetValue(position*VOLUME_MAX);
    libvlc_audio_set_volume(media_player, position*VOLUME_MAX);
    event.Skip();
}

void PlayerDlg::OnTimelineClicked(wxMouseEvent& event) {
    wxSize size = timeline->GetSize();
    float position = (float) event.GetX() / (float) size.GetWidth();
    libvlc_media_player_set_position(media_player, position);
    setTimeline(position);
    event.Skip();
}

void PlayerDlg::play() {
    libvlc_media_player_play(media_player);
    playpause_button->SetLabel(wxT("Pause"));
    playpause_button->Enable(true);
    stop_button->Enable(true);
    timeline->Enable(true);
}

void PlayerDlg::pause() {
    libvlc_media_player_pause(media_player);
    playpause_button->SetLabel(wxT("Play"));
}

void PlayerDlg::stop() {
    pause();
    libvlc_media_player_stop(media_player);
    stop_button->Enable(false);
    setTimeline(0.0);
    timeline->Enable(false);
}

void PlayerDlg::setTimeline(float value) {
    if(value < 0.0) value = 0.0;
    if(value > 1.0) value = 1.0;
    Disconnect(myID_TIMELINE);
    timeline->SetValue((int) (value * TIMELINE_MAX));
    connectTimeline();
}

void PlayerDlg::connectTimeline() {
    Connect(myID_TIMELINE, wxEVT_COMMAND_SLIDER_UPDATED, wxCommandEventHandler(PlayerDlg::OnPositionChanged_USR));
}

void OnPositionChanged_VLC(const libvlc_event_t *event, void *data) {
    wxCommandEvent evt(vlcEVT_POS, wxID_ANY);
    ((PlayerDlg*) data)->GetEventHandler()->AddPendingEvent(evt);
}

void OnEndReached_VLC(const libvlc_event_t *event, void *data) {
    wxCommandEvent evt(vlcEVT_END, wxID_ANY);
    ((PlayerDlg*) data)->GetEventHandler()->AddPendingEvent(evt);
}
