#include "Producto.h"
#include <string.h>
#include <fstream>
using namespace std;

Producto::Producto(int c,string nom,int exis,int smin,int smax,int p)
{
    setcodigo(c);
    setdescripcion(nom);
    setexistencias(exis);
    setstockmin(smin);
    setstockmax(smax);
    setprecio(p);

}

void Producto::setcodigo(int c)
{
    if(c<0)
        codigo=1;
    else
        codigo=c;
}

int Producto::getcodigo()
{
    return codigo;
}

void Producto::setdescripcion(string nom)
{
    const char *valorNombre = nom.data(); // el data me devulve la informacion que esta encapsulada en el string
    int longitud = nom.size();  // con size obtenemos la longitud
    if(longitud>=38)
        longitud=37;  //no puede superar 38 por que va al final un \0
    strncpy(descripcion,valorNombre,longitud);   // copiamos hasta cierta cantidad la n (de los primeros n) lo da longitud
    descripcion[longitud] = '\0';
}

string Producto::getdescripcion()
{
    return descripcion;
}

void Producto::setexistencias(int exis)
{
    if(exis<0)
        existencias=1;
    else
        existencias=exis;
}

int Producto::getexistencias()
{
    return existencias;
}

void Producto::setstockmin(int smin)
{
    if(smin<0)
        stockmin=1;
    else
        stockmin=smin;
}

int Producto::getstockmin()
{
    return stockmin;
}

void Producto::setstockmax(int smax)
{
    if(smax<0)
        stockmax=1;
    else
        stockmax=smax;
}

int Producto::getstockmax()
{
    return stockmax;
}

void Producto::setprecio(int p)
{
     if(p<0)
        precio=1;
    else
        precio=p;
}

int Producto::getprecio()
{
    return precio;
}

void Producto::setBorrado(int b)
{
    if(b!=0 && b!=1)   // solo 0 o 1
        borrado=0;
    else
        borrado=b;
}

int Producto::getBorrado()
{
    return borrado;
}

void Producto::buscar(fstream &a)
{
    Producto reg;  // variable de tipo objeto
    a.clear();   // limpia señal de eof
    a.seekg(0,ios::beg);  // 0 desplazamiento desde el principio
    a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));   // leemos el registro del objeto persona calculando su tamaño
    while(!a.eof()&&reg.getcodigo()!=codigo)        // comprobamos que el codigo que leimos sea diferente al que ya tengamos
    {
        a.read(reinterpret_cast<char *>(&reg),sizeof(Producto));  // volvemos a leer para seguir buscando
    }
}
