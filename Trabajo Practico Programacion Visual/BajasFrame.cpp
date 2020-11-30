#include "BajasFrame.h"

//(*InternalHeaders(BajasFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(BajasFrame)
const long BajasFrame::ID_STATICTEXT1 = wxNewId();
const long BajasFrame::ID_TEXTCTRL1 = wxNewId();
const long BajasFrame::ID_STATICTEXT2 = wxNewId();
const long BajasFrame::ID_BUTTON1 = wxNewId();
const long BajasFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(BajasFrame,wxFrame)
    //(*EventTable(BajasFrame)
    //*)
END_EVENT_TABLE()

BajasFrame::BajasFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(BajasFrame)
    Create(parent, id, _("Bajas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    SetBackgroundColour(wxColour(255,255,255));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo:"), wxPoint(48,104), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(200,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    st1 = new wxStaticText(this, ID_STATICTEXT2, wxEmptyString, wxPoint(56,152), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont st1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    st1->SetFont(st1Font);
    Button1 = new wxButton(this, ID_BUTTON1, _("Baja"), wxPoint(144,400), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\baja-producto.jpg")).Rescale(wxSize(160,168).GetWidth(),wxSize(160,168).GetHeight())), wxPoint(104,200), wxSize(160,168), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&BajasFrame::Ontc1Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&BajasFrame::OnButton1Click);
    //*)
}

BajasFrame::~BajasFrame()
{
    //(*Destroy(BajasFrame)
    //*)
}

#include <fstream>
#include "Producto.h"
#include <wx/string.h>

void BajasFrame::OnButton1Click(wxCommandEvent& event)
{
    Producto reg,prod;
    fstream arch;
    int c;

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
    prod.setcodigo(c);
    prod.buscar(arch);  // buscamos el codigo
    if(arch.eof())
        st1->SetLabel("Baja inexistente");
   else
    {
        arch.clear();
        arch.seekg(arch.tellg()-sizeof(Producto),ios::beg);           // nos movemos al puntero anterior
        arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
        if (reg.getBorrado()==0)
        {
            reg.setBorrado(1);  //  lo marcamos con 1 para despues eliminarlo
            arch.seekp(arch.tellg()-sizeof(Producto),ios::beg);
            arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));
            st1->SetLabel("Baja exitosa");
        }
    else

        {
            st1->SetLabel("Producto dado de baja");
        }
    }

    arch.close();
}


void BajasFrame::Ontc1Text(wxCommandEvent& event)
{
    st1->SetLabel("");
}
