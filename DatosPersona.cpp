#include "DatosPersona.h"
#include <string.h>

DatosPersona::DatosPersona()
{
    strcpy(codigo,"000000");
    strcpy(nombre,"Sin nombre");    
}

DatosPersona::DatosPersona(char n[],char c[]){
    strcpy(codigo,c);
    strcpy(nombre,n);
}

char* DatosPersona::getcod(){
    return codigo;
}

char* DatosPersona::getnombre(){
    return nombre;
}