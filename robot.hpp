#include <iostream>

#include "deposito.hpp"
#include "lista.hpp"

const int LLENO = 10;
using namespace std;
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

    void agregarProducto(int a){
        lista.add(a);
    }

    void realizarPedido(){
        int nodoActual = 0;
        int distanciaTotal = 0;

        while (!lista.esvacia()) {
            // Calcular el camino más corto desde el nodo actual al primer producto en la lista
            int producto = lista.cabeza();
            int distancia = deposito.distancia(nodoActual, producto);
            distanciaTotal += distancia;

            // Recorrer el camino más corto e ir actualizando el nodo actual
            cout << "Se recorrio desde el nodo " << nodoActual << " hasta el nodo " << producto << endl;
            cout << "Agregando el producto " << producto << endl;
            nodoActual = producto;

            // "Recoger" el producto (eliminarlo de la lista)
            lista.borrar();

            // Aumentar el volumen del robot
            aumentarVolumen();

            // Verificar si el volumen alcanzó su capacidad máxima
            if (volumenActual() == LLENO) {
                cout << "El robot esta lleno. Descargando productos..." << endl;
                descargarVolumen();
                nodoActual = 0;  // Volver al nodo cero después de vaciar el robot
            }
        }
        cout << "La distancia total recorrida fue: " << distanciaTotal << endl;

    }
};