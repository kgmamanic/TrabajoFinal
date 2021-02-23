#ifndef DATOSPERSONA_H
#define DATOSPERSONA_H


class DatosPersona
{
    public:
        DatosPersona();
        DatosPersona(char n[],char c[]);
        char* getcod();
        char* getnombre();
    private:
        char nombre[20];
        char codigo[6];
};

#include "DatosPersona.cpp"

#endif // DATOSPERSONA_H
