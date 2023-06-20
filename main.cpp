#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "robot.hpp"

using namespace std;
int main() {

    robot robot("adyacencia.csv");

    robot.agregarProducto(1,2,1,2);           //trio p,e,m,c    p={1,2,3}   e={1 al 15} m={1 al 16}   c es la cantidad de ese producto a agregar
    robot.agregarProducto(3,9,8,5);
    robot.agregarProducto(2,1,4,8);
    robot.agregarProducto(1,6,1,1);
    robot.agregarProducto(3,12,16,5);
    robot.agregarProducto(3,12,15,4);



  
    robot.realizarPedido();

    


    system("pause"); 

}





