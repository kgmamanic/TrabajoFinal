#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

#include "Extras.h"

using namespace std;




int main(){
    fstream ListaPostulanes;
    ListaPostulanes.open("/Data/ListaPostulantes.dat", ios::binary|ios::in|ios::out);
    string a;
    string b[5] = {"Estudiante" , "Postulante","Visualizar","Administrador","Salir"};
    string menuVisu[4] = {"Facultades", "Escuelas", "Resultados de Examenes"};
    bool NoSalir = true;
    int seleccion,seleccion2;
    system("cls");
    do{    
        //MessageBox(0,"¿Guardar cambios?", "Título", MB_YESNO | MB_ICONQUESTION);
        a = {"Menu principal"};
        seleccion = Menu(a,b,5);
        a = b[seleccion-1];
        switch(seleccion){
            case 1:
                break;
            case 2:

                break;
            case 3:
                seleccion2 = Menu(a,menuVisu,3);
                switch(seleccion2){
                    case 1:
                        break;
                }
                break;
            case 4:
                break;
            case 5:
                NoSalir = false;
                break;
        }
    }while(NoSalir);
}

//  g++ -o programa.exe programa.cpp 