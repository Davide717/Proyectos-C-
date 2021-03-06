#include "CompraFrame.h"

//(*InternalHeaders(CompraFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(CompraFrame)
const long CompraFrame::ID_STATICTEXT1 = wxNewId();
const long CompraFrame::ID_TEXTCTRL1 = wxNewId();
const long CompraFrame::ID_STATICTEXT2 = wxNewId();
const long CompraFrame::ID_TEXTCTRL2 = wxNewId();
const long CompraFrame::ID_BUTTON1 = wxNewId();
const long CompraFrame::ID_BUTTON2 = wxNewId();
const long CompraFrame::ID_STATICTEXT3 = wxNewId();
const long CompraFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CompraFrame,wxFrame)
    //(*EventTable(CompraFrame)
    //*)
END_EVENT_TABLE()

CompraFrame::CompraFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(CompraFrame)
    Create(parent, id, _("Compras"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(547,602));
    Move(wxDefaultPosition);
    SetBackgroundColour(wxColour(26,108,191));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo:"), wxPoint(24,88), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(192,88), wxSize(288,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese cantidad a comprar:"), wxPoint(24,168), wxSize(248,24), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(320,168), wxSize(144,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Button1 = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(136,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetBackgroundColour(wxColour(128,255,255));
    Button2 = new wxButton(this, ID_BUTTON2, _("Nuevo"), wxPoint(272,504), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetBackgroundColour(wxColour(128,255,255));
    st1 = new wxStaticText(this, ID_STATICTEXT3, wxEmptyString, wxPoint(40,224), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont st1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    st1->SetFont(st1Font);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\Comprar-stock.jpg")).Rescale(wxSize(256,208).GetWidth(),wxSize(256,208).GetHeight())), wxPoint(128,272), wxSize(256,208), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CompraFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CompraFrame::OnButton2Click);
    //*)
}

CompraFrame::~CompraFrame()
{
    //(*Destroy(CompraFrame)
    //*)
}

#include <fstream>
#include "Producto.h"
#include <wx/string.h>

void CompraFrame::OnButton1Click(wxCommandEvent& event)
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

    wxString str = tc1->GetValue();  // obtenemos todos los valores ingresados
    c=wxAtoi(str);
    str=tc2->GetValue();
    cant=wxAtoi(str);
    prod.setcodigo(c);
    prod.buscar(arch);  // buscamos el codigo
    if(arch.eof())
        st1->SetLabel("Compra inexistente");
    else
    {
        arch.clear();
        arch.seekg(arch.tellg()-sizeof(Producto),ios::beg);
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
        if(reg.getBorrado()==0)
        {
            e=reg.getexistencias();       //obtenemos las existencias
            cant+=e;                      //sumamos la cantidad ingresada a las ecistencias
            reg.setexistencias(cant);     //establecemos el nuevo valor a las existencias
            if(cant<=reg.getstockmax()) // verificamos que la cantidad a comprar sea menor al stock maximo
            {
                arch.seekp(arch.tellg()-sizeof(Producto),ios::beg);
                arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
                st1->SetLabel("Compra exitosa");
            }
            else
            {
                st1->SetLabel("La compra supera el stock maximo");
            }
        }

        else
        {
            st1->SetLabel("Producto dado de baja");
        }
    }
}
void CompraFrame::OnButton2Click(wxCommandEvent& event)
{
    tc1->Clear();
    tc2->Clear();
    st1->SetLabel("");
}
