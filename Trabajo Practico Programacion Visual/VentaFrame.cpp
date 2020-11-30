#include "VentaFrame.h"

//(*InternalHeaders(VentaFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(VentaFrame)
const long VentaFrame::ID_STATICTEXT1 = wxNewId();
const long VentaFrame::ID_TEXTCTRL1 = wxNewId();
const long VentaFrame::ID_STATICTEXT2 = wxNewId();
const long VentaFrame::ID_TEXTCTRL2 = wxNewId();
const long VentaFrame::ID_BUTTON1 = wxNewId();
const long VentaFrame::ID_BUTTON2 = wxNewId();
const long VentaFrame::ID_STATICTEXT3 = wxNewId();
const long VentaFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(VentaFrame,wxFrame)
    //(*EventTable(VentaFrame)
    //*)
END_EVENT_TABLE()

VentaFrame::VentaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(VentaFrame)
    Create(parent, id, _("Ventas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(505,498));
    Move(wxDefaultPosition);
    SetBackgroundColour(wxColour(218,12,12));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo:"), wxPoint(32,88), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(200,88), wxSize(240,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese cantidad a vender:"), wxPoint(32,160), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(312,160), wxSize(136,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(112,448), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxColour(128,255,255));
    Button2 = new wxButton(this, ID_BUTTON2, _("Nuevo"), wxPoint(256,448), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxColour(128,255,255));
    st1 = new wxStaticText(this, ID_STATICTEXT3, wxEmptyString, wxPoint(40,208), wxSize(48,27), 0, _T("ID_STATICTEXT3"));
    wxFont st1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    st1->SetFont(st1Font);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\Vender-Stock.jpg")).Rescale(wxSize(240,176).GetWidth(),wxSize(240,176).GetHeight())), wxPoint(112,256), wxSize(240,176), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VentaFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&VentaFrame::OnButton2Click);
    //*)
}

VentaFrame::~VentaFrame()
{
    //(*Destroy(VentaFrame)
    //*)
}

#include <fstream>
#include "Producto.h"
#include <wx/string.h>

void VentaFrame::OnButton1Click(wxCommandEvent& event)
{
    Producto reg,prod;
    fstream arch;
    int c,cant,e;

    arch.open("productos.dat",ios::app|ios::binary);
    if(!arch)
    {
        st1->SetLabel("Error de apertura de archivo");
        Close();
    }
    arch.close();
    arch.open("productos.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        st1->SetLabel("Error de apertura de archivo");
        Close();
    }

    wxString str = tc1->GetValue();
    c=wxAtoi(str);
    str=tc2->GetValue();
    cant=wxAtoi(str);
    prod.setcodigo(c);
    prod.buscar(arch);
    if(arch.eof())
        st1->SetLabel("Venta inexistente");
    else
    {
        arch.clear();
        arch.seekg(arch.tellg()-sizeof(Producto),ios::beg);
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
        if(reg.getBorrado()==0)
        {
            if(cant<=reg.getexistencias())
            {
                e=reg.getexistencias();
                e=e-cant;
                reg.setexistencias(e);

                arch.seekp(arch.tellg()-sizeof(Producto),ios::beg);
                arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
                st1->SetLabel("Venta exitosa");
            }
            else
                st1->SetLabel("La venta supera las existencias");

        }
        else
            st1->SetLabel("Producto dado de baja");


    }

}

void VentaFrame::OnButton2Click(wxCommandEvent& event)
{
    tc1->Clear();
    tc2->Clear();
    st1->SetLabel("");
}
