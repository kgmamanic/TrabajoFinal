#include "Facultad.h"
#include <cstring>

#include <iostream>

Facultad::Facultad()
{
    /*
    strcpy()

    
    */
}
void Facultad::asignarDatos(char* n){
    strcpy(nombre,n);
}

char* Facultad::getNom(){
    return nombre;
}

void Facultad::mostrarEscuelas(){
    for(int i = 1; i <= nEscuelas ; i++){
        std::cout<<i<<". "<<escuelas[i];
    }
}

void Facultad::crearEscuela(Escuela E[], int &contE){
    contE = contE+1;
    
}
std::ostream & operator <<(std::ostream & escribir,Facultad & obj){
    escribir<<obj.nombre;
    return escribir;
}
