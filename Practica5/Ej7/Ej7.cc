#include <iostream>

using namespace std;

template <class tipo>                                   //indicamos que tipo va a ser del tipo que introduzcamos

class MiClase{                                          //creamos la clase
    private:
        tipo x_;                                        //le asignamos dos variables de clase tipo
        tipo y_;
    public:
        MiClase (tipo a, tipo b){ x_=a; y_=b;};         //constructor de la clase que recibe dos valores y los asigna a sus variables privadas
        tipo div(){return x_/y_;};
};

int main(){
    MiClase <int> a(8,7);                               //creamos un objeto de tipo int de la clase MiClase
    MiClase <double> b(9.1, 1.22);                      //creamos un objeto de tipo double de la clase MiClase

    cout << "division entera = " << a.div() << endl;    //calculamos la división entera y real de ambos números
    cout << "division real = " << b.div() << endl;
}