///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UI.h"

#include "../../data/channel.png.h"
#include "../../data/home.png.h"
#include "../../data/reload.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_TOOL( ID_HOME, MainFrameBase::_wxFB_OnHome )
	EVT_TOOL( ID_CHANNEL, MainFrameBase::_wxFB_OnChannel )
	EVT_TOOL( ID_RELOAD, MainFrameBase::_wxFB_OnReload )
END_EVENT_TABLE()

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	MainTB = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT );
	HomeBtn = MainTB->AddTool( ID_HOME, wxT("Home"), home_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Goes home to all subscriptions"), NULL );

	ChannelBtn = MainTB->AddTool( ID_CHANNEL, wxT("Channel"), channel_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Selects the channel to view"), NULL );

	MainTB->AddSeparator();

	RelTool = MainTB->AddTool( ID_RELOAD, wxT("Reload"), reload_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Reloads the current page"), NULL );

	MainTB->Realize();

	bSizer1->Add( MainTB, 1, wxEXPAND, 5 );

	VidScrollWin = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	VidScrollWin->SetScrollRate( 5, 5 );
	VideoList = new wxBoxSizer( wxVERTICAL );


	VidScrollWin->SetSizer( VideoList );
	VidScrollWin->Layout();
	VideoList->Fit( VidScrollWin );
	bSizer1->Add( VidScrollWin, 12, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

BEGIN_EVENT_TABLE( VideoBoxBase, wxPanel )
	EVT_BUTTON( wxID_ANY, VideoBoxBase::_wxFB_OnPlayBtn )
END_EVENT_TABLE()

VideoBoxBase::VideoBoxBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	TitleLbl = new wxStaticText( this, wxID_ANY, wxT("Title"), wxDefaultPosition, wxDefaultSize, 0 );
	TitleLbl->Wrap( -1 );
	bSizer4->Add( TitleLbl, 0, wxALL, 5 );

	ChannelLbl = new wxStaticText( this, wxID_ANY, wxT("Channel"), wxDefaultPosition, wxDefaultSize, 0 );
	ChannelLbl->Wrap( -1 );
	bSizer4->Add( ChannelLbl, 0, wxALL, 5 );

	PlayBtn = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( PlayBtn, 0, wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
}

VideoBoxBase::~VideoBoxBase()
{
}

BEGIN_EVENT_TABLE( ChannelSelectDlgBase, wxDialog )
	EVT_BUTTON( ID_CANCEL, ChannelSelectDlgBase::_wxFB_OnCancel )
	EVT_BUTTON( ID_OK, ChannelSelectDlgBase::_wxFB_OnOK )
END_EVENT_TABLE()

ChannelSelectDlgBase::ChannelSelectDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxString ChannelChoiceChoices[] = { wxT("All") };
	int ChannelChoiceNChoices = sizeof( ChannelChoiceChoices ) / sizeof( wxString );
	ChannelChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ChannelChoiceNChoices, ChannelChoiceChoices, 0 );
	ChannelChoice->SetSelection( 0 );
	bSizer5->Add( ChannelChoice, 5, wxALL, 5 );

	CancelBtn = new wxButton( this, ID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( CancelBtn, 1, wxALL, 5 );

	OkBtn = new wxButton( this, ID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( OkBtn, 1, wxALL, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );
}

ChannelSelectDlgBase::~ChannelSelectDlgBase()
{
}

PlayerDlgBase::PlayerDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	MediaPlayer = new wxMediaCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);
	MediaPlayer->SetPlaybackRate(1);
	MediaPlayer->SetVolume(1);

	MediaPlayer->Stop();
	bSizer6->Add( MediaPlayer, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();

	this->Centre( wxBOTH );
}

PlayerDlgBase::~PlayerDlgBase()
{
}
