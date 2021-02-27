#ifndef ESCUELA_H
#define ESCUELA_H

#include"Estudiante.h"

class Escuela
{
    private:
        char Nombre[20];
        Asignatura *asignaturas[20];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[20];
        int nVacantes;
        char Siglas[5];
    public:
        Escuela();
        char* getNombre();
        void AgregarAsi(Asignatura *Asi);
        void ModEscuela();
        int getVacantes();
        char* getSiglas();
        friend std::ostream & operator <<(std::ostream & escribir,Escuela & obj);
};

#include "Escuela.cpp"

#endif // ESCUELA_H
