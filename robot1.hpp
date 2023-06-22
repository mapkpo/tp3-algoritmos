#include <iostream>

#include "deposito1.hpp"
#include "lista.hpp"

const int LLENO = 10;
using namespace std;

/*
La clase robot representa el robot utilizado en el depósito para realizar tareas de recogida de productos. 
Esta clase proporciona métodos para controlar el volumen del robot, agregar productos a una lista de productos 
y realizar pedidos.
*/
class robot{

private:
    int volumen;
    Deposito deposito;
    Lista<int> lista;

    void descargarVolumen(){
        volumen = 0;
    }

    void aumentarVolumen(){
        if(!isLleno()){
            volumen+=1;
        } else cout<<"robot lleno"<<endl;
    }
    
    bool isLleno(){
        if (volumen == LLENO){
            return true;
        }   
        else return false;
    }
    
    int volumenActual(){
        return volumen;
    }

public:
    robot(string archivo) {
        volumen = 0;
        deposito.cargarMatrizDesdeArchivo(archivo);
    }

/*
El metodo agregarProducto() agrega determinada mercaderia que se encuentra en el deposito en
la lista de pedidos a realizar por el robot.
Parámetros:
p = cual de las 3 filas de 8 estantes se encuentra el producto. p{1,2,3}.
e = distancia desde la base en la que se encuentra el producto dentro del estante.
m = es cual de las 2 columnas de los 8 estantes se encuentra el producto.
*/
    void agregarProducto(int p, int e, int m, int c){
        int temp = c;
        while(temp>0){
        lista.add(deposito.getDireccion(p,e,m));
        temp-=1;
        }
    }

/*
El metodo realizarPedido() entrega los productos que se solicitan en la lista de pedidos.
Mientras la lista de pedidos no este vacia, calcula y recorre la distancia minima entre el nodo actual y 
el nodo que contiene el proximo pedido, "entrega" el pedido y sigue con los demas pedidos.
Si el robot alcanza el volumen de carga maximo, despacha los pedidos y vuelve al nodo inicial 0.
*/
    void realizarPedido(){
        int nodoActual = 0;
        int distanciaTotal = 0;

        while (!lista.esvacia()) {
            // Calcular el camino más corto desde el nodo actual al primer producto en la lista
            int producto = lista.cabeza();
            int distancia = deposito.distancia(nodoActual, producto);
            distanciaTotal += distancia;

            // Recorrer el camino más corto e ir actualizando el nodo actual
            cout << "Se recorrio desde el nodo " << nodoActual+1 << " hasta el nodo " << producto+1 << endl;
            cout << "Agregando el producto " << producto+1 << endl;
            nodoActual = producto;

            // "Recoger" el producto (eliminarlo de la lista)
            lista.borrar();

            // Aumentar el volumen del robot
            aumentarVolumen();

            // Verificar si el volumen alcanzó su capacidad máxima
            if (volumenActual() == LLENO) {
                cout << "El robot esta lleno. Volviendo a inicio. Descargando productos y retornando" << endl;
                descargarVolumen();
                distanciaTotal += deposito.distancia(nodoActual, 0);
                nodoActual = 0;  // Volver al nodo cero después de vaciar el robot
            }            
        }
        distanciaTotal += deposito.distancia(nodoActual, 0);

        cout << "La distancia total recorrida fue: " << distanciaTotal << endl;

    }
};