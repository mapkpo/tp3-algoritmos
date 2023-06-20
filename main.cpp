#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "robot.hpp"

using namespace std;
int main() {

    robot robot("adyacencia.csv");

    robot.agregarProducto(501);
    robot.agregarProducto(5);
    robot.agregarProducto(5);
    robot.agregarProducto(702);
    robot.agregarProducto(250);
    robot.agregarProducto(251);
    robot.agregarProducto(252);
    robot.agregarProducto(253);
    robot.agregarProducto(254);
    robot.agregarProducto(255);
    robot.agregarProducto(256);
    robot.agregarProducto(257);
    robot.agregarProducto(258);
    robot.agregarProducto(259);
    robot.agregarProducto(260);
    robot.agregarProducto(254);
  
    robot.realizarPedido();


    system("pause");

}





