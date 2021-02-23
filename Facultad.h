#ifndef FACULTAD_H
#define FACULTAD_H

// Cabeceras


class Facultad
{
    public:
        Facultad();
        char* getNom();
        void mostrarEscuelas();
    protected:
        char nombre[20];
        Escuela *escuelas[20];
        int nEscuelas;
};

#endif // FACULTAD_H
