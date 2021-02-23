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
    public:
        Escuela();
        char* getNombre();
        void AgregarAsi(Asignatura *Asi);
        void ModEscuela();
        int getVacantes();

};

#endif // ESCUELA_H
