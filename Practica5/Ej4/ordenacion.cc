#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool wayToSort(int i, int j) { return i > j; }                                  //creamos una función para la ordenación de modo descendente

int main(){
    int tam;
    int opcion=0;

    cout << "Introduce el tamaño del vector: ";                                 //introducimos el tamaño del vector
    cin >> tam;

    vector <int> v(tam);                                                        //creamos un vector de dicho tamaño

    cout << "\nIntroducir datos al vector de tipo int \n";

    for (int i=0 ; i<v.size() ; i++) {                                          //añadimos los valores de dicho vector
        cout << "Introduce un valor para la posición "<<i<<" del vector: ";
        cin >> v[i];
    }

    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"\tInserte un método de ordenación"<<endl;                            //introducimos un método de ordenación
    cout<<"\t1. ascendente"<<endl;
    cout<<"\t2. descendente"<<endl;
    cout<<"-----------------------------------"<<endl;
    cin >> opcion;

    switch(opcion){
        case 1:                                                                 //ordenamos el vector de forma ascendente
            cout<<"Método de ordenación ascendente"<<endl;
            sort(v.begin(), v.end());                                           //se ordena el vector de forma ascendente

        break;
        case 2:                                                                 //ordenamos el vector de forma descendente
            cout<<"Método de ordenación descendente"<<endl;
            sort(v.begin(), v.end(), wayToSort);                                //se ordena de forma descendente
        break;
        default:                                                                //si introducimos una opción no válida imprimimos el mensaje del error
            cout<<"Inserte una opción valida"<<endl;
        break;
    }
    cout << endl;
    cout << "El vector ordenado se quedaría" << endl;                           //imprimimos el vector ordenado
    for (vector<int>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}