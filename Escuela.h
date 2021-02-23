#ifndef ESCUELA_H
#define ESCUELA_H

class Asignatura;

#include "Asignatura.h"
#include "Estudiante.h"
#include "Facultad.h"

class Escuela
{
    public:
        Escuela();
        void AgregarAsi(Asignatura *A);
        void ModEscuela();
        int getVacantes();
        char* getFacultad();
    private:
        Asignatura *asignaturas[20];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[20];
        int nVacantes;
        Facultad *facultad;
};

#endif // ESCUELA_H
