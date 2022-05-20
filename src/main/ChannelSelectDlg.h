//
// Created by rhys on 19/05/22.
//

#ifndef WXYT_CHANNELSELECTDLG_H
#define WXYT_CHANNELSELECTDLG_H


#include "UI.h"
#include <Channel.h>

class ChannelSelectDlg : public ChannelSelectDlgBase{
private:

    wxVector<Channel_t*> channels;


protected:
    void OnCancel( wxCommandEvent& event );
    void OnOK( wxCommandEvent& event );

public:

    ChannelSelectDlg(wxWindow* parent, wxVector<Channel_t*> channels);

    Channel_t* Get();

    bool IsAll();
};


#endif //WXYT_CHANNELSELECTDLG_H
