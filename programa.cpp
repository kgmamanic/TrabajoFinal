#include <iostream>
#include <conio.h>

#include "Extras.h"

using namespace std;

int main(){
    system("cls");
    cuadro();
    //system("pause");
    getch();
    //MessageBox(0,"¿Guardar cambios?", "Título", MB_YESNO | MB_ICONQUESTION);
    int a = Menu();
}

//  g++ -o programa.exe programa.cpp 