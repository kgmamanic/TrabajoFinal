#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include "Escuela.h"
#include "Facultad.h"

class Asignatura
{
    public:
        Asignatura();
    private:
        char nombre[25];
        char codigo[6];
        Escuela *escuela;

};

#endif // ASIGNATURA_H

