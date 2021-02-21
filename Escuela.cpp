#include "Escuela.h"

#include <fstream>

Escuela::Escuela()
{
    nCursos = 0;
    nEstudiantes = 0;
    nVacantes = 0;
}

void Escuela::AgregarAsi(Asignatura *A){
    nCursos++;
    asignaturas[nCursos] = A; 
}

void Escuela::ModEscuela(){
    //Todavia
}

int Escuela::getVacantes(){
    return nVacantes;
}

