#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona{                                                                            //*creamos la clase persona
    private:                                                                                //!esta sera la parte privada de la clase, que será los parámetros que tiene la misma
        string dni_;                                                                        //se le asigna una cadena dni que almacenará el dni de la persona
        string nombre_;                                                                     //se le asigna una cadena nombre que almacenará el nombre de la persona
        string apellidos_;                                                                  //se el asigna una cadena apellidos que almacenará los apellidos de la persona
        int edad_;                                                                          //se le asigna un entero edad que almacenará la edad de la persona
        string direccion_;                                                                  //se le asigna una cadena direccion que almacenará la dirección de la persona
        string localidad_;                                                                  //se le asigna una cadena localidad que almacenará la localidad de la persona
        string provincia_;                                                                  //se le asigna una cadena provincia que almacenará la provincia de la persona
        string pais_;                                                                       //se le asigna una cadena pais que almacenará el pais de la persona

    public:                                                                                 //!esta es la parte pública de la clase, que será donde se encontrarán las funciones de la clase

        Persona(string dni, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="");
        /*Este es el contructor de la clase persona que recibe todos los parámetros de la clase y además, indicamos el valor inicial de los string a vacio, menos el dni y la edad a 0*/

        inline void setDNI(string const dni){dni_=dni;}                                     //esta función inline nos permitirá poner el dni a la persona que recibirá el dni introducido y se pondrá dentro de la clase persona dicho dni
        inline string getDNI() const {return dni_;}                                         //esta función inline nos permitirá devolver el valor del dni de una persona

        inline void setNombre(string const nombre){nombre_=nombre;}                         //esta función inline nos permitirá poner el nombre a la persona que recibirá el nombre introducido y se pondrá dentro de la clase persona dicho nombre
        inline string getNombre() const {return nombre_;}                                   //esta función inline nos permitirá devolver el valor del nombre de una persona

        inline void setApellidos(string const apellidos){apellidos_=apellidos;}             //esta función inline nos permitirá poner los apellidos a la persona que recibirá los apellidos introducidos y se pondrá dentro de la clase persona dichos apellidos
        inline string getApellidos() const {return apellidos_;}                             //esta función inline nos permitirá devolver el valor de los apellidos de una persona

        bool setEdad(int const &edad);                                                      //esta función nos permitirá poner la edad a la persona que recibirá un dicha edad
        inline int getEdad(){return edad_;}                                                 //esta función inline nos permitirá devolver el valor del edad de una persona

        inline void setDireccion(string const direccion){direccion_=direccion;}             //esta función inline nos permitirá poner la dirección a la persona que recibirá la dirección introducida y se pondrá dentro de la clase persona dicha dirección
        inline string getDireccion() const {return direccion_;}                             //esta función inline nos permitirá devolver el valor de la dirección de una persona

        inline void setLocalidad(string const localidad){localidad_=localidad;}             //esta función inline nos permitirá poner la localidad a la persona que recibirá la localidad introducida y se pondrá dentro de la clase persona dicha localidad
        inline string getLocalidad() const {return localidad_;}                             //esta función inline nos permitirá devolver el valor de la localidad de una persona

        inline void setProvincia(string const provincia){provincia_=provincia;}             //esta función inline nos permitirá poner la provincia a la persona que recibirá la provincia introducida y se pondrá dentro de la clase persona dicha provincia
        inline string getProvincia() const {return provincia_;}                             //esta función inline nos permitirá devolver el valor de la provincia de una persona

        inline void setPais(string const pais){pais_=pais;}                                 //esta función inline nos permitirá poner el país a la persona que recibirá el país introducido y se pondrá dentro de la clase persona dicho país
        inline string getPais() const {return pais_;}                                       //esta función inline nos permitirá devolver el valor del país de una persona

        inline string getApellidosyNombre() const {return (apellidos_+", "+nombre_);}       //esta función inline nos permitirá devolver el valor del nombre y de los apellidos de una persona

        bool mayor() ;                                                                      //esta función nos permitirá saber si una persona cualquiera es mayor de edad o no, siendo mayor de edad que la persona tenga igual o más de 18 años
};

#endif