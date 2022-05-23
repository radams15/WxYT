//
// Created by rhys on 21/05/22.
//

#include "../SearchDlg.h"

void SearchDlg::OnCancel(wxCommandEvent &event) {
    wxDialog::EndModal(wxID_CANCEL);
}

void SearchDlg::OnOK(wxCommandEvent &event) {
    query = QueryBox->GetValue();

    type = (SearchType) TypeBox->GetSelection();

    wxDialog::EndModal(wxID_OK);
}

SearchDlg::SearchDlg(wxWindow *parent) : SearchDlgBase(parent){

}
