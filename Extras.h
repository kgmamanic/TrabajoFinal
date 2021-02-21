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
#define ARRIBA 
#define ABAJO 
#define ENTER 13

using namespace std;

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

int Menu(){
    int tecla;
    bool repetir = true;
    do{
        do{
            tecla = getch();
        }while(tecla != ARRIBA && tecla != ABAJO && tecla != ENTER );
        switch(tecla){
            case ARRIBA:
                cout<<"ARRIBA";
                break;
            case ABAJO:
                cout<<"ABAJO";
                break;
            case ENTER:
                cout<<"ENTER";
                repetir = false;
                break;
        }
    }while(repetir);
}

void OcultarCursor(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(hCon, )
}