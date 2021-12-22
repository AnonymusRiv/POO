#ifndef CONTADOR_H
#define CONTADOR_H

#include <list>

using namespace std;

class Contador{                                                                     //*creamos la clase contador
    private:                                                                            //!clase privada de la clase contador
        int valor_;                                                                     //número entero que guarda el valor
        int min_;                                                                       //número entero que guarda el valor mínimo
        int max_;                                                                       //número entero que guarda el valor máximo
        list <Contador> lista_;                                                         //lista de tipo contador que tendrá los valores anteriores

        void controlValor();                                                            //esta función nos permitirá controlal el valor que toma

    public:                                                                             //!clase pública de la clase contador
        Contador(int valor=0, int min=0, int max=1000);                                 //constructor de la clase contador que recibirá los tres parámetros

        Contador operator = (const int &n);                                             //esta función nos permitirá asignar un entero al contador
        Contador operator = (const Contador &contador);                                 //esta función nos permitirá asignar un contador al contador

        Contador operator ++ (void);                                                    //esta función nos permitirá devolver un contador antes de ser aumentado
        Contador operator ++ (int);                                                     //esta función nos permitirá devolver un contador después de ser aumentado

        Contador operator -- (void);                                                    //esta función nos permitirá devolver un contador antes de ser disminuido
        Contador operator -- (int);                                                     //esta función nos permitirá devolver un contador despues de ser disminuido

        Contador operator + (const int &n);                                             //esta función nos permitirá devolver un contador con la suma de n más el contador
        friend Contador operator + (const int &n, const Contador &contador);            //esta función nos permitirá devolver un contador con la suma de un contador más n

        Contador operator - (const int &n);                                             //esta función nos permitirá devolver un contador con la resta de n menos el contador
        friend Contador operator - (const int &n, const Contador &contador);            //esta función nos permitirá devolver un contador con la resta de un contador menos n

        bool undo(const int &n=1);                                                      //esta función nos permitirá deshacer los n últimos cambios

        inline int get() const {return valor_;}                                         //esta función inline nos permitirá devolver el valor actual del contador
};

#endif