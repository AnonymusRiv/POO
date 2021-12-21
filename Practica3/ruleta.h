#ifndef RULETA_H
#define RULETA_H

#include <list>
#include "jugador.h"
#include "crupier.h"

using namespace std;

class Ruleta{
    private:
        int banca_;
        int bola_;
        list<Jugador> jugadores_;
        Crupier crupier_;

    public:
        inline Ruleta(Crupier crupier):crupier_(crupier.getDNI(), crupier.getCodigo()){bola_=-1; banca_=1000000;}
        /*Este es el contructor inline de la clase ruleta que hereda de la clase crupier que recibe como parámetro un objeto de la clase crupier y además le asignamos el valor de bola a -1 y el de banca a un millón*/

        bool setBola(int const &bola);                                                  //esta función nos permitirá poner el valor a la bola
        inline int getBola() const {return bola_;}                                      //esta función inline nos permitirá devolver el valor de la bola

        bool setBanca(int const &banca);                                                //esta función nos permitirá poner el valor a la banca
        inline int getBanca() const {return banca_;}                                    //esta función inline nos permitirá devolver el valor de la banca

        inline void setCrupier(Crupier const &crupier){crupier_=crupier;}               //esta función inline nos permitirá poner el valor del objeto de la clase crupier
        inline Crupier getCrupier() const {return crupier_;}                            //esta función inline nos permitirá devolver el valor del objeto de la clase crupier

        inline list<Jugador> getJugadores() const {return jugadores_;}                  //esta función inline nos permitirá devolver la lista de jugadores

        bool addJugador(Jugador &Jugador);                                              //esta función nos permitirá añadir un objeto de la clase jugador

        int deleteJugador(string const &dni);                                           //esta función nos permitirá eliminar un objeto de la clase jugador al que tendremos que pasar su dni como parámetro
        int deleteJugador(Jugador const &jugador);                                      //esta función nos permitirá eliminar un objeto de la clase jugador al que tendremos que pasar su objeto de la clase jugador como parámetro

        void escribeJugadores();                                                        //esta función nos permitirá escribir los datos de la lista de jugadores
        void leeJugadores();                                                            //esta función nos permitirá leer los datos de la lista de jugadores

        inline void giraRuleta(){srand(time(NULL)); bola_=rand()%(37);}                 //esta función inline nos permitirá simular el giro de una ruleta donde obtendra un número aleatorio entre 0 y 37

        void getPremios();                                                              //esta función nos permitirá recorrer la lista de jugadores y vargar sus apuestas

        bool esRojo(int const &valor);                                                  //esta función nos permitirá comprobar si la bola es roja
        bool esPar(int const &valor);                                                   //esta función nos permitirá comprobar si la bola es par
        bool esAlto(int const &valor);                                                  //esta función nos permitirá comprobar su la bola tiene un balor alto
};


#endif