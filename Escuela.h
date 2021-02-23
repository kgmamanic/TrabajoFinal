#ifndef ESCUELA_H
#define ESCUELA_H


#include "Asignatura.h"
#include "Estudiante.h"
#include "Facultad.h"

class Escuela
{
    private:
        Asignatura *asignaturas[20];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[20];
        int nVacantes;
        Facultad *facultad;
    public:
        Escuela();
        void AgregarAsi(Asignatura *A);
        void ModEscuela();
        int getVacantes();
        char* getFacultad();

};

#endif // ESCUELA_H
