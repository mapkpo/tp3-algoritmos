#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

template <class T>
class Nodo {
private:
    T dato;
    Nodo* next;

public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};

template <class T>
class Lista {
private:
    Nodo<T>* czo;

public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
    //resto= lo que queda de la lista sin la cabeza
    string toPrint();
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last(); //borra el ultimo
    void ordenarBurbuja();
};

template <class T> void Lista<T>::add(T d)
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
    this->ordenarBurbuja();
}

template <class T> bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}

template <class T> T Lista<T>::cabeza(void)
{
    if (this->esvacia()) {
        cout << " Error, Cabeza de lista vacia";
        return 0;
    }
    return czo->get_dato();
}

template <class T> Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}

template <class T> string Lista<T>::toPrint()
{
    if (this->esvacia()) {
        return "";
    }
    else {
        ostringstream stm;
        stm << this->cabeza() << " " << this->resto()->toPrint();
        return stm.str();
    }
}

template <class T> int Lista<T>::size()
{
    if (this->esvacia())
        return 0;
    return 1 + this->resto()->size();
}

template <class T> void Lista<T>::borrar(void)
{ //borra el nodo cabeza
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

template <class T> void Lista<T>::borrar_last()
{ // borra el ultimo nodo
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else
            this->resto()->borrar_last();
    }
}

template <class T> void Lista<T>::ordenarBurbuja()
{
    int n = this->size();
    if (n <= 1)
        return;

    bool intercambio;
    do {
        intercambio = false;
        Nodo<T>* actual = czo;
        Nodo<T>* siguiente = actual->get_next();

        for (int i = 0; i < n - 1; i++) {
            if (actual->get_dato() > siguiente->get_dato()) {
                T temp = actual->get_dato();
                actual->set_dato(siguiente->get_dato());
                siguiente->set_dato(temp);
                intercambio = true;
            }

            actual = siguiente;
            siguiente = siguiente->get_next();
        }
    } while (intercambio);
}