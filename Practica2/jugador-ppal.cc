#include <iostream>
#include <string>
#include <list>
#include "jugador.h"

int main(){
    using namespace std;

    system("clear");
    Jugador jugador("a","a");
    string cadena;
    cout<<"Introduzca el dni del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setDNI(cadena);
    cout<<"Introduzca el codigo del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setCodigo(cadena);
    cout<<"Introduzca el nombre del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setNombre(cadena);
    cout<<"Introduzca los apellidos del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setApellidos(cadena);
    cout<<"Introduzca la edad del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setEdad(stoi(cadena));
    cout<<"Introduzca direccion del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setDireccion(cadena);
    cout<<"Introduzca el localidad del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setLocalidad(cadena);
    cout<<"Introduzca el provincia del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setProvincia(cadena);
    cout<<"Introduzca el pais del jugador: ";
    getline(cin, cadena, '\n');
    jugador.setPais(cadena);

    list<Apuesta> aux;
    jugador.setApuestas();
    aux=jugador.getApuestas();
    list<Apuesta>::iterator a=aux.begin();

    for (int i=0; i<aux.size(); i++){
        cout<<"El tipo de apuesta del jugador es "<<(*a).tipo<<" cuyo valor es "<<(*a).valor<<" y cuya cantidad es "<<(*a).cantidad<<endl;
        a++;
    }
    return 0;
}