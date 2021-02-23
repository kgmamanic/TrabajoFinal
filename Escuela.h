#ifndef ESCUELA_H
#define ESCUELA_H


class Escuela
{
    private:
        char Nombre[20];
        Asignatura *asignaturas[20];
        int nCursos;
        int nEstudiantes;
        Estudiante *Estudi[20];
        int nVacantes;
        Facultad *facultad;
    public:
        Escuela();
        char* getNombre();
        void AgregarAsi(Asignatura *Asi);
        void ModEscuela();
        int getVacantes();
        char* getFacultad();

};

#endif // ESCUELA_H
