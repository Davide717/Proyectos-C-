/***************************************************************
 * Name:      Trabajo_Practico_Programacion_VisualMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-11-01
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef TRABAJO_PRACTICO_PROGRAMACION_VISUALMAIN_H
#define TRABAJO_PRACTICO_PROGRAMACION_VISUALMAIN_H

//(*Headers(Trabajo_Practico_Programacion_VisualFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class Trabajo_Practico_Programacion_VisualFrame: public wxFrame
{
    public:

        Trabajo_Practico_Programacion_VisualFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Trabajo_Practico_Programacion_VisualFrame();

    private:

        //(*Handlers(Trabajo_Practico_Programacion_VisualFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuAltaSelected(wxCommandEvent& event);
        void OnMenuBajasSelected(wxCommandEvent& event);
        void OnMenuBajaSelected(wxCommandEvent& event);
        void OnMenuModificacionSelected(wxCommandEvent& event);
        void OnMenuListadoSelected(wxCommandEvent& event);
        void OnMenuListadoaReponerSelected(wxCommandEvent& event);
        void OnMenuEliminarRegistrosSelected(wxCommandEvent& event);
        void OnMenuComprarSelected(wxCommandEvent& event);
        void OnMenuVenderSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(Trabajo_Practico_Programacion_VisualFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICBITMAP1;
        static const long idMenuQuit;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM6;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Trabajo_Practico_Programacion_VisualFrame)
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem9;
        wxStaticBitmap* StaticBitmap1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TRABAJO_PRACTICO_PROGRAMACION_VISUALMAIN_H
