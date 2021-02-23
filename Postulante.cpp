#include "Postulante.h"
#include <cstring>

Postulante::Postulante()
{    
}

Postulante::Postulante(char n[],char c[],char a[],char Ca[],float p,int nO):DatosPersona(n,c){
    strcpy(apellidos,a);
    strcpy(carrera,Ca);
    puntaje = p;
    nOrden = nO;
}

// Se usara para saber si algun postulante ingreso o no
bool Postulante::Ingresante(){
    return ingreso; // 
}