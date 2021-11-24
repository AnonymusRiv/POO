#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    using namespace std;
    int num, sol=0;
    cout<<"Introduce un numero del 1 al 10 para adivinarlo posteriormente: ";
    cin>>num;
    srand(time(NULL));

    while(sol!=num){
        sol=rand()%10+1;
        if(sol<num){
            cout<<"El numero "<<sol<<" es menor que el numero introducido\n";
        }
        else if(sol>num){
            cout<<"El numero "<<sol<<" es mayor que el numero introducido\n";
        }
        else{
            cout<<"El numero "<<sol<<" es el numero introducido\n";
        }
    }
}