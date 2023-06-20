#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

const int N = 720;
#define MIEMBRO   1
#define NO_MIEMBRO 0

class Deposito {
private:
    int** matriz;

public:
    Deposito() {
        matriz = new int*[N];
        for (int i = 0; i < N; i++) {
            matriz[i] = new int[N];
        }
    }

    ~Deposito() {
        for (int i = 0; i < N; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    void cargarMatrizDesdeArchivo(const std::string& archivo) {
        std::ifstream archivoEntrada(archivo);
        std::string linea;

        int fila = 0;
        while (getline(archivoEntrada, linea) && fila < N) {
            std::stringstream ss(linea);
            std::string valor;

            int columna = 0;
            while (getline(ss, valor, ',') && columna < N) {
                matriz[fila][columna] = std::stoi(valor);
                columna++;
            }

            fila++;
        }

        archivoEntrada.close();
    }

    int distancia(int s, int t) {
        int* pdist;
        int P[N];
        pdist = dijkstra(s, t, P);
        int distanciaMinima = pdist[t];
        camino(P,s,t);
        return distanciaMinima;
    }

private:
    int* dijkstra(int s, int t, int Pre[]) {
        static int D[N];
        int S[N];
        int actual, i, k, b;
        int menordist, nuevadist;
        int contador = 0;

        for (i = 0; i < N; i++) {
            S[i] = NO_MIEMBRO;
            D[i] = 9000;
            Pre[i] = -1;
        }

        S[s] = MIEMBRO;
        D[s] = 0;
        actual = s;
        b = 1;
        k = 0;

        while ((actual != t) && (b == 1)) {
            b = 0;
            menordist = 9000;

            for (i = 0; i < N; i++) {
                if (S[i] == NO_MIEMBRO) {
                    nuevadist = D[actual] + matriz[actual][i];

                    if (nuevadist < D[i]) {
                        D[i] = nuevadist;
                        Pre[i] = actual;
                        b = 1;
                    }

                    if (D[i] < menordist) {
                        menordist = D[i];
                        k = i;
                        b = 1;
                    }
                }
            }

            actual = k;
            S[actual] = MIEMBRO;

            contador = contador + 1;
            //std::cout << "iteracion: " << contador << std::endl;
        }

        return D;
    }


void camino(int P[], int s, int t)
{  if (t==s) cout<< s<<"  ";
   else{
        camino(P,s,P[t]);
        cout<<t<<"  ";
   }
}

};