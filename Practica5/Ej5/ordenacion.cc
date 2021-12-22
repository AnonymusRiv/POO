#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "jugador.h"
#include "persona.h"

using namespace std;

vector <Jugador> leeJugadores(){                                                                    //leemos los jugadores del fichero (igual que el leeJugadores de la clase ruleta)
    vector <Jugador> jugadores;
    jugadores.empty();
    ifstream f("jugadores.txt");

    char dni[255], codigo[255], nombre[255], apellidos[255];
    char direccion[255], localidad[255], provincia[255], pais[255], dinero[255];

    while(f.getline(dni, 255, ',')){
        f.getline(codigo, 255, ',');
        f.getline(nombre, 255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais, 255, ',');
        f.getline(dinero, 255, '\n');

        Jugador aux (dni, codigo, nombre, apellidos, 0, direccion, localidad, provincia, pais);
        jugadores.push_back(aux);
    }
    f.close();
    return jugadores;
}

bool ascendente(Jugador j1, Jugador j2){                                        //creamos una función que reciba los dos jugadores y lea el dni de cada uno y devuelva el menor
    return j1.getDNI()<j2.getDNI();
}

bool descendente(Jugador j1, Jugador j2){                                       //creamos una función que reciba los dos jugadores y lea el dni de cada uno y devuelva el mayor
    return j1.getDNI()>j2.getDNI();
}

int main(){
    vector<Jugador> jugadores;                                                  //creamos un vector de jugadores donde guardaremos los jugadores leidos
    jugadores = leeJugadores();                                                 //leemos los jugadores del fichero

    cout << "El vector sin ordenar sería" << endl;                              //imprimimos el vector sin ordenar
    for (int i=0; i<(int) jugadores.size(); i++){
        cout << jugadores[i].getDNI() << " ";
    }

    int opcion;
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"\tInserte un método de ordenación"<<endl;                            //insertamos un método de ordenación de los dni
    cout<<"\t1. ascendente"<<endl;
    cout<<"\t2. descendente"<<endl;
    cout<<"-----------------------------------"<<endl;
    cin>>opcion;

    switch(opcion){
        case 1:                                                                 //ordenamos los jugadores de forma ascendente
            cout<<"Método de ordenación ascendente"<<endl;
            sort(jugadores.begin(), jugadores.end(), ascendente);               //se ordena de forma ascendente
        break;
        case 2:                                                                 //ordenamos los jugadores de forma descendente
            cout<<"Método de ordenación descendente"<<endl;
            sort(jugadores.begin(), jugadores.end(), descendente);              //se ordena de forma descendente
        break;
        default:                                                                //si introducimos una opción no válida imprimimos el mensaje del error
            cout<<"Inserte una opción válida"<<endl;
        break;
    }

    cout << "El vector ordenado se quedaría" << endl;                           //imprimimos el vector ordenado
    for (int i=0; i<(int) jugadores.size(); i++){
        cout << jugadores[i].getDNI() << " ";
    }
    cout<<endl;
}