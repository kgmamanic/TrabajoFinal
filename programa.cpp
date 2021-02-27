#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

#include "ordenador.h"
#include"Clases/Escuela.h"
#include"Clases/Facultad.h"
#include"Clases/Postulante.h"

using namespace std;

#include"Extras.h"
// Recibe como parametros los contadores de cada clase
void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P);


int main(){
    // Declaracion de los objetos
    Postulante PPos[50];
    Asignatura AAsi[0];
    Escuela EEsc[0];
    Facultad FFacu[0];
    Estudiante EEstu[0];
    // Declaracion de Contadores
    int contP=0,contA=0,contEsc=0,contF=0,contEst=0;
    
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
            // Solicitara usuario y contraseña usuario:(SIGLAS DE ESCUELA)+(codigo)
                break;
            case 2:
                // 2 opciones buscar por nombre y la otra ver lista completa
                break;
            case 3:
                // se usara para mostrar datos generales de las escuelas y facultades
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
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    administrador(FFacu,EEsc,AAsi,EEstu,PPos,contF,contEsc,contA,contEst,contP);
                }else{
                    cout<<"Incorrecto... Volviendo a Menu Principal";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                }
                break;
            case 5:
                NoSalir = false;
                break;
        }
    }while(NoSalir);
}

void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P){
    int opcion,opcion2,nSEscuela;
    system("cls");
    bool seguir();
    // Variables Temporales
    char nombre[20],apellido[30],codigo[7],pass[15],SEscuela[5];
    float puntaje;
    // menus
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
                case 1: // agregar facultades
                case 2: // agregar escuelas
                case 3:// agregar asignaturas
                case 4: // Agregar Estudiante
                    system("cls");
                    cuadro(); 
                    gotoxy(55,17); cout<<"AGREGAR ESTUDIANTE";
                    gotoxy(40,20);
                    cout<<"Nombre:";Pequecuadro(47,19);
                    gotoxy(37,23);
                    cout<<"Apellidos:"; Pequecuadro(47,22);
                    gotoxy(28,26);
                    cout<<"Codigo:(Ejm 000000):";Pequecuadro(47,25);
                    gotoxy(36,29);
                    cout<<"Contrase\244a:";Pequecuadro(47,28);
                    // ingresar datos
                    gotoxy(48,20);
                    fflush(stdin); cin.getline(nombre,20);
                    gotoxy(48,23);
                    fflush(stdin); cin.getline(apellido,30);
                    gotoxy(48,26);
                    fflush(stdin); cin.getline(codigo,7);
                    gotoxy(48,29);
                    fflush(stdin); cin.getline(pass,20);
                    // Seleccionar Escuela todavia
                    system("cls");
                    nSEscuela = Menu("Seleccion Escuela",escu,Esc);
                    Estudiante Estutemp(nombre,apellido,codigo,escu[nSEscuela].getSiglas(),pass);
                    
                    break;
                case 5: // Agregar Postulante  - Desarrollado
                    system("cls");
                    cuadro();
                    gotoxy(55,17); cout<<"AGREGAR POSTULANTE";
                    gotoxy(40,20);
                    cout<<"Nombre:"; Pequecuadro(47,19);
                    gotoxy(37,23);
                    cout<<"Apellidos:"; Pequecuadro(47,22);
                    gotoxy(28,26);
                    cout<<"Codigo(Ejm 000000):"; Pequecuadro(47,25);
                    gotoxy(39,29);
                    cout<<"Puntaje:"; Pequecuadro(47,28);
                    // Ingresar Datos
                    gotoxy(48,20);
                    fflush(stdin); cin.getline(nombre,20); // nombre
                    gotoxy(48,23);
                    fflush(stdin); cin.getline(apellido,30); // apellidos
                    gotoxy(48,26);
                    strcat(codigo,"AAA");
                    fflush(stdin); cin.getline(codigo,sizeof(codigo));
                    gotoxy(48,29);
                    fflush(stdin); cin>>puntaje;
                    P = P+1; // contador de postulantes                    
                    char AAA[] = "ESIS"; // eliminar 
                    Postulante postutemp(nombre,codigo,AAA,apellido,AAA,puntaje);
                    postu[P] = postutemp;
                    // Ordena los postulantes
                    quickshortDes(postu,P);
                    administrador(Facu,escu,asig,estu,postu,F,Esc,A,Est,P);
                    break;
            }
            break;
        default: return;
    }
}

//  g++ -o programa.exe programa.cpp
//pipipi