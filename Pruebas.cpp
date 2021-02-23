#include <iostream>
#include <string.h>



class Escuela
{
    private:
        int nCursos;
        int nEstudiantes;
        int nVacantes;
    public:
        Escuela();
        void ModEscuela();
        int getVacantes();

};


Escuela::Escuela()
{
    /*
    nCursos = 0;
    nEstudiantes = 0;
    nVacantes = 0;
    */
}

// Agrega una asignatura a la escuela. Parametro: Puntero de asignatura


// Opcion para modificar los atributos de la escuela
void Escuela::ModEscuela(){
    //Todavia
}


// Retorna el numero de Vacantes disponibles
int Escuela::getVacantes(){
    return nVacantes;
}


// Retorna el nombre de la Facultad

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
DatosPersona::DatosPersona()
{
    /*
    strcpy(codigo,"000000");
    strcpy(nombre,"Sin nombre");
    */    
}

// Constructor
DatosPersona::DatosPersona(char n[],char c[]){
    strcpy(codigo,c);
    strcpy(nombre,n);
}

// Retorna Codigo
char* DatosPersona::getcod(){
    return codigo;
}

// Retorna Nombre
char* DatosPersona::getnombre(){
    return nombre;
}

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


Postulante::Postulante()
{/*
    strcpy(apellidos,"aaaaa");
    carrera = NULL;
    puntaje = 0;
    nOrden = 9999;
    ingreso = false;
    */ 
}

Postulante::Postulante(char n[],char c[],char a[],Escuela *Ca,float p,int nO):DatosPersona(n,c){
    strcpy(apellidos,a);
    carrera = Ca;
    puntaje = p;
    nOrden = nO;
    if(nOrden <= carrera->getVacantes()){
        ingreso = true;
        Ingresante();
    }else{
        ingreso = false;
    }
}

// Se usara para saber si algun postulante ingreso o no
bool Postulante::Ingresante(){
    return ingreso; // 
}

int main(){
    Postulante a[0];
}