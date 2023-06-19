#include <iostream>
const int LLENO = 10;
using namespace std;
class robot{

private:
    int volumen;

public:
    robot() {
        volumen = 0;
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

    void aumentarVolumen(){
        if(!isLleno()){
            volumen+=1;
        } else cout<<"robot lleno"<<endl;
    }

    void descargarVolumen(){
        volumen = 0;
    }
};