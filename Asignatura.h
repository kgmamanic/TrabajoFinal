#ifndef ASIGNATURA_H
#define ASIGNATURA_H

class Escuela;
class Estudiante;

#include"Escuela.h"
#include"Estudiante.h"


class Asignatura{
    private:
        char nombre[25];
        char codigo[6];
        Escuela *escuela;
        char docentes[3][30];
        int nDocentes;
        Estudiante *Alumnos[40];
        int nAlumnos;
    public:
        Asignatura();
        char *getNom();
        void modAsignatura();
        void agregarEstudiante(Estudiante *Estudy);
        char *getCod();
};

#endif // ASIGNATURA_H

