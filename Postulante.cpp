#include "Postulante.h"
#include <cstring>

Postulante::Postulante()
{    
}

Postulante::Postulante(char* n,char* c,char* a,char* Ca,float p):DatosPersona(n,c){
    strcpy(apellidos,a);
    strcpy(carrera,Ca);
    puntaje = p;
}

// Se usara para saber si algun postulante ingreso o no
bool Postulante::Ingresante(){
    return ingreso; // 
}

void Postulante::mostrar(){
    std::cout<<getnombre()<<apellidos<<" "<<getcod()<<carrera<<" "<<puntaje;
}

bool Postulante:: operator<(Postulante P){
    if(puntaje < P.puntaje){
        return true;
    }else{
        return false;
    }
}