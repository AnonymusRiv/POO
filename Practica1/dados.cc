#include "dados.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


Dados::Dados(){                                             //*se inicializa el constructor con unos parámetros por defecto
    srand(time(NULL));                                          //se utiliza para inicializar la intrucción que nos permitirá poner los números aleatorios
    d1_=1;                                                      //es la variale que tendrá el valor que tendrá el dado 1
    d2_=1;                                                      //es la variable que tendrá el valor que tendrá el dado 2
    lanz1_=0;                                                   //es la variable que tendrá el número de lamzamientos del dado 1
    lanz2_=0;                                                   //es la variable que tendrá el número de lanzamientos del dado 2
    sum1_=0;                                                    //es la variable que tendrá el sumatorio de todos los valores que ha tomado el dado 1
    sum2_=0;                                                    //es la variable que tendrá el sumatorio de todos los valores que ha tomado el dado 2
}

void Dados::lanzamiento(){                                  //*función para el lanzamiento de los dados
    d1_=(rand()%6)+1;                                           //ponemos un valor aleatorio al dado 1 entre el 1 y el 6
    d2_=(rand()%6)+1;                                           //ponemos un valor aleatorio al dado 2 entre el 1 y el 6
    lanz1_++;                                                   //incrementamos en 1 la variable que nos indicará el número de lanzamientos del dado 1
    lanz2_++;                                                   //incrementamos en 1 la variable que nos indicará el número de lanzamientos del dado 2
    sum1_+=d1_;                                                 //sumamos el valor obtenido del lanzamiento al sumatorio de valores dej dado 1
    sum2_+=d2_;                                                 //sumamos el valor obtenido del lanzamiento al sumatorio de valores del dado 2

    for(int i=4; i>=0; i--){                                    //hacemos un bucle cambiar la posición de los 5 ultimos valores del dado 1 ya que tenemos que añadir el número que nos ha salido en el lanzamiento actual
        ultimos1[i]=ultimos1[i-1];                              //cambiamos el valor de la posición i al de i+1 y el primer valor que tuvimos (ultimos1[4]) no lo metemos
    }
    ultimos1[0]=d1_;                                            //ponemos en la primera posición del vector el último valor obtenido del dado 1

    for(int i=4; i>=0; i--){                                    //hacemos un bucle cambiar la posición de los 5 ultimos valores del dado 2 ya que tenemos que añadir el número que nos ha salido en el lanzamiento actual
        ultimos2[i]=ultimos2[i-1];                              //cambiamos el valor de la posición i al de i+1 y el primer valor que tuvimos (ultimos2[4]) no lo metemos
    }
    ultimos2[0]=d2_;                                            //ponemos en la primera posición del vector el último valor obtenido del dado 2
}

bool Dados::setDado1(const int &n){                         //*función para poner el valor que queramos al dado
    if(n>=1 && n<=6){                                           //comprobamos si el valor que queremos poner al dado 1 vale entre 1 y 6, ambos incluidos
        d1_=n;                                                  //le ponemos el valor introducido al dado 1
        lanz1_++;                                               //incrementamos en 1 la variable que nos indicará el número de lanzamientos del dado 1
        sum1_+=d1_;                                             //sumamos el valor obtenido del lanzamiento al sumatorio de valores del dado 1

        for(int i=4; i>=0; i--){                                //hacemos un bucle cambiar la posición de los 5 ultimos valores del dado 1 ya que tenemos que añadir el número que nos ha salido en el lanzamiento actual
            ultimos1[i]=ultimos1[i-1];                          //cambiamos el valor de la posición i al de i+1 y el primer valor que tuvimos (ultimos1[4]) no lo metemos
        }
        ultimos1[0]=d1_;                                        //ponemos en la primera posición del vector el último valor obtenido del dado 1
        return true;                                            //si se puede poner el valor al dado 1 se devolvera true
    }
    return false;                                               //en caso de que no se pueda se devolverá false
}

bool Dados::setDado2(const int &n){                         //*función para poner el valor que queramos al dado
    if(n>=1 && n<=6){                                           //comprobamos si el valor que queremos poner al dado 2 vale entre 1 y 6, ambos incluidos
        d2_=n;                                                  //le ponemos el valor introducido al dado 2
        lanz2_++;                                               //incrementamos en 1 la variable que nos indicará el número de lanzamientos del dado 2
        sum2_+=d2_;;                                             //sumamos el valor obtenido del lanzamiento al sumatorio de valores del dado 2

        for(int i=4; i>=0; i--){                                //hacemos un bucle cambiar la posición de los 5 ultimos valores del dado 2 ya que tenemos que añadir el número que nos ha salido en el lanzamiento actual
            ultimos2[i]=ultimos2[i-1];                          //cambiamos el valor de la posición i al de i+1 y el primer valor que tuvimos (ultimos1[4]) no lo metemos
        }
        ultimos2[0]=d2_;                                        //ponemos en la primera posición del vector el último valor obtenido del dado 2
        return true;                                            //si se puede poner el valor al dado 2 se devolvera true
    }
    return false;                                               //en caso de que no se pueda se devolverá false
}

float Dados::getMedia1()const{                              //*función para obtener la media del dado 1
    if(lanz1_==0){                                              //si los lanzamientos del dado 1 son iguales a cero, al no poder dividir entre cero, lo tenemos que indicar su resultado directamente
        return 0;                                               //el resultado de la media sería 0 ya que nos daría un error
    }
    return (float)sum1_/lanz1_;                                 //si los lanzamientos son distintos de cero, para calcular la media haremos la suma general entre el numero de lanzamientos y lo devolvemos
}

float Dados::getMedia2()const{                              //*función para obtener la media del dado 2
    if(lanz2_==0){                                              //si los lanzamientos del dado 1 son iguales a cero, al no poder dividir entre cero, lo tenemos que indicar su resultado directamente
        return 0;                                               //el resultado de la media sería 0 ya que nos daría un error
    }
    return (float)sum2_/lanz2_;                                 //si los lanzamientos son distintos de cero, para calcular la media haremos la suma general entre el numero de lanzamientos y lo devolvemos
}

void Dados::getUltimos1(int v[5]){                          //*función para obtener los últimos cinco valores del dado 1
    for(int i=0; i<5; i++){                                     //se recorre el vector que tiene los últimos valores del dado 1
        v[i]=ultimos1[i];                                       //se almacena en v los 5 valores últimos que ha tomado el dado
    }
}

void Dados::getUltimos2(int v[5]){                          //*función para obtener los últimos cinco valores del dado 2
    for(int i=0; i<5; i++){                                     //se recorre el vector que tiene los ultimos valores del dado 2
        v[i]=ultimos2[i];                                       //se almacena en v los 5 valores últimos que ha tomado el dado
    }
}