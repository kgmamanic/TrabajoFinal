#include "Asignatura.h"

Asignatura::Asignatura()
{
    //ctor
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

char* Asignatura::getNom(){
    return nombre;
}
