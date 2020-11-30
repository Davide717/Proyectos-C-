#ifndef BAJAFRAME_H
#define BAJAFRAME_H

//(*Headers(BajaFrame)
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class BajaFrame: public wxFrame
{
	public:

		BajaFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BajaFrame();

		//(*Declarations(BajaFrame)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(BajaFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		//*)

	private:

		//(*Handlers(BajaFrame)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
