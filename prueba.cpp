#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#define MIEMBRO   1
#define NO_MIEMBRO 0
const int N = 720;
using namespace std;

void imprimirMatriz(int** matriz) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int *dijkstra(int** matriz,int s, int t, int Pre[])
{
 static int D[N];
 int S[N];
 int actual, i, k, b;
 int menordist, nuevadist;
 int contador = 0;

 for(i=0;i<N;i++){
                         S[i]=NO_MIEMBRO;
                         D[i]=9000;
                         Pre[i]= -1;
 }//fin for
 S[s]=MIEMBRO; D[s]=0; actual=s; b=1; k=0;
 while((actual!=t)&&(b==1)){
                  b=0;
                  menordist=9000;
                  for(i=0;i<N;i++){                
                          if(S[i]==NO_MIEMBRO){
                                 nuevadist=D[actual]+matriz[actual][i];
                                 if(nuevadist<D[i]){
                                        D[i]=nuevadist;
                                        Pre[i]=actual; b=1;
                                 }
                                 if(D[i]<menordist){
                                        menordist=D[i];
                                        k=i;  b=1;
                                 }
                          }
                  }
                               
                  actual=k; // actual se ubica en el nodo de menor distancia
                  S[actual]=MIEMBRO;
                  //printf("\n\n         D     S     Pre");
                  for(i=0;i<N;i++){
                           //printf("\n[%2i] %5i %5i %5i     ",i,D[i], S[i],Pre[i]);              ////////////////////
                   } 
      
                  //printf("\n\n   D[%i]=%3i ",actual,D[actual]);
                
                contador=contador+1;  
                cout<<"iteracion: "<<contador<<endl;

                //system("PAUSE");
 }//fin while
 return D;
}// fin dijkstra

void camino(int P[], int s, int t)
{  if (t==s) cout<< s<<"  ";
   else{
        camino(P,s,P[t]);
        cout<<t<<"  ";
   }   
}






int main() {
    // Crear la matriz en el heap
    int** matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[N];
    }

    // Cargar la matriz de adyacencia desde el csv
    ifstream archivo("adyacencia.csv");
    string linea;

    int fila = 0;
    while (getline(archivo, linea) && fila < N) {
        stringstream ss(linea);
        string valor;

        int columna = 0;
        while (getline(ss, valor, ',') && columna < N) {
            matriz[fila][columna] = stoi(valor);
            columna++;
        }

        fila++;
    }

    archivo.close();

    // Imprimir la matriz
    //imprimirMatriz(matriz);


    int *pdist, i, j, P[N],s,t;

    s=0;  // vertice de inicio
    t=719;  // vertice final

    pdist=dijkstra(matriz,s,t,P);

    if (pdist[t]!=9000){
        cout<<"\n\n distancia minima del nodo "<<s
            <<" al nodo "<<t<<" es= "<<pdist[t];
   
        cout<<"\n\n CAMINO= ";
        camino(P,s,t);
       
    }                
    else cout<<"\n NO HAY CAMINO";
    
    cout<<endl<<endl<<endl;
    












    system("pause");

    // Liberar la memoria asignada en el heap
    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
