#ifndef VENTAFRAME_H
#define VENTAFRAME_H

//(*Headers(VentaFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class VentaFrame: public wxFrame
{
	public:

		VentaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~VentaFrame();

		//(*Declarations(VentaFrame)
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

		//(*Identifiers(VentaFrame)
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

		//(*Handlers(VentaFrame)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
