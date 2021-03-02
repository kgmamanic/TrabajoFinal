#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include"DatosPersona.h"
#include"Asignatura.h"

class Estudiante: public DatosPersona
{
    public:
        Estudiante();
        //Estudiante(char* n,char* a,char* c, char* S, char* contra);
        void agregarCursos(Asignatura *Asig);
        char* getcontrasena();
        void agreMatricula(int );
        void modEstudiante();
        void asignarDatos(char* n,char* a,char* c, char* S, char* contra);
    private:
        Asignatura *Cursos[9];
        char contrasena[20];
        int nCursos;
        int nmatricula;
};

int sizeEstudiante= sizeof(Estudiante);

#include "Estudiante.cpp"
#endif // ESTUDIANTE_H
