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
    int matrizDireccion[45][16]{0,45,90,135,180,225,270,315,360,405,450,495,540,585,630,675,    // Matriz de 3 filas con 
                                1,46,91,136,181,226,271,316,361,406,451,496,541,586,631,676,    // con 8 estantes cada fila.
                                2,47,92,137,182,227,272,317,362,407,452,497,542,587,632,677,    //3 estantes de 15mts=45
                                3,48,93,138,183,228,273,318,363,408,453,498,543,588,633,678,    //16 = 2 lados de los 8 estantes
                                4,49,94,139,184,229,274,319,364,409,454,499,544,589,634,679,    //
                                5,50,95,140,185,230,275,320,365,410,455,500,545,590,635,680,    //
                                6,51,96,141,186,231,276,321,366,411,456,501,546,591,636,681,
                                7,52,97,142,187,232,277,322,367,412,457,502,547,592,637,682,
                                8,53,98,143,188,233,278,323,368,413,458,503,548,593,638,683,
                                9,54,99,144,189,234,279,324,369,414,459,504,549,594,639,684,
                                10,55,100,145,190,235,280,325,370,415,460,505,550,595,640,685,
                                11,56,101,146,191,236,281,326,371,416,461,506,551,596,641,686,
                                12,57,102,147,192,237,282,327,372,417,462,507,552,597,642,687,
                                13,58,103,148,193,238,283,328,373,418,463,508,553,598,643,688,
                                14,59,104,149,194,239,284,329,374,419,464,509,554,599,644,689,
                                15,60,105,150,195,240,285,330,375,420,465,510,555,600,645,690,
                                16,61,106,151,196,241,286,331,376,421,466,511,556,601,646,691,
                                17,62,107,152,197,242,287,332,377,422,467,512,557,602,647,692,
                                18,63,108,153,198,243,288,333,378,423,468,513,558,603,648,693,
                                19,64,109,154,199,244,289,334,379,424,469,514,559,604,649,694,
                                20,65,110,155,200,245,290,335,380,425,470,515,560,605,650,695,
                                21,66,111,156,201,246,291,336,381,426,471,516,561,606,651,696,
                                22,67,112,157,202,247,292,337,382,427,472,517,562,607,652,697,
                                23,68,113,158,203,248,293,338,383,428,473,518,563,608,653,698,
                                24,69,114,159,204,249,294,339,384,429,474,519,564,609,654,699,
                                25,70,115,160,205,250,295,340,385,430,475,520,565,610,655,700,
                                26,71,116,161,206,251,296,341,386,431,476,521,566,611,656,701,
                                27,72,117,162,207,252,297,342,387,432,477,522,567,612,657,702,
                                28,73,118,163,208,253,298,343,388,433,478,523,568,613,658,703,
                                29,74,119,164,209,254,299,344,389,434,479,524,569,614,659,704,
                                30,75,120,165,210,255,300,345,390,435,480,525,570,615,660,705,
                                31,76,121,166,211,256,301,346,391,436,481,526,571,616,661,706,
                                32,77,122,167,212,257,302,347,392,437,482,527,572,617,662,707,
                                33,78,123,168,213,258,303,348,393,438,483,528,573,618,663,708,
                                34,79,124,169,214,259,304,349,394,439,484,529,574,619,664,709,
                                35,80,125,170,215,260,305,350,395,440,485,530,575,620,665,710,
                                36,81,126,171,216,261,306,351,396,441,486,531,576,621,666,711,
                                37,82,127,172,217,262,307,352,397,442,487,532,577,622,667,712,
                                38,83,128,173,218,263,308,353,398,443,488,533,578,623,668,713,
                                39,84,129,174,219,264,309,354,399,444,489,534,579,624,669,714,
                                40,85,130,175,220,265,310,355,400,445,490,535,580,625,670,715,
                                41,86,131,176,221,266,311,356,401,446,491,536,581,626,671,716,
                                42,87,132,177,222,267,312,357,402,447,492,537,582,627,672,717,
                                43,88,133,178,223,268,313,358,403,448,493,538,583,628,673,718,
                                44,89,134,179,224,269,314,359,404,449,494,539,584,629,674,719,};

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

/*
El metodo getDireccion() devuelve la dirección almacenada en la matriz de direcciones (matrizDireccion) para una posición (p, e, m) dada.
Parámetros:
p: representa cual de las 3 filas de 8 estantes es. p{1,2,3}
e: representa la altura desde la base del estante en donde esta la mercaderia.
m: representa cual de las 2 columnas de los 8 estantes es.
Valor de retorno: Entero que representa la dirección.
*/
    int getDireccion(int p, int e, int m){
        return matrizDireccion[15*(p-1)+(e-1)][(m-1)];
    }

/*
El metodo cargarMatrizDesdeArchivo() almacena en la matriz los datos almacenados en un archivo de texto.
Parámetros: 
archivo: archivo de texto que contiene los datos a almacenar en la matriz.
*/
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

/*
El metodo distancia() calcula y devuelve la distancia mínima entre dos puntos en la matriz usando el algoritmo de Dijkstra.
Parámetros:
s: Entero que representa el nodo de inicio.
t: Entero que representa el nodo de destino.
Valor de retorno: Entero que representa la distancia mínima entre los puntos s y t.
*/
    int distancia(int s, int t) {
        int* pdist;
        int P[N];
        pdist = dijkstra(s, t, P);
        int distanciaMinima = pdist[t];
        camino(P,s,t);
        return distanciaMinima;
    }

private:
/*
El metodo dijkstra() implementa el algoritmo de Dijkstra para encontrar la distancia mínima entre dos puntos en la matriz.
Parámetros:
s: Entero que representa el punto de inicio.
t: Entero que representa el punto de destino.
Pre: Arreglo de enteros que almacenará los predecesores de cada punto en el camino más corto.
Valor de retorno: Puntero a un arreglo de enteros que contiene las distancias mínimas desde 
el punto de inicio hasta cada punto en la matriz.
*/
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

/*
El metodo camino() imprime el camino desde el punto de inicio hasta el punto de destino utilizando el arreglo de predecesores.
Parámetros:
P: Arreglo de enteros que contiene los predecesores de cada punto en el camino más corto.
s: Entero que representa el punto de inicio.
t: Entero que representa el punto de destino.
Valor de retorno: No devuelve ningún valor, imprime por pantalla el camino recorrido entre los nodos.
*/
void camino(int P[], int s, int t)
{  if (t==s) cout<< s+1 <<"  ";
   else{
        camino(P,s,P[t]);
        cout<<t+1<<"  ";
   }
}

};