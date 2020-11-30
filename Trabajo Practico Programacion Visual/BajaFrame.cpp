#include "BajaFrame.h"

//(*InternalHeaders(BajaFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(BajaFrame)
const long BajaFrame::ID_STATICTEXT1 = wxNewId();
const long BajaFrame::ID_TEXTCTRL1 = wxNewId();
const long BajaFrame::ID_STATICTEXT2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BajaFrame,wxFrame)
	//(*EventTable(BajaFrame)
	//*)
END_EVENT_TABLE()

BajaFrame::BajaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(BajaFrame)
	Create(parent, id, _("Bajas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo"), wxPoint(40,104), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(232,104), wxSize(112,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxPoint(160,280), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	//*)
}

BajaFrame::~BajaFrame()
{
	//(*Destroy(BajaFrame)
	//*)
}

