#include "DatosPersona.h"
#include <string.h>

DatosPersona::DatosPersona()
{
    /*
    strcpy(codigo,"000000");
    strcpy(nombre,"Sin nombre");
    */    
}

// Constructor
DatosPersona::DatosPersona(char* n,char* c){
    strcpy(codigo,c);
    strcpy(nombre,n);
}

// Retorna Codigo
char* DatosPersona::getcod(){
    return codigo;
}

// Retorna Nombre
char* DatosPersona::getnombre(){
    return nombre;
}
