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

        bool setBola(int const &bola);
        inline int getBola() const {return bola_;}

        bool setBanca(int const &banca);
        inline int getBanca() const {return banca_;}

        inline void setCrupier(Crupier const &crupier){crupier_=crupier;}
        inline Crupier getCrupier() const {return crupier_;}

        inline list<Jugador> getJugadores() const {return jugadores_;}

        bool addJugador(Jugador &Jugador);

        int deleteJugador(string const &dni);
        int deleteJugador(Jugador const &jugador);

        void escribeJugadores();
        void leeJugadores();

        inline void giraRuleta(){srand(time(NULL)); bola_=rand()%(37);}

        void getPremios();

        bool esRojo(int const &valor);
        bool esPar(int const &valor);
        bool esAlto(int const &valor);
};


#endif