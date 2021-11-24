#include "jugador.h"
#include <fstream>
#include <iostream>

using namespace std;

void Jugador::setApuestas(){
    apuestas_.clear();
    ifstream f((getDNI() + ".txt"));
    if(!f){
        cout<<"ERROR: no se pudo abrir el fichero"<<endl;
        EXIT_FAILURE;
    }
    Apuesta ap;
    string cadena;
    getline(f, cadena, ',');
    while(!f.eof()){
        ap.tipo=stoi(cadena);
        getline(f, cadena, ',');
        ap.valor=cadena;
        getline(f, cadena, '\n');
        ap.cantidad=stoi(cadena);
        apuestas_.push_back(ap);
        getline(f, cadena, ',');
    }
    f.close();
}