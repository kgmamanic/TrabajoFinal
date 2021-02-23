#include "Postulante.h"

Postulante::Postulante()
{
    // no realizar constructores
    //porque p ? :v
    // porque su desarrollo no ayuda en nada :v los dejamos asi nomas con llaves 
    //yaya
}

Postulante::Postulante(char n[],char c[],char a[],char Ca[],float p,int nO):DatosPersona(n,c){
    strcpy(apellidos,a);
    strcpy(carrera,Ca);
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