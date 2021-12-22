#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int tam;

    cout << "Introduce el tamaño del vector: " ;                                //introducimos el tamaño que queremos que tenga el vector
    cin >> tam;

    vector <int> v(tam);                                                        //creamos el vector de dicho tamaño

    cout << "\nIntroducir datos al vector de tipo int \n";                      //introducimos los valores al vector

    for (int i=0 ; i<v.size() ; i++) {
        cout << "Introduce un valor para la posición "<<i<<" del vector: ";
        cin >> v[i];
    }

    sort(v.begin(), v.end());                                                   //ordenamos mediante la función sort

    cout << endl;
    cout << "El vector ordenado se quedaría" << endl;                           //imprimimos el vector ordenado
    for (vector<int>::size_type i = 0; i != v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}