//
// Created by rhys on 20/05/22.
//

#ifndef WXYT_PLAYERDLG_H
#define WXYT_PLAYERDLG_H

#include <wx/timer.h>
#include "UI.h"

#define TICK_TIME 500

class PlayerDlg : public PlayerDlgBase {
DECLARE_EVENT_TABLE()

private:
    bool playing;
    bool loaded;

    wxTimer* timer;

    void OnLoaded(wxMediaEvent& event);
    void Tick(wxTimerEvent& event);

    wxString FormatSecs(double secs);

    enum {
        ID_TICK_TIMER
    };

    double GetLength();
    double GetElapsedTime();
    double GetElapsedPercentage();

protected:
    void OnSliderChange( wxCommandEvent& event );
    void OnPlayPause( wxCommandEvent& event );
public:
    PlayerDlg( wxWindow* parent, wxString url );

    ~PlayerDlg();
};


#endif //WXYT_PLAYERDLG_H
