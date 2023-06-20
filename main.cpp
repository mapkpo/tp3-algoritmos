#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "robot.hpp"

using namespace std;
int main() {

    robot robot("adyacencia.csv");

    //p,e,m,c    p={1,2,3}   e={1 al 15} m={1 al 16}   c es la cantidad de ese producto a agregar
    
    robot.agregarProducto(1,1,2,2);          
    robot.agregarProducto(3,9,8,5);
    robot.agregarProducto(2,1,4,8);
    robot.agregarProducto(1,6,1,1);
    robot.agregarProducto(3,12,16,5);
    robot.agregarProducto(2,15,16,12);
    robot.agregarProducto(2,4,16,9);
    robot.agregarProducto(1,2,16,8);
    robot.agregarProducto(3,3,16,4);
    robot.agregarProducto(2,11,14,4);

    robot.realizarPedido();

    system("pause"); 


}


/*uso una matriz de 720 nodos para representar los 24 estantes de 30 lugares, 15 por cada lado entonces 24*30=720 nodos.
al ser tan grande su matriz de adyacencia no es posible cargarla en el stack asi que debe ser cargada en el heap desde un
archico csv que la contiene.
se hace uso de otra matriz de direcciones para obtener los numeros de nodos segun su fila y columna en los estantes esta si
esta implementada en el stack ya que es pequeña. tambien se implementa una lista que es la que guarda los productos.*/



