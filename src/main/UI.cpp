///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UI.h"

#include "../../data/channel.png.h"
#include "../../data/home.png.h"
#include "../../data/search.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_TOOL( ID_HOME, MainFrameBase::_wxFB_OnHome )
	EVT_TOOL( ID_CHANNEL, MainFrameBase::_wxFB_OnChannel )
	EVT_TOOL( ID_SEARCH, MainFrameBase::_wxFB_OnSearch )
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

	SearchBtn = MainTB->AddTool( ID_SEARCH, wxT("Search"), search_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Search for channels or videos"), NULL );

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
	m_statusBar1 = this->CreateStatusBar( 1, 0, wxID_ANY );

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

BEGIN_EVENT_TABLE( VideoBoxBase, wxPanel )
	EVT_BUTTON( ID_PLAY, VideoBoxBase::_wxFB_OnPlayBtn )
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

	PlayBtn = new wxButton( this, ID_PLAY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( PlayBtn, 0, wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
}

VideoBoxBase::~VideoBoxBase()
{
}

BEGIN_EVENT_TABLE( ChannelBoxBase, wxPanel )
	EVT_BUTTON( ID_SUB, ChannelBoxBase::_wxFB_OnSubBtn )
	EVT_BUTTON( ID_GO, ChannelBoxBase::_wxFB_OnGoBtn )
END_EVENT_TABLE()

ChannelBoxBase::ChannelBoxBase( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	NameLbl = new wxStaticText( this, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	NameLbl->Wrap( -1 );
	bSizer4->Add( NameLbl, 0, wxALL, 5 );

	SubsLbl = new wxStaticText( this, wxID_ANY, wxT("Subs"), wxDefaultPosition, wxDefaultSize, 0 );
	SubsLbl->Wrap( -1 );
	bSizer4->Add( SubsLbl, 0, wxALL, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	SubBtn = new wxButton( this, ID_SUB, wxT("Subscribe"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( SubBtn, 0, wxALL, 5 );


	bSizer20->Add( 0, 0, 1, wxEXPAND, 5 );

	GoBtn = new wxButton( this, ID_GO, wxT("Go"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( GoBtn, 0, wxALL, 5 );


	bSizer4->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
}

ChannelBoxBase::~ChannelBoxBase()
{
}

BEGIN_EVENT_TABLE( QualityDlgBase, wxDialog )
	EVT_BUTTON( ID_CANCEL, QualityDlgBase::_wxFB_OnCancel )
	EVT_BUTTON( ID_OK, QualityDlgBase::_wxFB_OnOK )
END_EVENT_TABLE()

QualityDlgBase::QualityDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	QualityLbl = new wxStaticText( this, wxID_ANY, wxT("Quality"), wxDefaultPosition, wxDefaultSize, 0 );
	QualityLbl->Wrap( -1 );
	bSizer7->Add( QualityLbl, 0, wxALL, 5 );

	wxString QualityBoxChoices[] = { wxT("144"), wxT("340"), wxT("720"), wxEmptyString };
	int QualityBoxNChoices = sizeof( QualityBoxChoices ) / sizeof( wxString );
	QualityBox = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, QualityBoxNChoices, QualityBoxChoices, 0 );
	QualityBox->SetSelection( 0 );
	bSizer7->Add( QualityBox, 0, wxALL, 5 );


	bSizer8->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );


	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );

	CancelBtn = new wxButton( this, ID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( CancelBtn, 0, wxALL, 5 );

	OkBtn = new wxButton( this, ID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( OkBtn, 0, wxALL, 5 );


	bSizer8->Add( bSizer14, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );
}

QualityDlgBase::~QualityDlgBase()
{
}

BEGIN_EVENT_TABLE( SearchDlgBase, wxDialog )
	EVT_BUTTON( ID_CANCEL, SearchDlgBase::_wxFB_OnCancel )
	EVT_BUTTON( ID_OK, SearchDlgBase::_wxFB_OnOK )
END_EVENT_TABLE()

SearchDlgBase::SearchDlgBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	TypeLbl = new wxStaticText( this, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	TypeLbl->Wrap( -1 );
	bSizer10->Add( TypeLbl, 0, wxALL, 5 );

	wxString TypeBoxChoices[] = { wxT("Video"), wxT("Channel") };
	int TypeBoxNChoices = sizeof( TypeBoxChoices ) / sizeof( wxString );
	TypeBox = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, TypeBoxNChoices, TypeBoxChoices, 0 );
	TypeBox->SetSelection( 0 );
	bSizer10->Add( TypeBox, 4, wxALL, 5 );


	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );

	QueryLbl = new wxStaticText( this, wxID_ANY, wxT("Query"), wxDefaultPosition, wxDefaultSize, 0 );
	QueryLbl->Wrap( -1 );
	bSizer101->Add( QueryLbl, 0, wxALL, 5 );

	QueryBox = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( QueryBox, 4, wxALL, 5 );


	bSizer9->Add( bSizer101, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );


	bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );

	CancelBtn = new wxButton( this, ID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( CancelBtn, 0, wxALL, 5 );

	OkBtn = new wxButton( this, ID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( OkBtn, 0, wxALL, 5 );


	bSizer9->Add( bSizer14, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );
}

SearchDlgBase::~SearchDlgBase()
{
}
