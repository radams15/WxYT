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

DECLARE_EVENT_TYPE(vlcEVT_END, -1)
DECLARE_EVENT_TYPE(vlcEVT_POS, -1)
DEFINE_EVENT_TYPE(vlcEVT_END)
DEFINE_EVENT_TYPE(vlcEVT_POS)

void OnPositionChanged_VLC(const libvlc_event_t *event, void *data);
void OnEndReached_VLC(const libvlc_event_t *event, void *data);

wxString FormatSecs(double secs) {
    unsigned long hours = (int) secs / (60*60);
    unsigned long mins = (int) secs / 60;
    unsigned long remainingSecs = (int) secs % 60;

    return wxString::Format(wxT("%03lu:%02lu:%02lu"), hours,mins, remainingSecs);
}

PlayerDlg::PlayerDlg(wxWindow *parent, wxString url) : wxFrame(parent, wxID_ANY, wxT("Video Player"), wxDefaultPosition) {
    // setup vbox
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(vbox);

    //setup player widget
    player_widget = new wxWindow(this, wxID_ANY);
    player_widget->SetBackgroundColour(wxColour(wxT("black")));
    vbox->Add(player_widget, 1, wxEXPAND | wxALIGN_TOP);

    wxBoxSizer* progressBox = new wxBoxSizer(wxHORIZONTAL);

    //setup timeline slider
    timeline = new wxSlider(this, myID_TIMELINE, 0, 0, 100);
    progressBox->Add( timeline, 7, wxALL, 5 );
    connectTimeline();

    PosLbl = new wxStaticText( this, wxID_ANY, wxT("000:00:00 / 000:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
    PosLbl->Wrap( -1 );
    progressBox->Add( PosLbl, 2, wxALL, 5 );

    vbox->Add(progressBox, 0, wxEXPAND, 5);

    //setup control panel
    wxPanel *controlPanel = new wxPanel(this, wxID_ANY);

    //setup hbox
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    controlPanel->SetSizer(hbox);
    vbox->Add(controlPanel, 0, wxEXPAND);

    //setup controls
    playpause_button = new wxButton(controlPanel, myID_PLAYPAUSE, wxT("Play"));
    stop_button = new wxButton(controlPanel, myID_STOP, wxT("Stop"));
    playpause_button->Enable(false);
    stop_button->Enable(false);
    hbox->Add(playpause_button);
    hbox->Add(stop_button);
    hbox->AddStretchSpacer();
    Connect(myID_PLAYPAUSE, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PlayerDlg::OnPlayPause));
    Connect(myID_STOP, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PlayerDlg::OnStop));

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
    } else {
        play();
    }
}

void PlayerDlg::OnStop(wxCommandEvent& event) {
    stop();
}

void PlayerDlg::OnPositionChanged_USR(wxCommandEvent& event) {
    float newDec = event.GetInt();

    libvlc_media_player_set_position(media_player, newDec/100.0f);
}

void PlayerDlg::OnPositionChanged_VLC(wxCommandEvent& event) {
    float positionDec = libvlc_media_player_get_position(media_player);
    long length = libvlc_media_player_get_length(media_player)/1000l;

    setTimeline(positionDec);
    PosLbl->SetLabel(wxString::Format(wxT("%s / %s"), FormatSecs(positionDec*(float) length), FormatSecs(length)));
}

void PlayerDlg::OnEndReached_VLC(wxCommandEvent& event) {
    stop();
}

void PlayerDlg::play() {
    libvlc_media_player_play(media_player);
    playpause_button->SetLabel(wxT("Pause"));
    playpause_button->Enable(true);
    stop_button->Enable(true);
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
    //Disconnect(myID_TIMELINE);

    timeline->SetValue(value*100.0f);

    //connectTimeline();
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
