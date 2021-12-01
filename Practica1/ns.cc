#include <iostream>

namespace n1{                                       //creamos un espacio de nombres con nombre n1 que tendrá dos variables
    int a;
    int b;
}

namespace n2{                                       //creamos un espacio de nombres con nombre n2 que tendrá dos variables
    int a;
    int b;
}

int main(){
    int a=55;                                       //le damos valor a las 3 a de los distintos namespace
    n1::a=0;
    n2::a=2;
    std::cout<< "n1::a= " << n1::a << "\n";         //imprimimos por pantalla el valor de la variable a del namespace n1
    std::cout<< "n2::a= " << n2::a << "\n";         //imprimimos por pantalla el valor de la variable a del namespace n2
    std::cout<< "a= " << a << "\n";                 //imprimimos por pantalla el valor de la variable a del la funcion main
}