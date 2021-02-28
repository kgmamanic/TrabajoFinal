#ifndef DATOSPERSONA_H
#define DATOSPERSONA_H


class DatosPersona
{
    public:
        DatosPersona();
        //DatosPersona(char* n,char* a,char* c,char* S);
        char* getcod();
        char* getnombre();
        char* obtenerSiglas();
        char* getApe();
        void asigDatos(char* n,char* a,char* c,char* S);
    private:
        char nombre[20];
        char apellidos[30];
        char codigo[7];
        char EsSiglas[5];

};

#include "DatosPersona.cpp"

#endif // DATOSPERSONA_H
