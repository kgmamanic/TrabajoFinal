#include "Facultad.h"
#include <string.h>

Facultad::Facultad()
{
    /*
    strcpy()

    
    */
}

char* Facultad::getNom(){
    return nombre;
}

void Facultad::mostrarEscuelas(){
    for(int i = 1; i <= nEscuelas ; i++){
        cout<<i<<". "<<escuelas[i].getNombre();
    }
}

