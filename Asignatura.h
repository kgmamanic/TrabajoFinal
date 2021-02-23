#ifndef ASIGNATURA_H
#define ASIGNATURA_H



#include "Escuela.h"
#include "Estudiante.h"

class Asignatura
{
    public:
        Asignatura();
        char *getNom();
        void modAsignatura();
        void agregarEstudiante(Estudiante *E);
        char *getCod();

    private:
        char nombre[25];
        char codigo[6];
        Escuela *escuela;
        char docentes[3][30];
        int nDocentes;
        Estudiante* Alumnos[40];
        int nAlumnos;

};

#endif // ASIGNATURA_H

