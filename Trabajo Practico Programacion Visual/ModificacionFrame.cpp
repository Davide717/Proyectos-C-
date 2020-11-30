#include "ModificacionFrame.h"

//(*InternalHeaders(ModificacionFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ModificacionFrame)
const long ModificacionFrame::ID_STATICTEXT1 = wxNewId();
const long ModificacionFrame::ID_STATICTEXT2 = wxNewId();
const long ModificacionFrame::ID_STATICTEXT3 = wxNewId();
const long ModificacionFrame::ID_STATICTEXT4 = wxNewId();
const long ModificacionFrame::ID_TEXTCTRL1 = wxNewId();
const long ModificacionFrame::ID_TEXTCTRL2 = wxNewId();
const long ModificacionFrame::ID_TEXTCTRL3 = wxNewId();
const long ModificacionFrame::ID_TEXTCTRL4 = wxNewId();
const long ModificacionFrame::ID_BUTTON1 = wxNewId();
const long ModificacionFrame::ID_BUTTON2 = wxNewId();
const long ModificacionFrame::ID_STATICTEXT5 = wxNewId();
const long ModificacionFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ModificacionFrame,wxFrame)
	//(*EventTable(ModificacionFrame)
	//*)
END_EVENT_TABLE()

ModificacionFrame::ModificacionFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ModificacionFrame)
	Create(parent, id, _("Modificaciones"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(418,558));
	Move(wxDefaultPosition);
	SetBackgroundColour(wxColour(45,143,242));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo:"), wxPoint(24,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese stock maximo:"), wxPoint(24,144), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Ingrese stock minimo:"), wxPoint(24,96), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Ingrese precio:"), wxPoint(24,192), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(192,48), wxSize(164,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(256,96), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	tc3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(264,144), wxSize(112,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	tc4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(184,192), wxSize(164,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Modificar"), wxPoint(96,496), wxSize(80,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(128,255,255));
	Button2 = new wxButton(this, ID_BUTTON2, _("Nuevo"), wxPoint(232,496), wxSize(80,24), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(128,255,255));
	st1 = new wxStaticText(this, ID_STATICTEXT5, wxEmptyString, wxPoint(40,248), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont st1Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	st1->SetFont(st1Font);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\modificacion.jpg")).Rescale(wxSize(216,168).GetWidth(),wxSize(216,168).GetHeight())), wxPoint(104,296), wxSize(216,168), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModificacionFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ModificacionFrame::OnButton2Click);
	//*)
}

ModificacionFrame::~ModificacionFrame()
{
	//(*Destroy(ModificacionFrame)
	//*)
}

#include <fstream>
#include "Producto.h"
#include <wx/string.h>

void ModificacionFrame::OnButton1Click(wxCommandEvent& event)
{
    Producto reg,prod;
    fstream arch;
    int c,smin,smax,p;

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
    smin=wxAtoi(str);
    str=tc3->GetValue();
    smax=wxAtoi(str);
    str=tc4->GetValue();
    p=wxAtoi(str);


    prod.setcodigo(c);
    prod.buscar(arch);   // buscamos el codigo
    if(arch.eof())
            st1->SetLabel("Modificacion inexistente");
    else
        {
            arch.clear();
            arch.seekg(arch.tellg()-sizeof(Producto),ios::beg);               // para moverse al registro anterior    tellg()  (dice donde esta el puntero)
            arch.read(reinterpret_cast<char *>(&reg),sizeof(Producto));
            if(reg.getBorrado()==0)   // para lo que no esta marcado para eliminarlo
            {
                reg.setstockmin(smin);  //  establecemos los nuevos valores a los atributos
                reg.setstockmax(smax);
                reg.setprecio(p);
                arch.seekp(arch.tellg()-sizeof(Producto),ios::beg);
                arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));  // grabamos
                st1->SetLabel("Modificacion exitosa");
            }
        else
        {
            st1->SetLabel("Producto dado de baja");
        }
    arch.close();

}
}

void ModificacionFrame::OnButton2Click(wxCommandEvent& event)
{
    tc1->Clear();
    tc2->Clear();
    tc3->Clear();
    tc4->Clear();
    st1->SetLabel("");
}
