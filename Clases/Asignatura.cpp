#include "Asignatura.h"

Asignatura::Asignatura()
{
    //ctor
}

void Asignatura::asignarDatos(char *n,char* c,char d[][40],int nD){
    strcpy(nombre,n);
    strcpy(codigo,c);
    for(int i=0;i<nD;i++){
        strcpy(docentes[i],d[1]);
    }
}

// Agrega un estudiante a la asignatura
void Asignatura::agregarEstudiante(Estudiante *E){
    // todavia
}


// modifica asignatura solo administradores
void Asignatura::modAsignatura(){
    // todavia
}

char* Asignatura::getCod(){
    return codigo;
}

char* Asignatura::getNombre(){
    return nombre;
}

