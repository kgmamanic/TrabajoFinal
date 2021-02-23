#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include"DatosPersona.h"
#include"Asignatura.h"

class Estudiante: public DatosPersona
{
    public:
        Estudiante();
        void agregarCursos(Asignatura *Asig);
        char* getcontrasena();
        void agreMatricula(int );
        void modEstudiante();

    private:
        char Apellidos[20];
        Asignatura *Cursos[9];
        char contrasena[10];
        int nCursos;
        int nmatricula;
};

#endif // ESTUDIANTE_H
