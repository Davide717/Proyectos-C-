/***************************************************************
 * Name:      Trabajo_Practico_Programacion_VisualMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-11-01
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Trabajo_Practico_Programacion_VisualMain.h"
#include <wx/msgdlg.h>
#include "AltaFrame.h"
#include "BajasFrame.h"
#include "ModificacionFrame.h"      // incluimos las ventanas
#include "CompraFrame.h"
#include "VentaFrame.h"

//(*InternalHeaders(Trabajo_Practico_Programacion_VisualFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Trabajo_Practico_Programacion_VisualFrame)
const long Trabajo_Practico_Programacion_VisualFrame::ID_STATICTEXT1 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_STATICTEXT2 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_STATICBITMAP1 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::idMenuQuit = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM1 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM2 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM3 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM4 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM5 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM8 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM7 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_MENUITEM6 = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::idMenuAbout = wxNewId();
const long Trabajo_Practico_Programacion_VisualFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Trabajo_Practico_Programacion_VisualFrame,wxFrame)
    //(*EventTable(Trabajo_Practico_Programacion_VisualFrame)
    //*)
END_EVENT_TABLE()

Trabajo_Practico_Programacion_VisualFrame::Trabajo_Practico_Programacion_VisualFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Trabajo_Practico_Programacion_VisualFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Control de stock"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    Hide();
    SetBackgroundColour(wxColour(80,216,226));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Control de productos"), wxPoint(40,96), wxSize(104,16), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxColour(69,51,227));
    wxFont StaticText1Font(26,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Gadugi"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Bienvenidos"), wxPoint(104,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText2->SetForegroundColour(wxColour(152,237,112));
    wxFont StaticText2Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\principal.jpg")).Rescale(wxSize(333,216).GetWidth(),wxSize(333,216).GetHeight())), wxPoint(32,168), wxSize(333,216), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de la aplicacion"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Archivo"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("Altas"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Bajas"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("Modificaciones"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem6 = new wxMenuItem(Menu3, ID_MENUITEM4, _("Comprar"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu3, ID_MENUITEM5, _("Vender"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem7);
    MenuItem10 = new wxMenuItem(Menu3, ID_MENUITEM8, _("Eliminar registros"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem10);
    MenuBar1->Append(Menu3, _("Operaciones"));
    Menu4 = new wxMenu();
    MenuItem9 = new wxMenuItem(Menu4, ID_MENUITEM7, _("Listado de productos"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem9);
    MenuItem8 = new wxMenuItem(Menu4, ID_MENUITEM6, _("Listado de productos a reponer"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem8);
    MenuBar1->Append(Menu4, _("Listados"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de\tF1"), _("Muestra informacion acerca de la aplicacion"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Ayuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnQuit);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuAltaSelected);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuBajaSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuModificacionSelected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuComprarSelected);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuVenderSelected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuEliminarRegistrosSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuListadoSelected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnMenuListadoaReponerSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Trabajo_Practico_Programacion_VisualFrame::OnAbout);
    //*)
}

Trabajo_Practico_Programacion_VisualFrame::~Trabajo_Practico_Programacion_VisualFrame()
{
    //(*Destroy(Trabajo_Practico_Programacion_VisualFrame)
    //*)
}

#include <fstream>
#include "Producto.h"
#include <iomanip>
using namespace std;

void Trabajo_Practico_Programacion_VisualFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Trabajo_Practico_Programacion_VisualFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "En esta aplicacion podra operar con productos";
    wxMessageBox(msg, _("Bienvenido a..."));
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuAltaSelected(wxCommandEvent& event)
{
    AltaFrame *frm= new AltaFrame(this);   // nos lleva a la ventana de altas
    frm->Show();
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuBajaSelected(wxCommandEvent& event)
{
    BajasFrame *frm= new BajasFrame(this);    // nos lleva a la ventana de bajas
    frm->Show();
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuModificacionSelected(wxCommandEvent& event)
{
    ModificacionFrame *frm= new ModificacionFrame(this);  // nos lleva a la ventana de modificacion
    frm->Show();

}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuListadoSelected(wxCommandEvent& event)
{
    wxString msg = "Listado de Productos";
    wxMessageBox(msg, _("Procesando..."));
    fstream arch;
    arch.open("productos.dat",ios::app|ios::binary);      // primero como app por que es un truco para que no diga que el archivo no exista al querer abrir, tambien sirve para que un archivo ya creado poder modificarlo agregando siempre al final
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    arch.close();
    arch.open("productos.dat",ios::in|ios::out |ios::binary);        // Abre el archivo binario
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }

    ofstream archt;  //archivo texto
    Producto reg;
    archt.open("ProductosListado.txt",ios::out);  //solo para grabar
    if(!archt)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
    }
    archt<<left<<setw(10)<<"Codigo/"<<setw(25)<<"Descripcion/"<<setw(25)<<"Existencias/"<<setw(19)<<"Stock minimo/"<<setw(19)<<"Stock maximo/"<<setw(19)<<"Precio"<<endl; // listamos todos los atributos

    arch.seekg(0);  // nos ubicamos arriba de todo
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));  //leemos   igual que el write pero sin const char*
    while(!arch.eof())
    {
        if(reg.getBorrado()==0)
        {
            archt<<left<<setw(10)<<reg.getcodigo()<<setw(25)<<reg.getdescripcion()<<setw(25)<<reg.getexistencias()<<setw(19)<<reg.getstockmin()<<setw(19)<<reg.getstockmax()<<setw(19)<<reg.getprecio()<<endl;  //obtenemos los atributos para guardarlos

        }
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));  //leemos de vuelta
    }

    archt.close();
    arch.close();
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuListadoaReponerSelected(wxCommandEvent& event)
{
    wxString msg = "Listado de Productos a reponer";
    wxMessageBox(msg, _("Procesando..."));
    fstream arch;
    ofstream archt;
    Producto reg;
    int cant=0;
    float importe=0;
    arch.open("productos.dat",ios::app|ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    arch.close();
    arch.open("productos.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }


    archt.open("ProductoReponer.txt",ios::out);
    if(!archt)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));

    }
    archt<<left<<setw(10)<<"Codigo/"<<setw(20)<<"Descripcion/"<<setw(10)<<"Reponer/"<<setw(10)<<"A pagar/"<<endl;

    arch.clear();
    arch.seekg(0,ios::beg);
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    while(!arch.eof())
    {
        if(reg.getexistencias()<=reg.getstockmin())
        {
            cant=(reg.getstockmax())-(reg.getexistencias());  //cantidad e importe para hacer el calculo
            importe=cant*(reg.getprecio());
            archt<<left<<setw(10)<<reg.getcodigo()<<setw(20)<<reg.getdescripcion()<<setw(10)<<cant<<setw(10)<<setprecision(2)<<fixed<<importe<<endl;

        }
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
    archt.close();
    arch.close();
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuEliminarRegistrosSelected(wxCommandEvent& event)
{
    wxString msg = "Eliminando registros";
    wxMessageBox(msg, _("Procesando..."));
    fstream temp,arch;
    Producto reg;

    temp.open("temporal.dat",ios::out |ios::binary);
    if(!temp)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    arch.open("productos.dat",ios::app|ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
    arch.close();
    arch.open("productos.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }

    arch.clear();
    arch.seekg(0,ios::beg);
    arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    while(!arch.eof())
    {
        if(reg.getBorrado()==0)
        {
            temp.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
        }
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
    }
    arch.close();
    temp.close();
    system("del productos.dat");
    system("rename temporal.dat productos.dat");
    arch.open("productos.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        msg = "Error de apertura de archivo";
        wxMessageBox(msg, _("ERROR!!!"));
        Close();
    }
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuComprarSelected(wxCommandEvent& event)
{
    CompraFrame *frm= new CompraFrame(this);  // ventana de compra
    frm->Show();
}

void Trabajo_Practico_Programacion_VisualFrame::OnMenuVenderSelected(wxCommandEvent& event)
{
    VentaFrame *frm= new VentaFrame(this);  // ventana de venta
    frm->Show();
}
