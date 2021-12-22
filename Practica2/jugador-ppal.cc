#include <iostream>
#include <string>
#include <list>
#include "jugador.h"

using namespace std;

int main(){
    system("clear");
    string dni;
    string codigo;
    Jugador jugador(dni, codigo);                           //se crea un objeto de la clase jugador con valores basura para sobreescribirlos despues
    string cadena;                                          //se crea una variable cadena que leera los datos introducidos
    cout<<"Introduzca el dni del jugador: ";
    cin>>cadena;                                            //introduciremos los datos pedidos para rellenar el objeto de la clase jugador
    jugador.setDNI(cadena);                                 //llamaremos a las distintas clases set para asignar dicha variable al objeto en cuestion
    cout<<"Introduzca el codigo del jugador: ";
    cin>>cadena;
    jugador.setCodigo(cadena);
    cout<<"Introduzca el nombre del jugador: ";
    cin>>cadena;
    jugador.setNombre(cadena);
    cout<<"Introduzca los apellidos del jugador: ";
    cin>>cadena;
    jugador.setApellidos(cadena);
    cout<<"Introduzca la edad del jugador: ";
    cin>>cadena;
    jugador.setEdad(stoi(cadena));                          //en este caso tendremos que pasar un entero, por eso pasamos la cadena a entero y la pasamos como parámetro
    cout<<"Introduzca direccion del jugador: ";
    cin>>cadena;
    jugador.setDireccion(cadena);
    cout<<"Introduzca el localidad del jugador: ";
    cin>>cadena;
    jugador.setLocalidad(cadena);
    cout<<"Introduzca el provincia del jugador: ";
    cin>>cadena;
    jugador.setProvincia(cadena);
    cout<<"Introduzca el pais del jugador: ";
    cin>>cadena;
    jugador.setPais(cadena);
    cout<<endl;

    list<Apuesta> aux;                                      //creamos una lista auxiliar de tipo apuestas para ver las apuestas del jugador
    jugador.setApuestas();                                  //el jugador realizará sus apuestas
    aux=jugador.getApuestas();                              //obtenemos el resultado de sus apuestas y lo guardamos en la variable auxiliar para mostrarlo por pantalla
    list<Apuesta>::iterator a=aux.begin();                  //va a ser el iterador que nos ayudará a imprimir la lista tomando en primer lugar el principio de esta, e incrementándose en uno hasta acabar dicha lista

    for (int i=0; i<aux.size(); i++){
        cout<<"El tipo de apuesta del jugador es "<<(*a).tipo<<" cuyo valor es "<<(*a).valor<<" y cuya cantidad es "<<(*a).cantidad<<endl;
        a++;
    }
    return 0;
}