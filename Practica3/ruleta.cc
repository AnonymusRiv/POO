#include <fstream>
#include <iostream>
#include "ruleta.h"

bool Ruleta::setBola(int const &bola){                                                      //esta función nos permitirá poner el valor a la bola
    if(bola<0 || bola>36){                                                                      //comprobamos si el valor no está entre 0 y 36
        return false;
    }
    bola_=bola;
    return true;
}

bool Ruleta::setBanca(int const &banca){
    if(banca<0){
        return false;
    }
    banca_=banca;
    return true;
}

bool Ruleta::addJugador(Jugador &jugador){
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){
        if(i->getDNI()==jugador.getDNI()){
            return false;
        }
    }
    jugadores_.push_back(jugador);

    fstream f;
    string file=jugador.getDNI() + ".txt";
    f.open(file, ios_base::app);
    if(!f){
        cout<<"No se puede abrir el archivo "<<jugador.getDNI()<<".txt"<<endl;
        EXIT_FAILURE;
    }
    f.close();
    return true;
}

int Ruleta::deleteJugador(string const &dni){
    if(jugadores_.empty()){
        return -1;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){
            if(i->getDNI()==dni){
                jugadores_.erase(i);
                return 1;
            }
    }
    return -2;
}

int Ruleta::deleteJugador(Jugador const &jugador){
    if(jugadores_.empty()){
        return -1;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){
            if(i->getDNI()==jugador.getDNI()){
                jugadores_.erase(i);
                return 1;
            }
    }
    return -2;
}

void Ruleta::escribeJugadores(){
    fstream f;
    f.open("jugadores.txt", ios::out);
    if(!f){
        cout<<"No se puede abrir el archivo jugadores.txt"<<endl;
        EXIT_FAILURE;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){
        f<<i->getDNI()<<","<<
        i->getCodigo()<<","<<
        i->getNombre()<<","<<
        i->getApellidos()<<","<<
        i->getDireccion()<<","<<
        i->getLocalidad()<<","<<
        i->getProvincia()<<","<<
        i->getPais()<<","<<
        i->getDinero()<<","<<endl;
    }
    f.close();
}

void Ruleta::leeJugadores(){
    jugadores_.empty();
    fstream f;
    f.open("jugadores.txt",ios::in);

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
        aux.setDinero(atoi(dinero));
        jugadores_.push_back(aux);
    }
    f.close();
}

void Ruleta::getPremios(){
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){
        i->setApuestas();
        list <Apuesta> aux = i->getApuestas();
        for(auto j=aux.begin(); j!=aux.end(); j++){
            Apuesta apuesta = *j;
            switch(apuesta.tipo){
                case 1:
                    if(bola_ == stoi(apuesta.valor)){
                        setBanca(getBanca() - 35*apuesta.cantidad);
                        i->setDinero(i->getDinero() + (apuesta.cantidad *35));
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                break;

                case 2:
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                    else if((apuesta.valor=="rojo" && esRojo(bola_)) || (apuesta.valor=="negro" && !esRojo(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                break;

                case 3:
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                    else if((apuesta.valor=="par" && esPar(bola_)) || (apuesta.valor=="impar" && !esPar(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                break;

                case 4:
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                    else if((apuesta.valor=="alto" && esAlto(bola_)) || (apuesta.valor=="bajo" && !esAlto(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                    }
                break;
            }
        }
    }
}

bool Ruleta::esRojo(int const &valor){
    int rojo[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    for(int i=0; i<18; i++){
        if(valor==rojo[i]){
            return true;
        }
    }
    return false;
}

bool Ruleta::esPar(int const &valor){
    if(valor%2==0){
        return true;
    }
    return false;
}

bool Ruleta::esAlto(int const &valor){
    if(valor>=1 && valor<=18){
        return false;
    }
    return true;
}