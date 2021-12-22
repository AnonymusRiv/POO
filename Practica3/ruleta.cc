#include <fstream>
#include <iostream>
#include "ruleta.h"

bool Ruleta::setBola(int const &bola){                                                      //*esta función nos permitirá poner el valor a la bola*/
    if(bola<0 || bola>36){                                                                      //comprobamos si el valor no está entre 0 y 36
        return false;                                                                           //si no esta devolvemos false ya que la bola no puede tener dicho valor
    }
    bola_=bola;                                                                                 //si es un valor válido se lo asignamos a la bola y devolvemos true
    return true;
}

bool Ruleta::setBanca(int const &banca){                                                    //*esta función nos permitirá poner el valor a la banca*/
    if(banca<0){                                                                                //si el número introducido es menor que 0 el valor no es válido por lo que se devolverá false
        return false;
    }
    banca_=banca;                                                                               //si el valor es válido se lo asignamos a la banca y devolvemos true
    lanzamientos_++;                                                                            //incrementamos el valor de los lanzamientos puesto que se ha realizado uno (PERTENECE A LA PRÁCTICA 4)
    return true;
}

bool Ruleta::addJugador(Jugador &jugador){                                                  //*esta función nos permitirá añadir un jugador pasado por parámetro*/
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){               //recorremos la lista de jugadores para comprobar si el jugador no está ya presente en la lista para no añadirlo dos veces
        if(i->getDNI()==jugador.getDNI()){                                                      //buscamos si el dni de la persona que hemos introducido corresponde con el dni de algun jugador existente
            cout<<"ERROR: Jugador ya presente"<<endl;                                           //si lo encontramos imprimimos el error y devolvemos false
            return false;
        }
    }
    jugadores_.push_back(jugador);                                                              //si el jugador no esta en la lista, lo añadimos a la cola de esta

    fstream f;
    string file=jugador.getDNI() + ".txt";
    f.open(file, ios_base::app);                                                                //abrimos el fichero donde se guardarían los datos del jugador para comprobar si nos daría error
    if(!f){                                                                                     //si nos da error, imprimimos el error y devolvemos un exit failure
        cout<<"No se puede abrir el archivo "<<jugador.getDNI()<<".txt"<<endl;
        EXIT_FAILURE;
    }
    f.close();                                                                                  //si no da error, cerramos el fichero y devolvemos true
    return true;
}

int Ruleta::deleteJugador(string const &dni){                                               //*esta función nos permitirá eliminar un jugador pasado su dni como parámetro*/
    if(jugadores_.empty()){                                                                     //si la lista de jugadores esta vacia devolvemos -1
        return -1;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){               //recorremos la lista de jugadores para buscar el dni
            if(i->getDNI()==dni){                                                               //vamos comprobando si el dni de la persona corresponde con el introducido
                jugadores_.erase(i);                                                            //si corresponde borramos de la lista ese elemento y devolvemos 1
                return 1;
            }
    }
    return -2;                                                                                  //si no encontramos al jugador en la lista de jugadores devolvemos 2
}

int Ruleta::deleteJugador(Jugador const &jugador){                                          //*esta función nos permitirá eliminar un jugador pasado dicho jugador como parámetro*/
    if(jugadores_.empty()){                                                                     //si la lista de jugadores esta vacia devolvemos -1
        return -1;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){               //recorremos la lista de jugadores para buscar el dni
            if(i->getDNI()==jugador.getDNI()){                                                  //vamos comprobando si el dni de la persona corresponde con el dni de la persona introducida
                jugadores_.erase(i);                                                            //si corresponde borramos de la lista ese elemento y devolvemos -1
                return 1;
            }
    }
    return -2;                                                                                  //si no encontramos al jugador en la lista de jugadores devolvemos 2
}

void Ruleta::escribeJugadores(){                                                            //*esta función nos permitirá escribir los jugadores*/
    fstream f;
    f.open("jugadores.txt", ios::out);                                                          //abrimos el fichero donde se encuentran todos los jugadores
    if(!f){                                                                                     //si no se puede abrir imprimimos el error y devolvemos un exit failure
        cout<<"No se puede abrir el archivo jugadores.txt"<<endl;
        EXIT_FAILURE;
    }
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){               //recorremos la lista de los jugadores para escribir los jugadores en el fichero
        f<<i->getDNI()<<","<<                                                                   //vamos imprimiendo todos sus valores en el archivo como se indica en la práctica
        i->getCodigo()<<","<<
        i->getNombre()<<","<<
        i->getApellidos()<<","<<
        i->getDireccion()<<","<<
        i->getLocalidad()<<","<<
        i->getProvincia()<<","<<
        i->getPais()<<","<<
        i->getDinero()<<","<<endl;
    }
    f.close();                                                                                  //una vez terminamos, cerramos el archivo
}

void Ruleta::leeJugadores(){                                                                //*esta función nos permitirá leer los jugadores existentes en el fichero*/
    jugadores_.empty();                                                                         //vaciamos la lista que ya teniamos para reutilizarla
    fstream f;
    f.open("jugadores.txt",ios::in);                                                            //abrimos el fichero donde tenemos los jugadores para pasarlos a la lista de jugadores

    char dni[255], codigo[255], nombre[255], apellidos[255];                                    //declaramos la variables que vamos a leer del fichero con una longitud máxima de una línea (255 caractéres)
    char direccion[255], localidad[255], provincia[255], pais[255], dinero[255];

    while(f.getline(dni, 255, ',')){                                                            //si podemos leer el dni, que es el primer dato, tendremos que seguir leyendo los datos de ese jugador hasta que ya no leamos ningún dni
        f.getline(codigo, 255, ',');                                                            //vamos leyendo los datos del jugador y lo vamos guardando en las variables anteriores con una longitud máxima de una línea (255 caractéres) y leemos hasta la coma que utilizaremos como separador de campos
        f.getline(nombre, 255, ',');
        f.getline(apellidos, 255, ',');
        f.getline(direccion, 255, ',');
        f.getline(localidad, 255, ',');
        f.getline(provincia, 255, ',');
        f.getline(pais, 255, ',');
        f.getline(dinero, 255, '\n');

        Jugador aux (dni, codigo, nombre, apellidos, 0, direccion, localidad, provincia, pais); //creamos un objeto de la clase jugador con los datos anteriores
        aux.setDinero(atoi(dinero));                                                            //le ponemos el dinero que tiene a ese jugador, leído del archivo von la función de setDinero pasando el string leido a int
        jugadores_.push_back(aux);                                                              //añadimos dicho jugador auxiliar a la cola de la lista de jugadores
    }
    f.close();                                                                                  //cerramos el archivo una vez hayamos terminado de leer todos los jugadores
}

void Ruleta::getPremios(){                                                                  //*esta función nos permitirá obtener los premios de las apuestas de los jugadores*/
    for(list <Jugador>::iterator i=jugadores_.begin(); i!=jugadores_.end(); i++){               //recorremos la lista de jugadores
        i->setApuestas();                                                                       //leemos las apuestas del jugador
        list <Apuesta> aux = i->getApuestas();                                                  //devolvemos una lista con las apuestas del jugador
        for(auto j=aux.begin(); j!=aux.end(); j++){                                             //recorremos la lista de apuestas
            Apuesta apuesta = *j;                                                               //creamos un objeto de la clase apuestas para ver las caracteristicas de esa apuesta
            switch(apuesta.tipo){                                                               //dependiendo del tipo de apuesta
                case 1:
                    if(bola_ == stoi(apuesta.valor)){                                           //si la bola coincide con el valor de la bola el jugador gana y la banca pierde
                        setBanca(getBanca() - 35*apuesta.cantidad);
                        i->setDinero(i->getDinero() + (apuesta.cantidad *35));
                        ganancia_-=35*apuesta.cantidad;                                         //tendremos en cuenta la ganancia de la banca (PERTENECE A LA PRÁCTICA 4)
                    }
                    else{                                                                       //sino es al contrario, la banca gana lo que el jugador pierde
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                break;

                case 2:                                                                         //lo mismo pasaría con los demás tipos de apuestas
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                    else if((apuesta.valor=="rojo" && esRojo(bola_)) || (apuesta.valor=="negro" && !esRojo(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                        ganancia_-=apuesta.cantidad;
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                break;

                case 3:
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                    else if((apuesta.valor=="par" && esPar(bola_)) || (apuesta.valor=="impar" && !esPar(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                        ganancia_-=apuesta.cantidad;
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                break;

                case 4:
                    if(bola_ == 0){
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                    else if((apuesta.valor=="alto" && esAlto(bola_)) || (apuesta.valor=="bajo" && !esAlto(bola_))){
                        setBanca(getBanca() - apuesta.cantidad);
                        i->setDinero(i->getDinero() + apuesta.cantidad);
                        ganancia_-=apuesta.cantidad;
                    }
                    else{
                        setBanca(getBanca() + apuesta.cantidad);
                        i->setDinero(i->getDinero() - apuesta.cantidad);
                        ganancia_+=apuesta.cantidad;
                    }
                break;
            }
        }
    }
}

void Ruleta::getEstadoRuleta(int &njugadores, int &dinero, int &lanzamientos, int &ganancia){       //*esta función nos permitirá obtener los datos de la ruleta en un tiempo determinado  (PERTENECE A LA PRÁCTICA 4)*/
    njugadores=(int) jugadores_.size();                                                                 //guardamos el número de jugadores de la partida
    lanzamientos=lanzamientos_;                                                                         //guardamos el número de lanzamientos de la bola
    dinero=banca_;                                                                                      //guardamos el dinero de la banca
    for(auto i=jugadores_.begin(); i!=jugadores_.end(); i++){                                           //recorremos la lista de jugadores para ver el dinero que han apostado para saber el dinero toal que hay sobre la mesa
        dinero+=i->getDinero();
    }
    ganancia=ganancia_;                                                                                 //guardamos la ganancia de la banca
}

/*FUNCIONES AUXILIARES CREADAS POR MÍ*/
bool Ruleta::esRojo(int const &valor){                                                              //*Esta función nos permitirá saber si la bola es roja o negra*/
    int rojo[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};                 //si esta en alguno de esos valores, la bola será roja, sino, la bola será negra
    for(int i=0; i<18; i++){
        if(valor==rojo[i]){                                                                             //comprobamos si la bola vale alguno de esos valores
            return true;
        }
    }
    return false;
}

bool Ruleta::esPar(int const &valor){                                                               //*Esta función nos permitirá saber si la bola es par o impar*/
    if(valor%2==0){                                                                                     //si el cociente de la división del valor entre 2 es cero significa que es par, sino, es impar
        return true;
    }
    return false;
}

bool Ruleta::esAlto(int const &valor){                                                              //*Esta función nos permitirá saber si la bola tiene un valor alto o no*/
    if(valor>=1 && valor<=18){                                                                          //si esta entre el 1 y el 18 el valor es bajo, sino el valor es alto
        return false;
    }
    return true;
}