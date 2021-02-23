#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H


class Estudiante //: public DatosPersona
{
    public:
        Estudiante();
        void agregarCursos(Asignatura *Asig);
        char getcontrasena();
        void agreMatricula(int );
        

    private:
        char Apellidos[20];
        /*
    Escuela *escuela
    Asignatura *Cursos[]
    */
        char contrasena[10];
        int nCursos;
        int nmatricula;
};

#endif // ESTUDIANTE_H
