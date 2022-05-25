//
// Created by rhys on 25/05/22.
//

#include "GetVidThread.h"

wxDEFINE_EVENT(wxEVT_VID_THREAD_COMPLETED, wxCommandEvent);

GetVidThread::GetVidThread(wxFrame* parent, Config_t* conf, Channel_t *channel) : wxThread(wxTHREAD_DETACHED){
    this->conf = conf;
    this->channel = channel;
    this->handler = parent;
}

void* GetVidThread::Entry() {
    List_t* vids;

    if (channel == NULL) {
        vids = config_get_vids_list(conf);
    } else {
        vids = channel_get_vids_list(channel, conf);
    }

    wxCommandEvent* retEvt = new wxCommandEvent(wxEVT_VID_THREAD_COMPLETED);
    retEvt->SetClientData(vids);

    wxQueueEvent(handler, retEvt);

    return (void*) wxID_OK;
}
