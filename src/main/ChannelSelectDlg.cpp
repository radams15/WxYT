//
// Created by rhys on 19/05/22.
//

#include "ChannelSelectDlg.h"

ChannelSelectDlg::ChannelSelectDlg(wxWindow* parent, wxVector<Channel_t *> channels) : ChannelSelectDlgBase(parent){
    this->channels = channels;

    for(Channel_t* channel : channels){
        ChannelChoice->Append(channel->name);
    }
}

Channel_t* ChannelSelectDlg::Get() {
    int id = ChannelChoice->GetSelection();

    if(id == 0){
        return NULL;
    }

    return channels.at(id-1);

}

bool ChannelSelectDlg::IsAll() {
    return ChannelChoice->GetSelection() == 0;
}

void ChannelSelectDlg::OnOK(wxCommandEvent &event) {
    EndModal(wxID_OK);
}


void ChannelSelectDlg::OnCancel(wxCommandEvent &event) {
    EndModal(wxID_CANCEL);
}
