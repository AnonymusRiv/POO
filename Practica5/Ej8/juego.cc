#include <iostream>
#include <cstdio>
#include "dados.h"

int main(){
    using namespace std;                                                                    //lo utilizamos para no poner todo el rato std::cout...
    Dados d;                                                                                //se crea un objeto de la clase dados
    int opcion=0;                                                                           //creamos una variable que guarde la opción de lo que queramos hacer de las distintas posibilidades que tenemos
    while(opcion!=12){                                                                      //hacemos un bucle con las distintas posibilidades que podemos hacer en el sistema que se ejecutará siempre y cuando no se introduzca un 10 que es la opción para salir del programa

        cout<<endl;
        cout<<"Seleccione una opción:"<<endl;                                               //se mostrará todas las opciones que puede realizar el usuario en el programa
        cout<<"1. Mostrar el valor de los dados"<<endl;
        cout<<"2. Lanzar dados"<<endl;
        cout<<"3. Mostrar la media de los dados"<<endl;
        cout<<"4. Modificar el valor del primer dado"<<endl;
        cout<<"5. Modificar el valor del segundo dado"<<endl;
        cout<<"6. Mostrar la suma de los dados"<<endl;
        cout<<"7. Mostrar la diferencia de los dados"<<endl;
        cout<<"8. Mostrar cuantas veces se han lanzado los dados"<<endl;
        cout<<"9. Mostrar los ultimos 5 valores de ambos dados"<<endl;
        cout<<"10. Insertador"<<endl;
        cout<<"11. Extractor"<<endl;
        cout<<"12. Salir"<<endl;

        cout<<endl;
        cin>>opcion;                                                                          //el usuario introduce la opción que desee realizar
        cout<<endl;

        switch(opcion){                                                                       //creamos un switch con todas las opciones disponibles que podemos hacer
            case 1:                                                                           //en caso de que sea 1, mostramos los valores de los dados con las funciones getDado1 y getDado2 del objeto creado de dicha clase d
                cout<<"El valor del dado 1 es: "<<d.getDado1()<<endl;
                cout<<"El valor del dado 2 es: "<<d.getDado2()<<endl;
                break;

            case 2:                                                                           //en caso de que sea 2, lanzaremos ambos dados con la función lanzamiento de la clase de dados d, para obtener un nuevo valor en ambos dados
                d.lanzamiento();
                cout<<"Se han lanzado los dados correctamente"<<endl;
                break;

            case 3:                                                                           //en caso de que sea 3, calcularemos la media de ambos dados con la función getMedia1 y getMedia2 del objeto creado de dicha clase d
                cout<<"La media del dado 1 es: "<<d.getMedia1()<<endl;
                cout<<"La media del dado 2 es: "<<d.getMedia2()<<endl;
                break;

            case 4:                                                                           //en caso de que valga 4, modificaremos manualmente el valor del dado 1 introduciendolo y se asignará si es válido o nos dará un error si es incorrecto ese valor
                int a;
                cout<<"Introduzca el nuevo valor del primer dado: ";
                cin>>a;                                                                           //introducimos el valor que queremos asignar
                if (d.setDado1(a)==true){                                                         //si el return de la funcion setDado1 de la clase dados del objeto d es correcto significa que el valor es valido, por lo que se asignará dicho valor al dado 1
                    cout<<"Dado guardado correctamente \n";
                }
                else {                                                                            //el return es false, por lo que el valor introducido es erróneo, mostrando un mensaje de error y se quedará con el valor anterior que tenía el dado
                    cout<<"ERROR. No se ha podido guardar el dado \n";
                }
                break;

            case 5:                                                                           //en caso de que valga 5, modificaremos manualmente el valor del dado 2 introduciendolo y se asignará si es válido o nos dará un error si es incorrecto ese valor
                int b;
                cout<<"Introduzca el nuevo valor del segundo dado: ";
                cin>>b;                                                                           //introducimos el valor que queremos asignar
                if (d.setDado2(b)==true){                                                         //si el return de la funcion setDado2 de la clase dados del objeto d es correcto significa que el valor es valido, por lo que se asignará dicho valor al dado 2
                    cout<<"Dado guardado correctamente \n";
                }
                else {                                                                            //el return es false, por lo que el valor introducido es erróneo, mostrando un mensaje de error y se quedará con el valor anterior que tenía el dado
                    cout<<"ERROR. No se ha podido guardar el dado \n";
                }
                break;

            case 6:                                                                           //en caso de que valga 6, mostraremos la suma de ambos dados con la función getSuma de la clase dados del objeto de dicha clase d
                cout<<"El valor de la suma es "<<d.getSuma()<<"\n";
                break;

            case 7:                                                                           //en caso de que valga 7, mostraremos la diferencia de ambos dados con la función getDiferencia de la clase dados del objeto de dicha clase d
                cout<<"El valor de la diferencia es "<<d.getDiferencia()<<"\n";
                break;

            case 8:                                                                           //en caso de que valga 8, mostraremos el número de lanzamientos que lleva cada dado mediante la función getLanzamiento1 y getLanzamiento2 de la clase dados, ya sea por los propios lanzamientos o asignándoles nosotros el valor
                cout<<"El dado 1 se ha lanzado "<<d.getLanzamiento1()<<" veces \n";
                cout<<"El dado 2 se ha lanzado "<<d.getLanzamiento2()<<" veces \n";
                break;

            case 9:                                                                           //en caso de que valga 9, mostraremos los 5 ultimos valores de cada dado con la función getUltimos1 y getUltimos2 de la clase dados
                int v1[5];                                                                    //creamos un vector de 5 elementos donde escribiremos los ultimos 5 valores del dado 1
                int v2[5];                                                                    //creamos un vector de 5 elementos donde escribiremos los ultimos 5 valores del dado 2

                d.getUltimos1(v1);                                                            //llamamos a la funcion getUltimos1 y le pasamos el vector creado anteriormente v1 para guardar en dicho vector los ultimos 5 valores del dado 1
                d.getUltimos2(v2);                                                            //llamamos a la funcion getUltimos2 y le pasamos el vector creado anteriormente v2 para guardar en dicho vector los ultimos 5 valores del dado 2

                cout<<"Los ultimos 5 valores obtenidos para el dado 1 son: "<<endl;
                for (int i=0; i<5; i++){                                                      //imprimimos por pantalla los ultimos 5 valores del dado 1
                    cout<<v1[i]<<", ";
                }
                cout<<endl;

                cout<<"Los ultimos 5 valores obtenidos para el dado 2 son: "<<endl;
                for (int i=0; i<5; i++){                                                      //imprimimos por pantalla los ultimos 5 valores del dado 2
                    cout<<v2[i]<<", ";
                }
                cout<<endl;
                break;

            case 10:                                                                          //llamamos a la nueva función insertador recién creada para mostrar los valores de ambos dados
                d.insertador();
            break;

            case 11:                                                                          //llamamos a la nueva función extractor recién creada para insertar los valores de ambos dados
                d.extractor();
            break;

            case 12:                                                                          //en caso de que valga 10, el programa finaliza
                cout<<"Salida del programa"<<endl;
                break;

        }

    }
}