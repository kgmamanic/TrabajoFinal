#include "Escuela.h"

#include <fstream>

Escuela::Escuela()
{
    nCursos = 0;
    nEstudiantes = 0;
    nVacantes = 0;
}

// Agrega una asignatura a la escuela. Parametro: Puntero de asignatura
void Escuela::AgregarAsi(Asignatura *A){
    nCursos++;
    asignaturas[nCursos] = A; 
}

// Opcion para modificar los atributos de la escuela
void Escuela::ModEscuela(){
    //Todavia
}


// Retorna el numero de Vacantes disponibles
int Escuela::getVacantes(){
    return nVacantes;
}


// Retorna el nombre de la Facultad
char* Escuela::getFacultad(){
    return facultad->getNom();
}