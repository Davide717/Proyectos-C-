#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include<fstream>
#include<string>
using namespace std;

class Producto
{
    public:
        Producto(int =0,string ="",int= 0,int=0,int=0,int=0);
        void setcodigo(int);
        int getcodigo();
        void setdescripcion(string);
        string getdescripcion();
        void setexistencias(int);
        int getexistencias();
        void setstockmin(int);
        int getstockmin();
        void setstockmax(int);
        int getstockmax();
        void setprecio(int);
        int getprecio();
        void setBorrado(int);   // marcamos un dato para luego borrarlo
        int getBorrado();
        void buscar(fstream &);
    private:
        int codigo,existencias,stockmin,stockmax,precio,borrado;
        char descripcion[38];

};

#endif // PRODUCTO_H_INCLUDED
