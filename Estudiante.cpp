#include "Estudiante.h"

Estudiante::Estudiante()
{
    //ctor
}

void Estudiante::agregarCursos(Asignatura *Asig){
    nCursos++;
    Cursos[nCursos] = Asig;
}

char* Estudiante::getContrase(){
    return contrasena;
}

void Estudiante::agreMatricula(int n){
    nmatricula = n;
}

void modEstudiante(){
    // con gotoxy y esas cosas :V 
}