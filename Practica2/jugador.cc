#include "jugador.h"
#include <fstream>
#include <iostream>

using namespace std;

void Jugador::setApuestas(){
    apuestas_.clear();                                              //limpiamos las apuestas que haya podido haber anteriormente
    ifstream f((getDNI() + ".txt"));                                //abrimos el archivo donde estarán sus apuestas que será acorde a su dni
    if(!f){
        cout<<"ERROR: no se pudo abrir el fichero"<<endl;           //si no se puede abrir muestra un mensaje de error y se para el programa
        EXIT_FAILURE;
    }
    Apuesta apuesta;                                                //creamos un objeto de la clase apuestauestas
    string cadena;                                                  //creamos una variable auxiliar para obtener los datos del fichero
    getline(f, cadena, ',');                                        //leemos la primera linea hasta la coma
    while(!f.eof()){                                                //mientras el fichero no se haya acabdo, seguirá leyendo datos de él
        apuesta.tipo=stoi(cadena);                                  //guardamos el tipo de apuesta que este haciendo en numero entero
        getline(f, cadena, ',');                                    //leemos el archivo hasta la siguiente coma
        apuesta.valor=cadena;                                       //guardamos la cadena leida en el valor de dicha apuesta
        getline(f, cadena, '\n');                                   //leemos el fichero hasta el fin de linea
        apuesta.cantidad=stoi(cadena);                              //guardamos la cantidad de la apuesta leida
        apuestas_.push_back(apuesta);                               //añadimos la apuesta leida entera a la lista de apuestas
        getline(f, cadena, ',');                                    //leemos el archivo hasta la siguiente coma
    }
    f.close();                                                      //cerramos el fichero ya que hemos leido todos los datos existentes en este
}