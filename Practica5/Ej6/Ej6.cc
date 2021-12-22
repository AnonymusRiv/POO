#include <iostream>

using namespace std;

template <class tipo>

void imprimirVector(tipo v[], const int t){         //función para imprimir el vector
    for(int i=0; i<t; i++) cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int a[8]={3, 6, 34, 1, 0, -1, 4, 8};            //creamos un vector de tipo int
    float b[5]={1.12, 9.678, 3.1, 0.5, 4.69};       //creamos un vector de tipo float
    char c[11]="Hola Mundo";                        //creamos un vector de tipo char

    cout<<"Vector de números enteros"<<endl;        //imprimimos el vector con la misma función sea del tipo que sea
    imprimirVector(a,8);

    cout<<"\nVector números flotantes"<<endl;
    imprimirVector(b,5);

    cout<<"\nVector de char"<<endl;
    imprimirVector(c,11);

    return 0;

}