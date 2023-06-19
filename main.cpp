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

    int s = 0;  // vertice de inicio
    int t = 584;  // vertice final

    int distanciaMinima = deposito.distancia(s, t);
    std::cout << distanciaMinima << std::endl;

    return 0;
}