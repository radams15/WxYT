///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/toolbar.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/scrolwin.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/mediactrl.h>
#include <wx/slider.h>
#include <wx/bmpbuttn.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnHome( wxCommandEvent& event ){ OnHome( event ); }
		void _wxFB_OnChannel( wxCommandEvent& event ){ OnChannel( event ); }
		void _wxFB_OnSearch( wxCommandEvent& event ){ OnSearch( event ); }


	protected:
		enum
		{
			ID_HOME = 1000,
			ID_CHANNEL,
			ID_SEARCH
		};

		wxToolBar* MainTB;
		wxToolBarToolBase* HomeBtn;
		wxToolBarToolBase* ChannelBtn;
		wxToolBarToolBase* SearchBtn;
		wxScrolledWindow* VidScrollWin;
		wxBoxSizer* VideoList;
		wxStatusBar* m_statusBar1;

		// Virtual event handlers, override them in your derived class
		virtual void OnHome( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChannel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSearch( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 788,448 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrameBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VideoBoxBase
///////////////////////////////////////////////////////////////////////////////
class VideoBoxBase : public wxPanel
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnPlayBtn( wxCommandEvent& event ){ OnPlayBtn( event ); }


	protected:
		enum
		{
			ID_PLAY = 1000
		};

		wxButton* PlayBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnPlayBtn( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* TitleLbl;
		wxStaticText* ChannelLbl;

		VideoBoxBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,123 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~VideoBoxBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ChannelBoxBase
///////////////////////////////////////////////////////////////////////////////
class ChannelBoxBase : public wxPanel
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnGoBtn( wxCommandEvent& event ){ OnGoBtn( event ); }


	protected:
		enum
		{
			ID_GO = 1000
		};

		wxStaticText* SubsLbl;
		wxButton* GoBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnGoBtn( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxStaticText* NameLbl;

		ChannelBoxBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,123 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~ChannelBoxBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ChannelSelectDlgBase
///////////////////////////////////////////////////////////////////////////////
class ChannelSelectDlgBase : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnCancel( wxCommandEvent& event ){ OnCancel( event ); }
		void _wxFB_OnOK( wxCommandEvent& event ){ OnOK( event ); }


	protected:
		enum
		{
			ID_CANCEL = 1000,
			ID_OK
		};

		wxChoice* ChannelChoice;
		wxButton* CancelBtn;
		wxButton* OkBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		ChannelSelectDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 560,233 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ChannelSelectDlgBase();

};

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

		PlayerDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~PlayerDlgBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class QualityDlgBase
///////////////////////////////////////////////////////////////////////////////
class QualityDlgBase : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnCancel( wxCommandEvent& event ){ OnCancel( event ); }
		void _wxFB_OnOK( wxCommandEvent& event ){ OnOK( event ); }


	protected:
		enum
		{
			ID_CANCEL = 1000,
			ID_OK
		};

		wxStaticText* QualityLbl;
		wxChoice* QualityBox;
		wxButton* CancelBtn;
		wxButton* OkBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		QualityDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 237,152 ), long style = wxDEFAULT_DIALOG_STYLE );

		~QualityDlgBase();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SearchDlgBase
///////////////////////////////////////////////////////////////////////////////
class SearchDlgBase : public wxDialog
{
	DECLARE_EVENT_TABLE()
	private:

		// Private event handlers
		void _wxFB_OnCancel( wxCommandEvent& event ){ OnCancel( event ); }
		void _wxFB_OnOK( wxCommandEvent& event ){ OnOK( event ); }


	protected:
		enum
		{
			ID_CANCEL = 1000,
			ID_OK
		};

		wxStaticText* TypeLbl;
		wxChoice* TypeBox;
		wxStaticText* QueryLbl;
		wxTextCtrl* QueryBox;
		wxButton* CancelBtn;
		wxButton* OkBtn;

		// Virtual event handlers, override them in your derived class
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		SearchDlgBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Search"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 371,271 ), long style = wxDEFAULT_DIALOG_STYLE );

		~SearchDlgBase();

};

