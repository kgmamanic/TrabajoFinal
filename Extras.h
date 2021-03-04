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

void clave(char cl[]){
    string contra = cl;
    clave(contra);
    strcpy(cl,contra.c_str());
}

void modificar(char* atrib){
    char letra;
    string palabra = atrib;
    cout<<atrib;
    letra = getch();
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
        letra = getch();
    }
    strcpy(atrib,palabra.c_str());
}


void caratula();
void cuadrado();
void triangulo();
void triangulo2();

/* int main(){
    triangulo2();
    triangulo();
    catarula();
    cout<<endl<<endl<<endl;

    return 0;
} */

void caratula(){
    triangulo2();
    triangulo();
    cuadrado();
    system("pause");
    system("cls");
} 

void triangulo(){
    gotoxy(1,12);cout<<"\262\262\262\262\262\262\262\262\262";
    gotoxy(3,13);cout<<"\262\262\262\262\262\262\262";
    gotoxy(5,14);cout<<"\262\262\262\262\262";
    gotoxy(7,15);cout<<"\262\262\262";
//.......               
    gotoxy(11,17);cout<<"\262\262\262\262\262\262\262\262\262"; 
    gotoxy(13,18);cout<<"\262\262\262\262\262\262\262";
    gotoxy(15,19);cout<<"\262\262\262\262\262";
    gotoxy(17,20);cout<<"\262\262\262";
//----------
    gotoxy(21,7);cout<<"\262\262\262\262\262\262\262\262\262"; 
    gotoxy(23,8);cout<<"\262\262\262\262\262\262\262";
    gotoxy(25,9);cout<<"\262\262\262\262\262";
    gotoxy(27,10);cout<<"\262\262\262";
    gotoxy(29,11);cout<<"\262";
}

void triangulo2(){
    gotoxy(9,11);cout<<"\262\262\262\262\262\262\262\262\262"; 
    gotoxy(9,10);cout<<"\262\262\262\262\262\262\262";
    gotoxy(9,9);cout<<"\262\262\262\262\262";
    gotoxy(9,8);cout<<"\262\262\262";
    //..........
    gotoxy(18,16);cout<<"\262\262\262\262\262\262\262\262\262"; 
    gotoxy(18,15);cout<<"\262\262\262\262\262\262\262";
    gotoxy(18,14);cout<<"\262\262\262\262\262";
    gotoxy(18,13);cout<<"\262\262\262";
    //.........
    gotoxy(1,21);cout<<"\262\262\262\262\262\262\262\262\262"; 
    gotoxy(1,20);cout<<"\262\262\262\262\262\262\262";
    gotoxy(1,19);cout<<"\262\262\262\262\262";
    gotoxy(1,18);cout<<"\262\262\262";
    gotoxy(1,17);cout<<"\262";

}
/* void triangulo(){
    gotoxy();
} */
void cuadrado(){
    //CUADRADO
    for(int i=1;i<10;i++){                     // cantidad de asteriscos
        for(int j=7;j<12;j++){               //cantidad filas
            gotoxy(i,j);cout<<"\262";
        }
    }
    //CUADRADO DEL MEDIO
    for(int i=10;i<20;i++){                     // cantidad de asteriscos
        for(int j=12;j<17;j++){               //cantidad filas
            gotoxy(i,j);cout<<"\262";
        }
    }
     //CUADRADO DEL ABAJO
    for(int i=20;i<30;i++){                     // cantidad de asteriscos
        for(int j=17;j<22;j++){               //cantidad filas
            gotoxy(i,j);cout<<"\262";
        }
    }
//g++ -o CARATULA2.exe CARATULA2.cpp.

/* for(int i=1;i<15;i++){                     // cantidad de asteriscos
        for(int j=7;j<13;j++){               //cantidad filas
            gotoxy(i,j);cout<<"*";
        }*/
    } 