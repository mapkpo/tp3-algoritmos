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

    nueva.add(25);
    nueva.add(80);
    nueva.add(25);
    nueva.add(99);
    nueva.add(25);
    cout<<nueva.toPrint()<<endl;
    nueva.ordenamientoInsercion();
    //cout<<nueva.size()<<endl;
    cout<<nueva.toPrint()<<endl;

    return 0;
}





