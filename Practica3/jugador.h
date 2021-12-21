#ifndef JUGADOR_H
#define JUGADOR_H

#include "persona.h"
#include <list>
using namespace std;

struct Apuesta{                                                             //creamos una estructura Apuesta que tendrá los datos de una apuesta de un jugador
    int tipo;                                                               //tendrá el tipo de apuesta que quiera realizar
    string valor;                                                           //tendrá el valor de dicha apuesta
    int cantidad;                                                           //tendrá la cantidad que apostó
};

class Jugador: public Persona{                                              //creamos la clase jugador que es una herencia de la clase persona, y por lo tanto, tendrá sus mismos atributos
    private:                                                                //además de los atributos de la clase persona, tendrá tres atributos privados más
        int dinero_;                                                        //se le asigna un entero que será el dinero que tendrá dicho jugador
        string codigo_;                                                     //se le asigna una cadena que será el código que tendrá dicho jugador
        list <Apuesta> apuestas_;                                           //se le asigna una lista de tipo apuestas que será una lista con todas las reservas que el jugador ha realizado

    public:
        inline Jugador(string dni, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="") :Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=1000;}
        /*Constructor de la clase jugador que hereda los parámetros de la clase persona, se le asigna el código y ponemos el valor inicial del dinero a 1000*/

        inline void setCodigo(string codigo){codigo_=codigo;}               //esta función inline nos permitirá poner el código al jugador que recibira el propio código como parámetro
        inline string getCodigo() const {return codigo_;}                   //esta función inline nos permitirá devolver el código de un jugador

        inline void setDinero(int const &dinero){dinero_=dinero;}           //esta función inline nos permitirá poner el dinero al jugador que recibira el propio dinero como parámetro
        inline int getDinero() const {return dinero_;}                      //esta función inline nos permitirá devolver el dinero de un jugador

        void setApuestas();                                                 //esta función nos permitirá poner las apuestas de un jugador
        inline list<Apuesta> getApuestas() const{return apuestas_;}         //esta función inline nos permitirá devolver las apuestas de un jugador
};

#endif