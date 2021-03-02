#ifndef ESCUELA_H
#define ESCUELA_H

#include"Estudiante.h"
class Escuela
{
    private:
        char Nombre[60];
        Asignatura *asignaturas[20];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[20];
        int nVacantes;
        char Siglas[5];
    public:
        Escuela(){}
        char* getNombre();
        void AgregarAsi(Asignatura *Asi);
        int getVacantes();
        char* getSiglas();
        void asignarDatos(char *n,int nV,char* S);
        friend std::ostream & operator <<(std::ostream & escribir,Escuela & obj);
};

int sizeEscuela = sizeof(Escuela);

#include "Escuela.cpp"

#endif // ESCUELA_H
