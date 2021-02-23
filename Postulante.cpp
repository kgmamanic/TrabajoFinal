#include "Postulante.h"
#include <string.h>

Postulante::Postulante()
{/*
    strcpy(apellidos,"aaaaa");
    carrera = NULL;
    puntaje = 0;
    nOrden = 9999;
    ingreso = false;
    */ 
}

Postulante::Postulante(char n[],char c[],char a[],Escuela *Ca,float p,int nO):DatosPersona(n,c){
    strcpy(apellidos,a);
    carrera = Ca;
    puntaje = p;
    nOrden = nO;
    if(nOrden <= carrera->getVacantes()){
        ingreso = true;
        Ingresante();
    }else{
        ingreso = false;
    }
}

// Se usara para saber si algun postulante ingreso o no
bool Postulante::Ingresante(){
    return ingreso; // 
}