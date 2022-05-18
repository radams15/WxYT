///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "UI.h"

#include "../../data/reload.png.h"

///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE( MainFrameBase, wxFrame )
	EVT_TOOL( ID_RELOAD, MainFrameBase::_wxFB_OnReload )
END_EVENT_TABLE()

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxTB_TEXT );
	RelTool = m_toolBar1->AddTool( ID_RELOAD, wxT("Reload"), reload_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxT("Reloads the current page"), NULL );

	m_toolBar1->AddSeparator();

	m_toolBar1->Realize();

	bSizer1->Add( m_toolBar1, 1, wxEXPAND, 5 );

	ContentScrollWin = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	ContentScrollWin->SetScrollRate( 5, 5 );
	ContentSizer = new wxBoxSizer( wxVERTICAL );


	ContentScrollWin->SetSizer( ContentSizer );
	ContentScrollWin->Layout();
	ContentSizer->Fit( ContentScrollWin );
	bSizer1->Add( ContentScrollWin, 12, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );
}

MainFrameBase::~MainFrameBase()
{
}

VideoBox::VideoBox( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
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

VideoBox::~VideoBox()
{
}
