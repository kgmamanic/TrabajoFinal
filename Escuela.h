#ifndef ESCUELA_H
#define ESCUELA_H

#include "Asignatura.h"
#include "Estudiante.h"

class Escuela
{
    public:
        Escuela();
        void AgregarAsi(Asignatura *A);
        void ModEscuela();
        int getVacantes();
    private:
        Asignatura *asignaturas[];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[];
        int nVacantes;
};

#endif // ESCUELA_H
