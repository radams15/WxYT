//
// Created by rhys on 20/05/22.
//

#include <iostream>

#include "PlayerDlg.h"

BEGIN_EVENT_TABLE( PlayerDlg, PlayerDlgBase )
                EVT_MEDIA_LOADED( ID_MEDIAPLAYER, PlayerDlg::OnLoaded )
                EVT_TIMER( ID_TICK_TIMER, PlayerDlg::Tick)
END_EVENT_TABLE()

PlayerDlg::PlayerDlg(wxWindow *parent, wxString url) : PlayerDlgBase(parent){
    playing = false;
    loaded = false;

    wxURI viduri(url);
    bool success = MediaPlayer->Load(viduri);

    std::cout << "Media loading: " << (success? "Success!" : "Fail!") << std::endl;

    timer = new wxTimer(this, ID_TICK_TIMER);
}

void PlayerDlg::OnSliderChange(wxCommandEvent &event) {
    int val = ProgressSlider->GetValue();

    float mult = (float)val/100.0f;

    long pos = mult*(GetLength()*1000);

    MediaPlayer->Seek(pos);
}

void PlayerDlg::OnPlayPause(wxCommandEvent &event) {
    if(playing){
        MediaPlayer->Pause();
        playing = false;
    }else if(loaded){
        MediaPlayer->Play();
        playing = true;
    }
}

void PlayerDlg::OnLoaded(wxMediaEvent &event) {
    loaded = true;
    PlayPauseBtn->Enable();

    timer->Start(TICK_TIME);
}

void PlayerDlg::Tick(wxTimerEvent &event) {
    if(loaded and playing) {
        ProgressSlider->SetValue((int) GetElapsedPercentage());
        PosLbl->SetLabel(wxString::Format(wxT("%s / %s"), FormatSecs(GetElapsedTime()), FormatSecs(GetLength())));
    }
}

double PlayerDlg::GetLength() {
    return (double)MediaPlayer->Length()/1000.0f;
}

double PlayerDlg::GetElapsedTime() {
    long elapsed = MediaPlayer->Tell();

    return (double)elapsed/1000.0f;
}

double PlayerDlg::GetElapsedPercentage() {
    return (GetElapsedTime()/GetLength())*100;
}

wxString PlayerDlg::FormatSecs(double secs) {
    unsigned long hours = (int) secs / (60*60);
    unsigned long mins = (int) secs / 60;
    unsigned long remainingSecs = (int) secs % 60;

    return wxString::Format(wxT("%03lu:%02lu:%02lu"), hours,mins, remainingSecs);
}

PlayerDlg::~PlayerDlg() {
    playing = false;
    MediaPlayer->Stop();
    timer->Stop();
}
