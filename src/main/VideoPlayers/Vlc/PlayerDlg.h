//
// Created by rhys on 5/23/22.
//

#ifndef WXYT_PLAYERDLG_H
#define WXYT_PLAYERDLG_H

#include <wx/wx.h>

#ifdef __WXGTK__
#include <gdk/gdkx.h>
#include <gtk/gtk.h>
#endif

#include <vlcpp/vlc.hpp>

#include <climits>

class PlayerDlg : public wxFrame {
private:
    // Event handlers
    void OnPositionChanged(wxThreadEvent& event);
    void OnEndReached(wxThreadEvent& event);

    void OnPlayPause(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnPositionChanged_USR(wxCommandEvent& event);
    void OnVolumeChanged(wxCommandEvent& event);
    void OnVolumeClicked(wxMouseEvent& event);
    void OnTimelineClicked(wxMouseEvent& event);
    void OnRendererWinCreated(wxWindowCreateEvent& event);

    // Helper functions.
    void Play();
    void Pause();
    void Stop();
    void SetTimeline(float value);
    void BindTimeline();
    void UnbindTimeline();

    // Video player controls.
    wxButton* m_playPauseButton;
    wxButton* m_stopButton;
    wxSlider* m_timeline;
    wxSlider* m_volumeSlider;
    wxWindow* m_playerWidget;

    // VLC objects
    VLC::Instance m_vlc;
    VLC::MediaPlayer m_player;

public:
    PlayerDlg(wxWindow *parent, wxString url);
};


#endif //WXYT_PLAYERDLG_H
