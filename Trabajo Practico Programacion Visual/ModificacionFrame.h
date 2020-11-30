#ifndef MODIFICACIONFRAME_H
#define MODIFICACIONFRAME_H

//(*Headers(ModificacionFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ModificacionFrame: public wxFrame
{
	public:

		ModificacionFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ModificacionFrame();

		//(*Declarations(ModificacionFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* st1;
		wxTextCtrl* tc1;
		wxTextCtrl* tc2;
		wxTextCtrl* tc3;
		wxTextCtrl* tc4;
		//*)

	protected:

		//(*Identifiers(ModificacionFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICBITMAP1;
		//*)

	private:

		//(*Handlers(ModificacionFrame)
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
