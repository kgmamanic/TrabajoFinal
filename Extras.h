#include <stdio.h>  
#include <windows.h>  
#include <iostream>
#include <conio.h>


void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

// Modifica el el cuadrito que parpadea al escribir
void ModCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(hcon, &cci);
}


#define ARRIBA 72
#define ABAJO 80
#define ENTER 13


using namespace std;

// Grafica un cuadro
void cuadro(){
    gotoxy(8,8);
    cout<<"\311";
    // Linea Horizontal Sup
    for(int i = 1; i < 100 ; i++){
        cout<<"\315";
    }
    cout<<"\273";
    // Linea Vertical Izq
    for(int i = 1; i<30; i++){
        gotoxy(8,8+i);
        cout<<"\272";
    }
    gotoxy(8,37);
    cout<<"\310";
    // Linea Horizontal Inf
    for(int i = 1; i < 100 ; i++){
    cout<<"\315";
    }
    cout<<"\274";
    //gotoxy(107,8);
    // Linea vertical Der
    for(int i = 1; i<29; i++){
        gotoxy(108,8+i);
        cout<<"\272";
    }
    cout<<endl<<endl;
}

// Implementa un menu. Recibe como Parámetros nombremenu( titulo del menu), opciones(arreglo de opciones), nopciones(cantidad de opciones)
int Menu(string nombremenu, string opciones[], int nopciones){
    int tecla;
    bool repetir = true;
    int flecha = 18, opcion = 1;
    WORD Attributes = 0;
    ModCursor();

    do{
        system("cls");
        cuadro();
        gotoxy(50,17);
        cout<<nombremenu;
        for(int i = 1; i <= nopciones ; i++){
            gotoxy(50,18+i);
            cout<<i<<". "<<opciones[i-1];
        }
        gotoxy(48,flecha+opcion);
        do{
            tecla = getch();
        }while(tecla != ARRIBA && tecla != ABAJO && tecla != ENTER );
        switch(tecla){
            case ARRIBA:
                opcion--;
                if(opcion < 1){
                    opcion = nopciones;
                }
                break;
            case ABAJO:
                opcion++;
                if(opcion > nopciones){
                    opcion = 1;
                }
                break;
            case ENTER:
                repetir = false;
                break;
        }
    }while(repetir);
    return opcion;
}

