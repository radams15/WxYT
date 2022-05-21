//
// Created by rhys on 21/05/22.
//

#include "ChannelBox.h"
#include "MainFrame.h"

void ChannelBox::OnGoBtn(wxCommandEvent &event) {
    ((MainFrame*)Frame)->LoadChannel(&channel);
}

ChannelBox::ChannelBox(Config_t* conf, wxWindow *parent, Channel_t *newchannel, wxWindow *Frame) : ChannelBoxBase(parent){
    this->channel = *newchannel;
    this->Frame = Frame;
    this->conf = conf;

    NameLbl->SetLabel(wxString::FromUTF8(channel.name));
    SubsLbl->SetLabel(wxString::Format(wxT("%ld"), channel.sub_count));

    if(IsSubscribed()){
        SubBtn->SetLabel("Unsubscribe");
    }
}

Channel_t* ChannelBox::GetChannel() {
    return &channel;
}

void ChannelBox::OnSubBtn(wxCommandEvent &event) {
    if(IsSubscribed()) {
        //TODO remove subscriber
        SubBtn->SetLabel("Subscribe");
    } else {
        config_subs_add(conf, &channel);

        SubBtn->SetLabel("Unsubscribe");
    }
}

bool ChannelBox::IsSubscribed() {
    for(int i=0 ; i<conf->subs->length ; i++){
        if(strcmp(channels_get(conf->subs, i)->name, channel.name) == 0){
            return true;
        }
    }

    return false;
}
