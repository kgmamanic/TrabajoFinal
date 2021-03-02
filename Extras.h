#include <stdio.h>  
#include <windows.h>  
#include <iostream>
#include <conio.h>

// mueve el cursor a una lugar especifico
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

// Modifica el el cuadrito que parpadea al escribir
void ModCursor(bool Mostrar){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = Mostrar;
    SetConsoleCursorInfo(hcon, &cci);
}


#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define RETROCESO 8

using namespace std;

// Grafica un cuadro
void cuadro(){
    ModCursor(FALSE);
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
    ModCursor(TRUE);
}

// Grafica un pequeño rectangulo x + cantidad de texto  | y-1
void Pequecuadro(int x, int y){
    ModCursor(FALSE);
    gotoxy(x,y); cout<<"\311";
    // Linea horizontal Sup
    for(int i = 1; i < 30 ; i++){
        cout<<"\315";
    }
    gotoxy(x,y+1); cout<<"\272";
    gotoxy(x,y+2); cout<<"\310";
    // Linea Inferior Sub
    for(int i = 1; i < 30 ; i++){
        cout<<"\315";
    }
    gotoxy(x+29,y); cout<<"\273";
    gotoxy(x+29,y+1); cout<<"\272";
    gotoxy(x+29, y+2); cout<<"\274";
    gotoxy(x+1,y+1); // vuelve a la posicion inicial para escribir 
    ModCursor(TRUE);
}

// Implementa un menu. Recibe como Parámetros nombremenu( titulo del menu), opciones(arreglo de opciones), nopciones(cantidad de opciones)
int Menu(string nombremenu, string opciones[], int nopciones){
    int tecla;
    bool repetir = true;
    int flecha = 18, opcion = 1;
    // imprime menu
    ModCursor(FALSE);
    system("cls");
    cuadro();
    gotoxy(50,17);
    cout<<nombremenu;
    for(int i = 1; i <= nopciones ; i++){
        gotoxy(50,18+i);
        cout<<i<<". "<<opciones[i-1];
    }
    do{
        gotoxy(48,flecha+opcion);
        do{
            ModCursor(TRUE);
            tecla = getch();
            ModCursor(FALSE);
            // Para actualizar la pantalla
            if(tecla == RETROCESO){
                // para actualizar la pantalla
                ModCursor(FALSE);
                system("cls");
                cuadro();
                gotoxy(50,17);
                cout<<nombremenu;
                for(int i = 1; i <= nopciones ; i++){
                    gotoxy(50,18+i);
                    cout<<i<<". "<<opciones[i-1];
                }
                gotoxy(48,flecha + opcion);
            }
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

// menu de Escuelas y Facultades
template <class a>
int MenuEF(string nombremenu, a opciones[], int nopciones){
    int tecla;
    bool repetir = true;
    int flecha = 18, opcion = 1;
    // imprime menu
    ModCursor(FALSE);
    system("cls");
    cuadro();
    gotoxy(50,17);
    cout<<nombremenu;
    for(int i = 1; i <= nopciones ; i++){
        gotoxy(50,18+i);
        cout<<i<<". "<<opciones[i];
    }
    do{
        gotoxy(48,flecha+opcion);
        do{
            ModCursor(TRUE);
            tecla = getch();
            ModCursor(FALSE);
            // Para actualizar la pantalla
            if(tecla == RETROCESO){
                // para actualizar la pantalla
                ModCursor(FALSE);
                system("cls");
                cuadro();
                gotoxy(50,17);
                cout<<nombremenu;
                for(int i = 1; i <= nopciones ; i++){
                    gotoxy(50,18+i);
                    cout<<i<<". "<<opciones[i];
                }
                gotoxy(48,flecha + opcion);
            }
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


#define admin "admin"
#define password "lagarto"

// Forma de escribir en "*" como una contraseña" 
void clave(string &pass){
    char letra;
    letra = getch();
    pass = "";
    while(letra != ENTER){ // Escribir contraseña
        if(letra != RETROCESO){ // 8 = retroceso
            pass.push_back(letra);
            cout<< "*";
        }else{
            if(pass.length() >0){
                cout<<"\b \b";
                pass = pass.substr(0,pass.length()-1);
            }
        }
        letra = getch();
    }
}

void modificar(char* atrib){
    char letra;
    string palabra = atrib;
    letra = getch();
    cout<<atrib;
    while(letra != ENTER){
        if(letra != RETROCESO){
            palabra.push_back(letra);
            cout<<letra;
        }else{
            if(palabra.length()> 0){
                cout<<"\b \b";
                palabra = palabra.substr(0,palabra.length()-1);
            }
        }
    }
}
