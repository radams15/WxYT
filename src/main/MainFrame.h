//
// Created by rhys on 12/05/22.
//

#ifndef GEMCLIENT_MAINFRAME_H
#define GEMCLIENT_MAINFRAME_H


#include <stack>
#include "UI.h"

class MainFrame : public MainFrameBase {
private:


protected:


public:
    MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("YtClient"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 790,549 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
};


#endif //GEMCLIENT_MAINFRAME_H
