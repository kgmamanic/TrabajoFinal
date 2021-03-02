#include "Postulante.h"
#include <cstring>

Postulante::Postulante()
{    
}

void Postulante::asignarDatos(char* n,char* c,char* S,char* a,float p){
    asigDatos(n,a,c,S);
    puntaje = p;
}

// Se usara para saber si algun postulante ingreso o no
bool Postulante::Ingresante(){
    return ingreso; // 
}

void Postulante::mostrar(){
    std::cout<<getNombre()<<getApe()<<" "<<getcod()<<" "<<puntaje;
}

bool Postulante:: operator<(Postulante P){
    if(puntaje < P.puntaje){
        return true;
    }else{
        return false;
    }
}

float Postulante::getPunt(){
    return puntaje;
}