#ifndef ASIGNATURA_H
#define ASIGNATURA_H

class Escuela;
class Estudiante;

#include"Escuela.h"
#include"Estudiante.h"


class Asignatura{
    private:
        char nombre[40];
        char codigo[6];
        Escuela *escuela;
        char docentes[3][50];
        int nDocentes;
        Estudiante *Alumnos[40];
        int nAlumnos;
    public:
        Asignatura();
        char *getNombre();
        void modAsignatura(char *n , char *c);
        void agregarEstudiante(Estudiante *Estudy);
        char *getCod();
        void asignarDatos(char *n,char* c,char d[][40],int nD,Escuela *es);
};

int sizeAsignatura = sizeof(Asignatura);
#include "Asignatura.cpp"
#endif // ASIGNATURA_H

