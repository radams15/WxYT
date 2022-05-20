//
// Created by rhys on 18/05/22.
//

#include "MainFrame.h"

#include "VideoBox.h"

VideoBox::VideoBox(wxWindow *parent, Video_t* newvid, wxWindow* Frame) : VideoBoxBase(parent){
    vid = *newvid;
    this->Frame = Frame;

    TitleLbl->SetLabel(wxString::FromUTF8(vid.title));
    ChannelLbl->SetLabel(wxString::FromUTF8(vid.channel_name));
}

void VideoBox::OnPlayBtn(wxCommandEvent &event) {
    ((MainFrame*)Frame)->PlayVideo(&vid);
}

Video_t* VideoBox::GetVid() {
    return &vid;
}
