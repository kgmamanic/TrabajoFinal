#ifndef POSTULANTE_H
#define POSTULANTE_H


#include"DatosPersona.h"

class Postulante: public DatosPersona
{
    private:
        int nOrden;
        char apellidos[30];
        char carrera[20]; 
        float puntaje;
        bool ingreso;
    public:
        Postulante();
        Postulante(char* n,char* c,char* a,char* Ca,float p);
        bool Ingresante();
        void mostrar();
        bool operator<(Postulante P);

};

#include"Postulante.cpp"
#endif // POSTULANTE_H
