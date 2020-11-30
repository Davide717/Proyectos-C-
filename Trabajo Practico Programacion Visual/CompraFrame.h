#ifndef COMPRAFRAME_H
#define COMPRAFRAME_H

//(*Headers(CompraFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class CompraFrame: public wxFrame
{
	public:

		CompraFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~CompraFrame();

		//(*Declarations(CompraFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* st1;
		wxTextCtrl* tc1;
		wxTextCtrl* tc2;
		//*)

	protected:

		//(*Identifiers(CompraFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICBITMAP1;
		//*)

	private:

		//(*Handlers(CompraFrame)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
