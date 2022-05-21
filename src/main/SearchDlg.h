//
// Created by rhys on 21/05/22.
//

#ifndef WXYT_SEARCHDLG_H
#define WXYT_SEARCHDLG_H

#include "UI.h"

class SearchDlg : public SearchDlgBase{
public:
    enum SearchType{
        TYPE_VIDEO,
        TYPE_CHANNEL
    };

private:
    SearchType type;
    wxString query;

protected:
    void OnCancel( wxCommandEvent& event );
    void OnOK( wxCommandEvent& event );

public:

    SearchDlg(wxWindow* parent);

    inline SearchType GetType(){ return type; }
    inline wxString GetQuery(){ return query; }
};


#endif //WXYT_SEARCHDLG_H
