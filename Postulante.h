#ifndef POSTULANTE_H
#define POSTULANTE_H


class Postulante: public DatosPersona
{
    private:
        int nOrden;
        char apellidos[25];
        Escuela *carrera; // No se si poner apuntador o normalito
        float puntaje;
        bool ingreso;
    public:
        Postulante();
        Postulante(char n[],char c[],char a[],Escuela *Ca,float p,int nO);
        bool Ingresante();

};

#endif // POSTULANTE_H
