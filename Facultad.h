#ifndef FACULTAD_H
#define FACULTAD_H


class Facultad
{
    public:
        Facultad();
        char* getNom();
    protected:
        char nombre[20];
        Escuela *escuelas[20];
};

#endif // FACULTAD_H
