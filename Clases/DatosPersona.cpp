#include "DatosPersona.h"
#include <string.h>

DatosPersona::DatosPersona()
{
    /*
    strcpy(codigo,"000000");
    strcpy(nombre,"Sin nombre");
    */    
}

// asigna datos
void DatosPersona::asigDatos(char* n,char *a,char* c,char * S){
    strcpy(codigo,c);
    strcpy(nombre,n);
    strcpy(EsSiglas,S);
    strcpy(apellidos,a);
}
char* DatosPersona::getApe(){
    return apellidos;
}

// Retorna Codigo
char* DatosPersona::getCod(){
    return codigo;
}

// Retorna Nombre
char* DatosPersona::getNombre(){
    return nombre;
}

char* DatosPersona::obtenerSiglas(){
    return EsSiglas;
}