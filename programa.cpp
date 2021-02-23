#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>


#include "Asignatura.h"
#include "Extras.h"
#include "Escuela.h"
#include "Postulante.h"

using namespace std;

// Recibe como parametros los contadores de cada clase
void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P);

int main(){
    // Declaracion de los objetos
    Postulante PPos[10];
    Asignatura AAsi[0];
    Escuela EEsc[0];
    Facultad FFacu[0];
    Estudiante EEstu[0];
    // Declaracion de Contadores
    int contF=0,contEsc=0,contA=0,contEst=0,contP=0;
    
    string titulomenu;
    string opcionesmenu[] = {"Estudiante" , "Postulante","Visualizar","Administrador","Salir"};
    string menuVisu[] = {"Facultades", "Escuelas", "Resultados de Examenes","Volver"};
    string contrasenia;
    bool NoSalir = true; // para salir del bucle del menu
    int seleccion,seleccion2;
    char letra; // para administrador contraseña
    system("cls");
    do{    
        //MessageBox(0,"¿Guardar cambios?", "Título", MB_YESNO | MB_ICONQUESTION);
        titulomenu = {"Menu principal"};
        seleccion = Menu(titulomenu,opcionesmenu,5);
        titulomenu = opcionesmenu[seleccion-1];
        switch(seleccion){
            case 1:
                break;
            case 2:

                break;
            case 3:
                seleccion2 = Menu(titulomenu,menuVisu,4);
                switch(seleccion2){
                    case 1:
                        break;
                }
                break;
            case 4: // Para administrador
                system("cls");
                cuadro();
                gotoxy(55,17); cout<<"ADMINISTRADOR";
                gotoxy(40,21); cout<<" Usuario:";
                Pequecuadro(49, 20);
                cout<<admin;
                gotoxy(40, 25); cout<<"Password:";
                Pequecuadro(49,24);
                clave(contrasenia); 
                gotoxy(40, 28);
                if(contrasenia == password){
                    cout<<"Correcto... Iniciando Sesion";
                    Sleep(1000); cout<<".";
                    Sleep(1000); cout<<".";
                    Sleep(1000); cout<<".";
                    administrador(FFacu,EEsc,AAsi,EEstu,PPos,contF,contEsc,contA,contEst,contP);
                }else{
                    cout<<"Incorrecto... Volviendo a Menu Principal";
                    Sleep(1000); cout<<".";
                    Sleep(1000); cout<<".";
                    Sleep(1000); cout<<".";
                }
                break;
            case 5:
                NoSalir = false;
                break;
        }
    }while(NoSalir);
}

void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P){
    int opcion,opcion2;
    system("cls");
    bool seguir();
    // Variables Temporales
    char nombre[20],apellido[25],codigo[6];
    float puntaje;
    string nombremenu = "Bienvenido, Administrador";
    string opciones[] = {"Modificar","Eliminar","Agregar","Volver"};
    string op2[] = {"Facultades", "Escuelas" , "Asignaturas", "Estudiantes" , "Postulantes", "Volver"};
    opcion = Menu(nombremenu,opciones, 4);
    switch(opcion){
        case 1:
            opcion2= Menu("ADMINISTRADOR: modificar", op2, 6);
            break;
        case 2:
            opcion2 = Menu("ADMINISTRADOR: Eliminar", op2, 6);
            break;
        case 3:
            opcion2 = Menu("ADMINISTRADOR: Agregar", op2, 6);
            switch(opcion2){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5: // Agregar Postulante
                    P++; // contador de postulantes
                    Postulante postu[P]; 
                    system("cls");
                    cuadro();
                    gotoxy(55,17); cout<<"AGREGAR ESTUDIANTE";
                    cout<<"Nombre:"; Pequecuadro(62,16);
                    /*fstream Postulantes("/Data/Postulantes.dat",ios::binary|ios::in|ios::out);
                    if(Postulantes.is_open()){
                        while(seguir){
                            cuadro();
                            gotoxy(55,17);
                        }
                    }*/
                    break;
            }
            break;
        default: return;
    }
}

//  g++ -o programa.exe programa.cpp 