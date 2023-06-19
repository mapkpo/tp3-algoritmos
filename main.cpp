#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "deposito.hpp"

using namespace std;
int main() {
    Deposito deposito;
    deposito.cargarMatrizDesdeArchivo("adyacencia.csv");

    

    int distanciaMinima = deposito.distancia(0, 152);
    cout<<distanciaMinima<<endl;

    return 0;
}