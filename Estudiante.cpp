#include "Estudiante.h"

Estudiante::Estudiante()
{
    /*
    strcpy(apellidos,"sin apellido");
    strcpy(asignatura,"sin asignatura")
    nCursos=0;
    nMatricula=0;

    */
    //ctor
}

void Estudiante::agregarCursos(Asignatura *Asig){
    nCursos++;
    Cursos[nCursos] = Asig;
}

char* Estudiante::getcontrasena(){
    return contrasena;
}

void Estudiante::agreMatricula(int n){
    nmatricula = n;
}

void modEstudiante(){   
    //-con gotoxy y esas cosas 
}