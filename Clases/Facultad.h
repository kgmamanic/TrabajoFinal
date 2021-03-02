#ifndef FACULTAD_H
#define FACULTAD_H

#include "Escuela.h"


class Facultad
{
    public:
        Facultad();
        //Facultad(char* n);
        char* getNombre();
        void mostrarEscuelas();
        void crearEscuela(Escuela E[],int &contE);
        void asignarDatos(char *n);
        friend std::ostream & operator <<(std::ostream & escribir,Facultad & obj);
    protected:
        char nombre[20];
        Escuela *escuelas[20];
        int nEscuelas;
};

int sizeFacultad = sizeof(Facultad);

#include "Facultad.cpp"
#endif // FACULTAD_H
