///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/mediactrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class PlayerDlgBase
///////////////////////////////////////////////////////////////////////////////
class PlayerDlgBase : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnSliderChange( wxCommandEvent& event ){ OnSliderChange( event ); }
		void _wxFB_OnPlayPause( wxCommandEvent& event ){ OnPlayPause( event ); }


	protected:
		enum
		{
			ID_MEDIAPLAYER = 1000,
			ID_PROGRESS,
			ID_PLAY_PAUSE
		};

		wxSlider* ProgressSlider;
		wxStaticText* PosLbl;
		wxBitmapButton* PlayPauseBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnSliderChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlayPause( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxMediaCtrl* MediaPlayer;

		PlayerDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 660,417 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~PlayerDlgBase();

};

