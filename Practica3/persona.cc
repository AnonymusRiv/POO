#include "persona.h"
#include <string>
using namespace std;

Persona::Persona(string dni, string nombre, string apellidos, int edad, string direccion, string localidad, string provincia, string pais){
    /*Este es el contructor de la clase persona que recibe todos los parámetros y los iguala a las variables privadas de cada uno*/
    dni_=dni;
    nombre_=nombre;
    apellidos_=apellidos;
    edad_=edad;
    direccion_=direccion;
    localidad_=localidad;
    provincia_=provincia;
    pais_=pais;
}

bool Persona::setEdad(int const &edad){                 //esta función nos permitirá poner la edad a la persona que recibirá un dicha edad
    if(edad>=0){                                            //comprobamos que dicha edad es mayor de 0, ya que sino, no sería una edad válida
        edad_=edad;                                         //guardamos ese valor en la variable privada de la clase
        return true;
    }
    return false;
}

bool Persona::mayor(){                                  //esta funcion nos permitirá saber si una persona es mayor de edad o no
    if(getEdad()<18){                                       //como ya se tiene la edad dentro del objeto de la clase persona, usamos el getEdad para tomar esa edad y comprobamos si es menor que 18
        return false;
    }
    return true;
}