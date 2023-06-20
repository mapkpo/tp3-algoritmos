#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "deposito.hpp"
#include "lista.hpp"

using namespace std;
int main() {
    Deposito deposito;
    deposito.cargarMatrizDesdeArchivo("adyacencia.csv");

    int distanciaMinima = deposito.distancia( 152 , 152 );
    cout<<distanciaMinima<<endl;

    Lista<int> nueva;

   nueva.add(58);
   nueva.add(20);
   nueva.add(1);
   nueva.add(58);
   nueva.add(548);
   nueva.add(700);
   nueva.ordenarBurbuja();
    cout<<nueva.toPrint()<<endl;
  


    return 0;
}





