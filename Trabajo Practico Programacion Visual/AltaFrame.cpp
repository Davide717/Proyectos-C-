#include "AltaFrame.h"

//(*InternalHeaders(AltaFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(AltaFrame)
const long AltaFrame::ID_STATICTEXT1 = wxNewId();
const long AltaFrame::ID_STATICTEXT2 = wxNewId();
const long AltaFrame::ID_STATICTEXT3 = wxNewId();
const long AltaFrame::ID_STATICTEXT4 = wxNewId();
const long AltaFrame::ID_STATICTEXT5 = wxNewId();
const long AltaFrame::ID_STATICTEXT6 = wxNewId();
const long AltaFrame::ID_TEXTCTRL1 = wxNewId();
const long AltaFrame::ID_TEXTCTRL2 = wxNewId();
const long AltaFrame::ID_TEXTCTRL3 = wxNewId();
const long AltaFrame::ID_TEXTCTRL4 = wxNewId();
const long AltaFrame::ID_TEXTCTRL5 = wxNewId();
const long AltaFrame::ID_TEXTCTRL6 = wxNewId();
const long AltaFrame::ID_BUTTON1 = wxNewId();
const long AltaFrame::ID_BUTTON2 = wxNewId();
const long AltaFrame::ID_BUTTON3 = wxNewId();
const long AltaFrame::ID_STATICTEXT7 = wxNewId();
const long AltaFrame::ID_STATICBITMAP1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AltaFrame,wxFrame)
	//(*EventTable(AltaFrame)
	//*)
END_EVENT_TABLE()

AltaFrame::AltaFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AltaFrame)
	Create(parent, id, _("Altas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(447,609));
	Move(wxDefaultPosition);
	Hide();
	SetBackgroundColour(wxColour(20,156,136));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ingrese codigo: "), wxPoint(24,16), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese descripcion: "), wxPoint(24,56), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Ingrese existencias: "), wxPoint(24,104), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Ingrese stock minimo:"), wxPoint(24,152), wxSize(234,16), 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Ingrese stock maximo: "), wxPoint(24,200), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Ingrese precio: "), wxPoint(24,248), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	tc1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(192,16), wxSize(144,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	tc2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(240,56), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	tc3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(240,104), wxSize(120,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	tc4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(256,152), wxSize(112,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	tc5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxPoint(264,200), wxSize(112,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	tc6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(184,248), wxSize(152,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Alta"), wxPoint(56,544), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetBackgroundColour(wxColour(128,255,255));
	Button2 = new wxButton(this, ID_BUTTON2, _("Nuevo"), wxPoint(160,544), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetBackgroundColour(wxColour(128,255,255));
	Button3 = new wxButton(this, ID_BUTTON3, _("Cerrar"), wxPoint(264,544), wxSize(-1,-1), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetBackgroundColour(wxColour(128,255,255));
	st1 = new wxStaticText(this, ID_STATICTEXT7, wxEmptyString, wxPoint(32,304), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	wxFont st1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	st1->SetFont(st1Font);
	StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T("C:\\Users\\lucas\\OneDrive\\Escritorio\\imagenes tp\\sumar-Stock.jpg")).Rescale(wxSize(258,176).GetWidth(),wxSize(258,176).GetHeight())), wxPoint(88,344), wxSize(258,176), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AltaFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AltaFrame::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AltaFrame::OnButton3Click);
	//*)
}

AltaFrame::~AltaFrame()
{
	//(*Destroy(AltaFrame)
	//*)
}

#include <fstream>
#include "Producto.h"
#include <wx/string.h>

void AltaFrame::OnButton1Click(wxCommandEvent& event) // boton de alta
{
    Producto reg,prod;  //los objetos
    fstream arch;
    int c,e,smin,smax,p;  // los atributos
    wxString n;              // para el nombre

    arch.open("productos.dat",ios::app|ios::binary);       // truquillo =)
    if(!arch)
    {
        st1->SetLabel("Error de apertura de archivo");
        Close();
    }
    arch.close();
    arch.open("productos.dat",ios::in|ios::out |ios::binary);    // hacemos escrituras y lecturas
    if(!arch)
    {
        st1->SetLabel("Error de apertura de archivo");
        Close();
    }

    wxString str = tc1->GetValue();  // declaro str para guardar todos los string
    c=wxAtoi(str);
    n = tc2->GetValue();       // el nombre no necesita conversion
    str = tc3->GetValue();     // obtenemos lo de text control 3
    e=wxAtoi(str);              // lo transformamamos a int
    str = tc4->GetValue();
    smin=wxAtoi(str);
    str = tc5->GetValue();
    smax=wxAtoi(str);
    str = tc6->GetValue();
    p=wxAtoi(str);

    prod.setcodigo(c);     // metemos el codigo en el objeto
    prod.buscar(arch);     // buscamos el codigo
    if(!arch.eof())
            st1->SetLabel("Alta existente");
    else
        {
            arch.clear();
            reg.setcodigo(c);                         //guardamos los atributos en el objeto
            reg.setdescripcion(n.ToStdString());     //hay que convertir asi el string por que es wx a un standard string
            reg.setexistencias(e);
            reg.setstockmin(smin);
            reg.setstockmax(smax);
            reg.setprecio(p);
            reg.setBorrado(0);                    //lo marcamos en 0 para dar altas
            arch.seekp(0,ios::end);               // nos vamos al final del archivo con 0 desplazamiento          seekp para grabar
            arch.write(reinterpret_cast<const char *>(&reg),sizeof(Producto));       // es asi para grabar hace un casteo de un const char * del tamaño de nuestro objeto
            st1->SetLabel("Alta exitosa");
        }
    arch.close();
}

void AltaFrame::OnButton2Click(wxCommandEvent& event)   //boton nuevo
{
    tc1->Clear();  // limpia el cuadro de texto
    tc2->Clear();
    tc3->Clear();
    tc4->Clear();
    tc5->Clear();
    tc6->Clear();
    st1->SetLabel("");  //limpia el mensaje
}

void AltaFrame::OnButton3Click(wxCommandEvent& event)  //boton cerar
{
    Close();  //cerramos
}
