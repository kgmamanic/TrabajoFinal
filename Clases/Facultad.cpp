#include "Facultad.h"
#include <cstring>
#include <iostream>
//#include <iostream>
using namespace std;
Facultad::Facultad()
{
    /*
    strcpy()

    
    */
}
void Facultad::asignarDatos(char* n){
    strcpy(nombre,n);
}

char* Facultad::getNombre(){
    return nombre;
}

void Facultad::mostrarEscuelas(){
    for(int i = 1; i <= nEscuelas ; i++){
        cout<<i<<". "<<escuelas[i];
    }
}

void Facultad::crearEscuela(Escuela E[], int &contE){
    contE = contE+1;
    char nombre[60],Siglas[5];
    int numVac;
    cout<<"Nombre:";
    fflush(stdin);cin.getline(nombre,60);
    cout<<"Numero de vacantes";
    cin>>numVac;
    cout<<"SIGLAS (4 Caracteres)";
    fflush(stdin);cin.getline(Siglas,5);
    nEscuelas = nEscuelas +1;
    escuelas[nEscuelas] = new Escuela;
    escuelas[nEscuelas]->asignarDatos(nombre,numVac,Siglas);
    
}
std::ostream & operator <<(std::ostream & escribir,Facultad & obj){
    escribir<<obj.nombre;
    return escribir;
}
