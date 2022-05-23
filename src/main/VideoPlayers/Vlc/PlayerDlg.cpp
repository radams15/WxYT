//
// Created by rhys on 5/23/22.
//

#include "PlayerDlg.h"

wxDEFINE_EVENT(vlcEVT_POS,wxThreadEvent);
wxDEFINE_EVENT(vlcEVT_END,wxThreadEvent);

static wxEvtHandler* gs_handler = NULL;

void OnPositionChanged_VLC(float f)
{
    if ( gs_handler )
    {
        wxThreadEvent* event = new wxThreadEvent(vlcEVT_POS);
        event->SetPayload<float>(f);
        wxQueueEvent(gs_handler,event);
    }
}

void OnEndReached_VLC()
{
    if ( gs_handler )
    {
        wxThreadEvent* event = new wxThreadEvent(vlcEVT_END);
        wxQueueEvent(gs_handler,event);
    }
}

PlayerDlg::PlayerDlg(wxWindow *parent, wxString url) : wxFrame(parent, wxID_ANY, "Video Player") {
    wxPanel* bgPanel = new wxPanel(this, wxID_ANY);

    // Create the window the VLC will draw to.
    m_playerWidget = new wxWindow(bgPanel, wxID_ANY);

    // Create the timeline slider.
    m_timeline = new wxSlider(bgPanel, wxID_ANY, 0, 0, TIMELINE_MAX);

    // Create play button, the stop button, and the volume slider.
    m_playPauseButton = new wxButton(bgPanel, wxID_ANY, "Play");
    m_stopButton = new wxButton(bgPanel, wxID_ANY, "Stop");
    m_volumeSlider = new wxSlider(bgPanel, wxID_ANY, VOLUME_MAX, 0, VOLUME_MAX);


    // Set the video window black and disable the timeline and buttons.
    m_playerWidget->SetBackgroundColour(*wxBLACK);
    m_timeline->Enable(false);
    m_playPauseButton->Enable(false);
    m_stopButton->Enable(false);


    // Use sizers to arrange the controls on the frame.
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(m_playerWidget, wxSizerFlags(1).Expand().Border(wxALL));
    vbox->Add(m_timeline, wxSizerFlags(0).Expand().Border(wxLEFT|wxRIGHT|wxBOTTOM));

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(m_playPauseButton, wxSizerFlags(0).Border(wxLEFT|wxRIGHT|wxBOTTOM));
    hbox->Add(m_stopButton,wxSizerFlags(0).Border(wxRIGHT|wxBOTTOM));
    hbox->AddStretchSpacer();
    hbox->Add(m_volumeSlider,wxSizerFlags(0).Border(wxRIGHT|wxBOTTOM));
    vbox->Add(hbox,wxSizerFlags(0).Expand());

    bgPanel->SetSizer(vbox);
    Layout();


    // Bind event handlers for the wxWidgets controls.
    m_playPauseButton->Bind(wxEVT_BUTTON, &PlayerDlg::OnPlayPause, this);
    m_stopButton->Bind(wxEVT_BUTTON, &PlayerDlg::OnStop, this);
    m_volumeSlider->Bind(wxEVT_SLIDER,&PlayerDlg::OnVolumeChanged,this);

    BindTimeline();
    m_timeline->Bind(wxEVT_LEFT_UP, &PlayerDlg::OnTimelineClicked,this);
    m_volumeSlider->Bind(wxEVT_LEFT_UP, &PlayerDlg::OnVolumeClicked,this);

    // Bind the events that will be thrown from VLC callbacks.
    Bind(vlcEVT_POS, &PlayerDlg::OnPositionChanged, this);
    Bind(vlcEVT_END, &PlayerDlg::OnEndReached, this);


    // Set up the VLC objects.
    m_vlc = VLC::Instance(0, nullptr);
    m_player = VLC::MediaPlayer(m_vlc);

#ifdef __WXGTK__
    // On GTK+, we have to wait until the window is actually created before we
    // can tell VLC to use it for output. So wait for the window create event.
    m_playerWidget->Bind(wxEVT_CREATE, &PlayerDlg::OnRendererWinCreated, this);
#elif defined(__WXMSW__)
    m_player.setHwnd(m_playerWidget->GetHandle());
#endif

    // Get the player's event manager and register to callbacks.
    VLC::MediaPlayerEventManager& eventManager = m_player.eventManager();
    eventManager.onPositionChanged(OnPositionChanged_VLC);
    eventManager.onEndReached(OnEndReached_VLC);

    // Set this frame to a global variable so that it can be used with the
    // VLC callbacks.
    gs_handler = this;

    VLC::Media media(m_vlc, url.ToStdString(), VLC::Media::FromLocation);
    m_player.setMedia(media);
    Play();
}


void PlayerDlg::OnRendererWinCreated(wxWindowCreateEvent& event)
{
#ifdef __WXGTK__
    m_player.setXwindow(gdk_x11_window_get_xid(gtk_widget_get_window(m_playerWidget->GetHandle())));

    m_playerWidget->Unbind(wxEVT_CREATE,&PlayerDlg::OnRendererWinCreated,this);
#endif
}

void PlayerDlg::OnPositionChanged(wxThreadEvent& event)
{
    float factor = event.GetPayload<float>();
    SetTimeline(factor);
}

void PlayerDlg::OnEndReached(wxThreadEvent& event)
{
    Stop();
}

void PlayerDlg::OnPlayPause(wxCommandEvent& event)
{
    if ( m_player.isPlaying () )
    {
        Pause();
    }
    else
    {
        Play();
    }
}

void PlayerDlg::OnStop(wxCommandEvent& event)
{
    Stop();
}

void PlayerDlg::OnPositionChanged_USR(wxCommandEvent& event)
{
    m_player.setPosition((float) event.GetInt() / (float) TIMELINE_MAX);
}

void PlayerDlg::OnVolumeChanged(wxCommandEvent& event)
{
    m_player.setVolume(m_volumeSlider->GetValue());
}

void PlayerDlg::OnVolumeClicked(wxMouseEvent& event)
{
    wxSize size = m_volumeSlider->GetSize();
    float position = (float) event.GetX() / (float) size.GetWidth();
    int volume = static_cast<int>(position*VOLUME_MAX);
    m_volumeSlider->SetValue(volume);
    m_player.setVolume(volume);
    event.Skip();
}

void PlayerDlg::OnTimelineClicked(wxMouseEvent& event)
{
    wxSize size = m_timeline->GetSize();
    float position = (float) event.GetX() / (float) size.GetWidth();
    m_player.setPosition(position);
    SetTimeline(position);
    event.Skip();
}

void PlayerDlg::Play()
{;
    m_player.play();
    m_playPauseButton->SetLabel("Pause");
    m_playPauseButton->Enable(true);
    m_stopButton->Enable(true);
    m_timeline->Enable(true);
}

void PlayerDlg::Pause()
{
    m_player.pause();
    m_playPauseButton->SetLabel("Play");
}

void PlayerDlg::Stop()
{
    Pause();
#if LIBVLC_VERSION_INT >= LIBVLC_VERSION(4, 0, 0, 0)
    m_player.stopAsync();
#else
    m_player.stop();
#endif
    m_stopButton->Enable(false);
    SetTimeline(0.0);
    m_timeline->Enable(false);
}

void PlayerDlg::SetTimeline(float value) {
    if ( value < 0.0 )
    {
        value = 0.0;
    }
    if ( value > 1.0 )
    {
        value = 1.0;
    }

    UnbindTimeline();
    m_timeline->SetValue((int) (value * TIMELINE_MAX));
    BindTimeline();
}

void PlayerDlg::BindTimeline()
{
    m_timeline->Bind(wxEVT_SLIDER, &PlayerDlg::OnPositionChanged_USR, this);
}

void PlayerDlg::UnbindTimeline()
{
    m_timeline->Unbind(wxEVT_SLIDER, &PlayerDlg::OnPositionChanged_USR, this);
}