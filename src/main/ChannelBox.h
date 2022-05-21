//
// Created by rhys on 21/05/22.
//

#ifndef WXYT_CHANNELBOX_H
#define WXYT_CHANNELBOX_H

#include "UI.h"
#include "Channel.h"

class ChannelBox : public ChannelBoxBase {
private:
    Channel_t channel;
    wxWindow* Frame;
    Config_t* conf;

    bool IsSubscribed();

protected:
    void OnGoBtn( wxCommandEvent& event );
    void OnSubBtn( wxCommandEvent& event );

public:
    ChannelBox( Config_t* conf, wxWindow* parent, Channel_t* newchannel, wxWindow* Frame );

    Channel_t* GetChannel();
};


#endif //WXYT_CHANNELBOX_H
