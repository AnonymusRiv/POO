#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    using namespace std;                                                            //para no tener que escribir todo el rato std::cout..., lo declaro aqui
    int num, sol=0;
    cout<<"Introduce un numero del 1 al 10 para adivinarlo posteriormente: ";
    cin>>num;                                                                       //introducimos el número que queremos que adivine el programa
    srand(time(NULL));                                                              //inicializamos el srand para la obtención de numeros aleatorios

    while(sol!=num){                                                                //hacemos un bucle que se ejecute cada vez que el numero obtenido sea distinto al numero de la solución que es el que queremos averiguar
        sol=rand()%10+1;                                                            //generamos un número aleatorio del 0 al 10
        if(sol<num){                                                                //si el número obtenido es mas chico que el que tenemos que buscar, imprimimos por pantalla que el número obtemido aleatoriamente es menor
            cout<<"El numero "<<sol<<" es menor que el numero introducido\n";
        }
        else if(sol>num){                                                           //si el número obtenido es mas grande que el que tenemos que buscar, imprimimos por pantalla que el número obtenido aleatoriamente es mayor
            cout<<"El numero "<<sol<<" es mayor que el numero introducido\n";
        }
        else{                                                                       //si el número obtenido es el número que tenemos que buscar, imprimimos por pantalla que ese es el número que el usuario ha introducido
            cout<<"El numero "<<sol<<" es el numero introducido\n";
        }
    }
}