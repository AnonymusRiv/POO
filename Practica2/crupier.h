#ifndef CRUPIER_H
#define CRUPIER_H

#include "persona.h"
using namespace std;

class Crupier: public Persona{
    private:
        string codigo_;                                                         //se le asigna una cadena codigo que almacenará el código del crupier

    public:
    inline Crupier(string dni, string codigo, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="") : Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){codigo_=codigo;}
    /*Este es el constructor de la clase Crupier que recibe todos los parámetros de la clase que hereda de la clase persona y además, indicamos el valor inicial de los string a vacio, menos el dni, la edad a 0 y el código*/

    inline void setCodigo(string const codigo){codigo_=codigo;}                 //esta función inline nos permitirá poner el código al crupier que recibira el propio código como parámetro
    inline string getCodigo() const {return codigo_;}                           //esta función inline nos permitirá devolver el código de un crupier
};

#endif