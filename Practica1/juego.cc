#include <iostream>
#include <cstdio>
#include "dados.h"

int main(){
    using namespace std;
    Dados d;
    int opcion=0;

    cout<<"Seleccione una opcion: "<<endl;

    while(opcion!=10){

        cout<<"----------------------------------------------------------"<<endl;
        cout<<"| Pulse una opción                                        |"<<endl;
        cout<<"| 1. Mostrar el valor de los dados                        |"<<endl;
        cout<<"| 2. Lanzar dados                                         |"<<endl;
        cout<<"| 3. Mostrar la media de los dados                        |"<<endl;
        cout<<"| 4. Modificar el valor del primer dado                   |"<<endl;
        cout<<"| 5. Modificar el valor del segundo dado                  |"<<endl;
        cout<<"| 6. Mostrar la suma de los dados                         |"<<endl;
        cout<<"| 7. Mostrar la diferencia de los dados                   |"<<endl;
        cout<<"| 8. Mostrar cuantas veces se han lanzado los dados       |"<<endl;
        cout<<"| 9. Mostrar los ultimos 5 valores de ambos dados         |"<<endl;
        cout<<"| 10. Salir                                               |"<<endl;
        cout<<"----------------------------------------------------------"<<endl;

        cin>>opcion;                                                                          //El usuario introduce la opción que desee
        cout<<"----------------------------------------------------------"<<endl;

        switch(opcion){
            case 1:
                cout<<"El valor del dado 1 es: "<<d.getDado1()<<endl;
                cout<<"El valor del dado 2 es: "<<d.getDado2()<<endl;
                break;

            case 2:
                d.lanzamiento();
                cout<<"Se han lanzado los dados correctamente"<<endl;
                break;

            case 3:
                cout<<"La media del dado 1 es: "<<d.getMedia1()<<endl;
                cout<<"La media del dado 2 es: "<<d.getMedia2()<<endl;
                break;

            case 4:
                int a;
                cout<<"Introduzca el nuevo valor del primer dado: ";
                cin>>a;                                                                 //Modificamos el dado 1
                if (d.setDado1(a)==true){
                    cout<<"Dado guardado correctamente \n";
                }
                else {
                    cout<<"ERROR. No se ha podido guardar el dado \n";
                }
                break;

            case 5:
                int b;
                cout<<"Introduzca el nuevo valor del segundo dado: ";
                cin>>b;                                                                //Modificamos el dado 2
                if (d.setDado2(b)==true){
                    cout<<"Dado guardado correctamente \n";
                }
                else {
                    cout<<"ERROR. No se ha podido guardar el dado \n";
                }
                break;

            case 6:
                cout<<"El valor de la suma es "<<d.getSuma()<<"\n";                        //Imprimimos el valor de la suma de ambos dados
                break;

            case 7:
                cout<<"El valor de la diferencia es "<<d.getDiferencia()<<"\n";            //Imprimimos el valor de la diferencia de ambos dados
                break;

            case 8:
                cout<<"El dado 1 se ha lanzado "<<d.getLanzamiento1()<<" veces \n";       //Imprimimos cuantas veces se ha lanzado el dado 1
                cout<<"El dado 2 se ha lanzado "<<d.getLanzamiento2()<<" veces \n";
                break;

            case 9:
                int v1[5];                                                                      //Creamos un vector donde copiaremos los ultimos 5 valores del dado 1  
                int v2[5];                                                                      //Creamos un vector donde copiaremos los ultimos 5 valores del dado 2

                d.getUltimos1(v1);                                                              //Llamamos a la funcion getUltimos1 y le pasamos v1 para que guarde ahi los ultimos 5 valores del dado 1
                d.getUltimos2(v2);                                                              //Llamamos a la funcion getUltimos2 y le pasamos v2 para que guarde ahi los ultimos 5 valores del dado 2

                cout<<"Los ultimos 5 valores obtenidos para el dado 1 son: "<<endl;   
                cout<<"|";
                for (int i=0; i<5; i++){                                                        //Imprimimos los ultimos 5 valores del dado 1
                    cout<<v1[i]<<"|";
                }
                cout<<endl;
                cout<<endl;

                cout<<"Los ultimos 5 valores obtenidos para el dado 2 son: "<<endl;   
                cout<<"|";
                for (int i=0; i<5; i++){                                                        //Imprimimos los ultimos 5 valores del dado 2
                    cout<<v2[i]<<"|";
                }
                cout<<endl;
                break;

            case 10:
                cout<<"Salida del ptograma"<<endl;
                break;

        }

    }
}