#include "Estudiante.h"
#include <iostream>

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
void Estudiante::asignarDatos(char* n,char* a,char* c, char* S, char* contra){
    asigDatos(n,a,c,S);
    strcpy(contrasena,contra);
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

void Estudiante::modEstudiante(){   
    //-con gotoxy y esas cosas 
}

