//
// Created by rhys on 21/05/22.
//

#include "ChannelBox.h"
#include "MainFrame.h"

void ChannelBox::OnGoBtn(wxCommandEvent &event) {
    ((MainFrame*)Frame)->LoadChannel(&channel);
}

ChannelBox::ChannelBox(wxWindow *parent, Channel_t *newchannel, wxWindow *Frame) : ChannelBoxBase(parent){
    this->channel = *newchannel;
    this->Frame = Frame;

    NameLbl->SetLabel(wxString::FromUTF8(channel.name));
    SubsLbl->SetLabel(wxString::Format(wxT("%ld"), channel.sub_count));
}

Channel_t* ChannelBox::GetChannel() {
    return &channel;
}
