#include "contador.h"

Contador::Contador(int valor, int min, int max){                //*constructor de la clase contador que recibirá como parámetro los tres valores*/
    if(min>max || valor<min || valor>max){                          //comprobamos si los valores están mal introducidos para poner los valores por defecto
        valor=0;
        min=0;
        max=1000;
    }
    valor_=valor;                                                   //asignamos los valores a las variables de la clase
    min_=min;
    max_=max;
    lista_.push_back(*this);                                        //añadimos este cambio a la cola de la lista de contadores
}

void Contador::controlValor(){                                  //*esta función nos permitirá controlar el valor*/
    if(valor_>max_){                                                //si el valor es mayor que el máximo, el valor tomará ese valor
        valor_=max_;
    }
    else if(valor_<min_){                                           //si el valor es menor que el mínimo, el valor tomará ese valor
        valor_=min_;
    }
    lista_.push_back(*this);                                        //añadimos este cambio a la cola de la lista de contadores
}

Contador Contador::operator = (const int &n){                   //*esta función nos permitirá asignar un entero al contador*/
    valor_=n;                                                       //asignamos n al valor
    controlValor();                                                 //vemos si el valor esta bien
    return *this;                                                   //devolvemos este contador
}

Contador Contador::operator = (const Contador &contador){       //*esta función nos permitirá asignar un contador al contador*/
    valor_=contador.valor_;                                         //asignamos el valor de contador a este contador
    min_=contador.min_;                                             //asignamos el minimo de contador a este contador
    max_=contador.max_;                                             //asignamos el maximo de contador a este contador
    controlValor();
    return *this;
}

Contador Contador::operator ++ (void){                          //*esta función nos permitirá devolver un contador antes de ser aumentado*/
    ++valor_;                                                       //Aumentamos el valor del contador
    controlValor();
    return *this;
}

Contador Contador::operator ++ (int){                           //*esta función nos permitirá devolver un contador después de ser aumentado*/
    Contador aux = *this;                                           //creamos un contador auxiliar que sea este
    ++valor_;                                                       //aumentamos el valor del contador
    controlValor();
    return aux;                                                     //devolvemos el valor del contador sin aumentar
}

Contador Contador::operator -- (void){                          //*esta función nos permitirá devolver un contador antes de ser disminuido*/
    --valor_;                                                       //decrementamos el valor del contador
    controlValor();
    return *this;
}

Contador Contador::operator -- (int){                           //*esta función nos permitirá devolver un contador despues de ser disminuido*/
    Contador aux = *this;
    --valor_;                                                       //disminuimos el valor del contador
    controlValor();
    return aux;                                                     //devolvemos el valor del contador sin disminuir
}

Contador Contador::operator + (const int &n){                   //*esta función nos permitirá devolver un contador con la suma de n más el contador*/
    valor_ = valor_ + n;                                            //sumamos valor del contador más n
    controlValor();
    return *this;
}

Contador operator + (const int &n, const Contador &contador){       //*esta función nos permitirá devolver un contador con la suma de un contador más n*/
    Contador aux;
    aux.valor_ = n + contador.valor_;                                   //sumamos n más valor del contador y lo asignamos al contador aux
    aux.max_ = contador.max_;                                           //asignamos el maximo de contador al contador aux
    aux.min_ = contador.min_;                                           //asignamos el minimo de contadoe al contador aux
    aux.controlValor();
    return aux;                                                         //devolvemos el valor del contador sin modificar
}

Contador Contador::operator-(const int &n){                     //*esta función nos permitirá devolver un contador con la resta de n menos el contador*/
    valor_ = valor_ - n;                                            //restamos valor del contador menos n
    controlValor();
    return *this;
}

Contador operator - (const int &n, const Contador &contador){       //*esta función nos permitirá devolver un contador con la resta de un contador menos n*/
    Contador aux;
    aux.valor_ = n - contador.valor_;                                   //restamos n menos valor del contador c y lo asignamos al contador aux
    aux.max_ = contador.max_;                                           //asignamos el maximo de contador al contador aux
    aux.min_ = contador.min_;                                           //asignamos el minimo de contador al contador aux
    aux.controlValor();
    return aux;
}

bool Contador::undo(const int &n){                              //*esta función nos permitirá deshacer los n últimos cambios*/
    if (n>= (int)lista_.size() || n<1){                             //si n es mayor que el total de cambios, o menor que uno, devolvemos false
        return false;
    }
    for(int i=0; i<n; i++){                                         //borramos de la lista los ultimos n elementos
        lista_.pop_back();
    }
    *this = lista_.back();                                          //guardamos en el contador el ultimo valor de la lista
    return true;
}