///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "WxPlayer.h"

#include "../../../../data/playpause.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( PlayerDlgBase, wxFrame )
	EVT_SLIDER( ID_PROGRESS, PlayerDlgBase::_wxFB_OnSliderChange )
	EVT_BUTTON( ID_PLAY_PAUSE, PlayerDlgBase::_wxFB_OnPlayPause )
END_EVENT_TABLE()

PlayerDlgBase::PlayerDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	MediaPlayer = new wxMediaCtrl( this, ID_MEDIAPLAYER, wxT(""), wxDefaultPosition, wxDefaultSize);
	MediaPlayer->SetPlaybackRate(1);
	MediaPlayer->SetVolume(1);

	MediaPlayer->Stop();
	bSizer6->Add( MediaPlayer, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	ProgressSlider = new wxSlider( this, ID_PROGRESS, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( ProgressSlider, 7, wxALL, 5 );

	PosLbl = new wxStaticText( this, wxID_ANY, wxT("000:00:00 / 000:00:00"), wxDefaultPosition, wxDefaultSize, 0 );
	PosLbl->Wrap( -1 );
	bSizer7->Add( PosLbl, 2, wxALL, 5 );

	PlayPauseBtn = new wxBitmapButton( this, ID_PLAY_PAUSE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );

	PlayPauseBtn->SetBitmap( playpause_png_to_wx_bitmap() );
	bSizer7->Add( PlayPauseBtn, 0, wxALL, 5 );


	bSizer6->Add( bSizer7, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );
}

PlayerDlgBase::~PlayerDlgBase()
{
}
