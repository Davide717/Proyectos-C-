#ifndef ALTAFRAME_H
#define ALTAFRAME_H

//(*Headers(AltaFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class AltaFrame: public wxFrame
{
	public:

		AltaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AltaFrame();

		//(*Declarations(AltaFrame)
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* st1;
		wxTextCtrl* tc1;
		wxTextCtrl* tc2;
		wxTextCtrl* tc3;
		wxTextCtrl* tc4;
		wxTextCtrl* tc5;
		wxTextCtrl* tc6;
		//*)

	protected:

		//(*Identifiers(AltaFrame)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICBITMAP1;
		//*)

	private:

		//(*Handlers(AltaFrame)
		void OnTextCtrl4Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void Ontc1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
