/***************************************************************
 * Name:      Trabajo_Practico_Programacion_VisualApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-11-01
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Trabajo_Practico_Programacion_VisualApp.h"

//(*AppHeaders
#include "Trabajo_Practico_Programacion_VisualMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Trabajo_Practico_Programacion_VisualApp);

bool Trabajo_Practico_Programacion_VisualApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Trabajo_Practico_Programacion_VisualFrame* Frame = new Trabajo_Practico_Programacion_VisualFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
