#ifndef BAJASFRAME_H
#define BAJASFRAME_H

//(*Headers(BajasFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class BajasFrame: public wxFrame
{
	public:

		BajasFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BajasFrame();

		//(*Declarations(BajasFrame)
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxStaticText* st1;
		wxTextCtrl* tc1;
		//*)

	protected:

		//(*Identifiers(BajasFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_STATICBITMAP1;
		//*)

	private:

		//(*Handlers(BajasFrame)
		void OnButton1Click(wxCommandEvent& event);
		void Ontc1Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
