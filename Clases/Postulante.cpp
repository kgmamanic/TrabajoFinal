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
    if(ingreso){
        return true;
    }else{
        return false;
    }
}

void Postulante::mostrar(){
    std::cout<<getNombre()<<getApe()<<" "<<getCod()<<" "<<puntaje;
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
void Postulante::asignarOrden(int numero, bool ing){
    nOrden = numero;
    ingreso = ing;
}

int Postulante::getOrden(){
    return nOrden;
}