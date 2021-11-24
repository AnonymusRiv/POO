#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
using namespace std;

struct Apuesta{
    int tipo;
    string valor;
    int cantidad;
};

class Jugador: public Persona{
    private:
        int dinero_;
        string codigo_;
        list <Apuesta> apuestas_;

    public:
        inline Jugador(string dni, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="") :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=1000;}

        inline void setCodigo(string codigo){codigo_=codigo;}
        inline string getCodigo() const {return codigo_;}

        inline void setDinero(int const &dinero){dinero_=dinero;}
        inline int getDinero() const {return dinero_;}

        void setApuestas();
        inline list<Apuesta> getApuestas() const{return apuestas_;}
};

#endif