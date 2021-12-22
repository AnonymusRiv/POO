#include <iostream>

#include "jugador.h"
#include "crupier.h"
#include "ruleta.h"

using namespace std;

int main(){
    system("clear");
    string dni;
    string codigo;
    string cadena;                                          //se crea una variable cadena que leera los datos introducidos
    Crupier crupier(dni, codigo);                           //se crea un objeto de la clase crupier con valores basura para sobreescribirlos después
    Ruleta ruleta(crupier);                                 //se crea un objeto de la clase ruleta con el crupier anterior
    Jugador jugador(dni, codigo);                           //se crea un objeto de la clase jugador con valores basura para sobreescribirlos después

    int njugadores,dinero, lanzamientos, ganancias;         //PERTENECE A LA PRÁCTICA 4
    list <Jugador> aux;                                     //creamos una lista de jugadores (PERTENECE A LA PRÁCTICA 4)
    int respuesta;
    bool res;

    cout<<"Introduzca el dni del crupier: ";
    cin>>cadena;                                            //introduciremos los datos pedidos para rellenar el objeto de la clase crupier
    crupier.setDNI(cadena);                                 //llamaremos a las distintas clases set para asignar dicha variable al objeto en cuestion
    cout<<"Introduzca el codigo del crupier: ";
    cin>>cadena;
    crupier.setCodigo(cadena);

    int opcion=0;

    while(opcion!=7){
        cout<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"\t\tInserte la opción a elegir"<<endl;
        cout<<"\t1. Cargar los jugadores del fichero"<<endl;
        cout<<"\t2. Guardar los jugadores en el fichero"<<endl;
        cout<<"\t3. Ver el estado de la ruleta"<<endl;
        cout<<"\t4. Girar ruleta"<<endl;
        cout<<"\t5. Eliminar jugador de la mesa"<<endl;
        cout<<"\t6. Añadir jugador a la mesa"<<endl;
        cout<<"\t7. Salir"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cin>>opcion;
        switch(opcion){                                                                                         //en función de la opción introducida haremos una acción u otra
            case 1:                                                                                             //para cargar los jugadores lo que hacemos es leer los jugadores del fichero mediante la clase ruleta
                ruleta.leeJugadores();
                cout<<"Jugadores cargados correctamente"<<endl;
            break;
            case 2:                                                                                             //para guardar los jugadores lo que hacemos es escribir los jugadores del fichero mediante la clase ruleta
                ruleta.escribeJugadores();
                cout<<"Jugadores guardados correctamente"<<endl;
            break;
            case 3:                                                                                             //para obtener el estado de la ruleta lo que hacemos es leer los valores mediante la clase ruleta e imprimirlos por pantalla
                ruleta.getEstadoRuleta(njugadores, dinero, lanzamientos, ganancias);
                cout<<"Estado de la ruleta:"<<endl;
                cout<<"Número de jugadores: "<<njugadores<<endl;
                cout<<"Dinero en la mesa: "<<dinero<<endl;
                cout<<"Número de lanzamientos: "<<lanzamientos<<endl;
                cout<<"Ganancia de la banca: "<<ganancias<<endl;
            break;
            case 4:                                                                                             //para girar la ruleta, llamamos a la función de giraRuleta y además mostramos los premios de cada jugador de la partida y mostramos el dinero de la banca
                ruleta.giraRuleta();
                cout<<"El valor de la bola es "<<ruleta.getBola()<<endl;                                        //obtenemos el valor de la bola
                ruleta.getPremios();                                                                            //obtenemos los premios de esta jugada
                aux=ruleta.getJugadores();                                                                      //cargamos la lista de jugadores de la partida
                for(auto i=aux.begin(); i!=aux.end(); i++){                                                     //recorremos dicha lista para mostrar el dinero actual de cada jugador
                    cout<<"El jugador con dni "<<i->getDNI()<<" tiene actualmente "<<i->getDinero()<<endl;
                }
                cout<<"\nLa banca tiene "<<ruleta.getBanca()<<endl;                                             //mostramos el dinero que tiene la banca
            break;
            case 5:                                                                                             //para eliminar un jugador de la partida, indicamos su dni y lo buscamos mediante la función deleteJugador pasándole dicho dni
                cout<<"Inserte el dni de la persona a eliminar: ";
                cin>>dni;
                respuesta=ruleta.deleteJugador(dni);
                if(respuesta==1){                                                                               //si devuelve 1 significa que se ha eliminado correctamente el jugador
                    cout<<"Jugador eliminado correctamente"<<endl;
                }
                else if(respuesta==-1){                                                                         //si devuelve -1 significa que la lista está vacia, por lo que no se va a poder eliminar
                    cout<<"Imposible encontrar la lista, ya que esta está vacia"<<endl;
                }
                else{                                                                                           //si no devuelve nada de esto (devuelve un -2) significa que dicho dni no se encuentra en la lista
                    cout<<"Jugador no encontrado en la lista"<<endl;
                }
            break;
            case 6:                                                                                             //para añadir un nuevo jugador a la mesa tendremos que introducir su dni y su código
                cout<<"Introduzca el dni del jugador: ";
                cin>>cadena;                                                                                    //introduciremos los datos pedidos para rellenar el objeto de la clase jugador
                jugador.setDNI(cadena);                                                                         //llamaremos a las distintas clases set para asignar dicha variable al objeto en cuestion
                cout<<"Introduzca el codigo del jugador: ";
                cin>>cadena;
                jugador.setCodigo(cadena);
                res=ruleta.addJugador(jugador);                                                                 //llamamos a la función que nos añade dicho jugador
                if(res==false){                                                                                 //si dicha función devuelve false significa que el jugador ya está en la lista de jugadores
                    cout<<"El jugador ya se encuentra en el juego"<<endl;
                }
                else{                                                                                           //si el jugador no existe, se añade a la cola de los jugadores actuales
                    cout<<"Jugador añadido correctamente"<<endl;
                }
            break;
            case 7:                                                                                             //salimos del programa
                cout<<"Saliendo del programa..."<<endl;
            break;
            default:                                                                                            //si no se introduce ninguno de estos valores muestra un mensaje de error
                cout<<"Introduzca una opción valida entre 1 y 7"<<endl;
            break;
        }
    }
}