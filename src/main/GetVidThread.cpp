//
// Created by rhys on 25/05/22.
//

#include "GetVidThread.h"

#include <wx/event.h>

DEFINE_EVENT_TYPE(EVT_VID_THREAD_COMPLETED);

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

    wxCommandEvent* retEvt = new wxCommandEvent(EVT_VID_THREAD_COMPLETED);
    retEvt->SetClientData(vids);

    //wxQueueEvent(handler, retEvt);

    wxPostEvent(handler, *((wxEvent*) retEvt));

    return (void*) wxID_OK;
}
