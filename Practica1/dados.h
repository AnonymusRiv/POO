#ifndef DADOS_H
#define DADOS_H
#include <cstdlib>


class Dados{                                                                //*creamos la clase dados
    private:                                                                    //!creamos la parte privada de la clase
        int d1_;                                                                //se le asigna un entero d1 que almacenará el valor del dado 1
        int d2_;                                                                //se le asigna un entero d2 que almacenará el valor del dado 2
        int lanz1_;                                                             //se le asigna un entero lanz1 que almacenará el número de lanzamientos del dado 1
        int lanz2_;                                                             //se le asigna un entero lanz2 que almacenará el número de lanzamientos del dado 2
        int sum1_;                                                              //se le asigna un entero sum1 que almacenará el sumatorio de todos los valores obtenidos del dado 1
        int sum2_;                                                              //se le asigna un entero sum2 que almacenará el sumatorio de todos los valores obtenidos del dado 2
        int ultimos1 [5] = {0,0,0,0,0};                                         //se le asigna un vector de enteros de 5 elementos que almacenará los últimos 5 valores del dado 1
        int ultimos2 [5] = {0,0,0,0,0};                                         //se le asigna un vectoe de enteros de 5 elementos que almacenará los últimos 5 valores del dado 2

    public:                                                                     //!creamos la parte pública de la clase
        Dados();                                                                //inicializamos el contructor de la clase dados

        inline int getDado1() const { return d1_;}                              //esta función inline nos permitirá devolver el valor del dado 1
        inline int getDado2() const { return d2_;}                              //esta función inline nos permitirá devolver el valor del dado 2

        bool setDado1(const int &n);                                            //esta función nos permitirá poner un valor al dado 1
        bool setDado2(const int &n);                                            //esta función nos permitirá poner un valor al dado 2

        inline int getSuma() const { return d1_ +d2_;}                          //esta función inline nos permitirá devolver la suma de los valores de ambos dados
        inline int getDiferencia() const { return (abs(d1_ - d2_));}            //esta función inline nos permitirá devolver la diferencia de los valores de ambos dados

        void lanzamiento();                                                     //esta función nos permitirá realizar el lanzamiento de los dados para tener un nuevo valor en ambos dados

        inline int getLanzamiento1() const { return lanz1_;}                    //esta función inline nos permitira devolver el número de lanzamientos del dado 1
        inline int getLanzamiento2() const { return lanz2_;}                    //esta función inline nos permitirá devolver el número de lanzamientos del dado 2

        float getMedia1() const;                                                //esta función nos permitirá obtener el valor medio de todos los valores obtenidos del dado 1
        float getMedia2() const;                                                //esta función nos permitirá obtener el valor medio de todos los valores obtenidos del dado 2

        void getUltimos1(int v[]);                                              //esta función nos permitirá obtener el valor de los últimos 5 lanzamientos del dado 1
        void getUltimos2(int v[]);                                              //esta función nos permitirá obtener el valor de los últimos 5 lanzamientos del dado 2
};

#endif