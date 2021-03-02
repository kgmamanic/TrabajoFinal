#include "Escuela.h"

#include <fstream>
/*
Escuela::Escuela()
{
    
    nCursos = 0;
    nEstudiantes = 0;
    nVacantes = 0;
    
}
*/
char* Escuela::getNombre(){
    return Nombre;
}

// Agrega una asignatura a la escuela. Parametro: Puntero de asignatura
void Escuela::AgregarAsi(Asignatura *A){
    nCursos++;
    asignaturas[nCursos] = A; 
}

// Retorna el numero de Vacantes disponibles
int Escuela::getVacantes(){
    return nVacantes;
}
char* Escuela::getSiglas(){
    return Siglas;
}
void Escuela::asignarDatos(char *n,int nV,char* S){
    strcpy(Nombre,n);
    nVacantes = nV;
    strcpy(Siglas,S);
}

std::ostream & operator <<(std::ostream & escribir,Escuela & obj){
    escribir<<obj.getNombre();
    return escribir;
}
