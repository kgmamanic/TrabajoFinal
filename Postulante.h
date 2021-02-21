#ifndef POSTULANTE_H
#define POSTULANTE_H

#include "DatosPersona.h"
#include "Escuela.h"

class Postulante: public DatosPersona
{
    public:
        Postulante();
        Postulante(char n[],char c[],char a[],Escuela *Ca,float p,int nO);
        bool Ingresante();
    private:
        char apellidos[];
        Escuela *carrera; // No se si poner apuntador o normalito
        float puntaje;
        bool ingreso;
        int nOrden;
};

#endif // POSTULANTE_H
