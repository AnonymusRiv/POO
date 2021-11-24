#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona{
    private:
        string dni_;
        string nombre_;
        string apellidos_;
        int edad_;
        string direccion_;
        string localidad_;
        string provincia_;
        string pais_;

    public:
        Persona(string dni, string nombre="", string apellidos="", int edad=0, string direccion="", string localidad="", string provincia="", string pais="");

        inline void setDNI(string const dni){dni_=dni;}
        inline string getDNI() const {return dni_;}

        inline void setNombre(string const nombre){nombre_=nombre;}
        inline string getNombre() const {return nombre_;}

        inline void setApellidos(string const apellidos){apellidos_=apellidos;}
        inline string getApellidos() const {return apellidos_;}

        bool setEdad(int const &edad);
        inline int getEdad(){return edad_;}

        inline void setDireccion(string const direccion){direccion_=direccion;}
        inline string getDireccion() const {return direccion_;}

        inline void setLocalidad(string const localidad){localidad_=localidad;}
        inline string getLocalidad() const {return localidad_;}

        inline void setProvincia(string const provincia){provincia_=provincia;}
        inline string getProvincia() const {return provincia_;}

        inline void setPais(string const pais){pais_=pais;}
        inline string getPais() const {return pais_;}

        inline string getApellidosyNombre() const {return (apellidos_+", "+nombre_);}

        bool mayor() ;
};

#endif