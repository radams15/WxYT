//
// Created by rhys on 18/05/22.
//

#ifndef WXYT_VIDEOBOX_H
#define WXYT_VIDEOBOX_H


#include "UI.h"
#include <Config.h>

class VideoBox : public VideoBoxBase{
private:
    Video_t vid;
    wxWindow* Frame;

protected:
    void OnPlayBtn( wxCommandEvent& event );

public:
    VideoBox( wxWindow* parent, Video_t* newvid, wxWindow* Frame );

    Video_t* GetVid();
};


#endif //WXYT_VIDEOBOX_H
