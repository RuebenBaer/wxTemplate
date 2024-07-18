#include <wx/wxprec.h>
#ifndef WX_PRECOMP
   #include <wx/wx.h>
#endif

#include "base.h"

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
   MainFrame *win = new MainFrame(_("wxWidget Template"), wxPoint (100, 100),
     wxSize(450, 340));
   SetExitOnFrameDelete(TRUE);
   win->Show(TRUE);
   SetTopWindow(win);

   return TRUE;
}

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame((wxFrame *) NULL, -1, title, pos, size)
{
	Bind(wxEVT_MENU, &MainFrame::OnQuit, this, ID_MAINWIN_QUIT);
	Bind(wxEVT_PAINT, &MainFrame::OnPaint, this);
	
	wxMenu *FileMenu = new wxMenu;
    wxMenuBar *MenuBar = new wxMenuBar;

    FileMenu->Append(ID_MAINWIN_QUIT, wxT("&Böenden\tALT-F4"));

    MenuBar->Append(FileMenu, wxT("&Datäi"));
    SetMenuBar(MenuBar);	

    CreateStatusBar(2);
    SetStatusText(_("TEMPLATE fu:r wxWidgets-Applikation"));
	
	Maximize(true);
}

MainFrame::~MainFrame()
{
	
}

void MainFrame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
    Close(TRUE);
}

void MainFrame::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	dc.SetBrush(wxBrush(dc.GetBackground()));
	dc.DrawRectangle(wxPoint(0, 0), dc.GetSize());
	dc.SetPen(wxPen(wxColor(0, 0, 0)));
	
	wxPoint t_mitte(dc.GetSize().GetWidth() / 2, dc.GetSize().GetHeight() / 2);
	
	dc.SetBrush(wxBrush(wxColor(117,35,90)));
	dc.DrawRectangle(t_mitte, wxSize(50, 50));
	dc.DrawText("Hallo Welt!", dc.GetSize().GetWidth() / 2, dc.GetSize().GetHeight() / 2);
	return;
}
