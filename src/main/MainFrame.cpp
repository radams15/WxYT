//
// Created by rhys on 12/05/22.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"

extern "C" void tweak(void* window);

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style) : MainFrameBase(parent, id, title, pos, size, style){
#ifdef __WXCOCOA__
    NSWindow* win = MacGetTopLevelWindowRef();
    tweak((void*)win);
#endif
#ifdef __WXGTK3__
    tweak((void*) wxWindow::GetHandle());
#endif
#ifdef __WXQT__
    tweak((void*) GetQMainWindow());
#endif
}