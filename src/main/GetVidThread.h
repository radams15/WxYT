//
// Created by rhys on 25/05/22.
//

#ifndef WXYT_GETVIDTHREAD_H
#define WXYT_GETVIDTHREAD_H

#include <wx/wx.h>
#include "Channel.h"

wxDECLARE_EVENT(wxEVT_VID_THREAD_COMPLETED, wxCommandEvent);

class GetVidThread : public wxThread {
private:
    wxFrame* handler;
    Channel_t* channel;
    Config_t* conf;
public:
    GetVidThread(wxFrame* parent, Config_t* conf, Channel_t* channel);

    void* Entry();
};


#endif //WXYT_GETVIDTHREAD_H
