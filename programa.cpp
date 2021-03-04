#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

#include"Clases/Escuela.h"
#include"Clases/Facultad.h"
#include"Clases/Postulante.h"


using namespace std;

#include"Extras.h"

#include "buscardor.h"
#include "ordenador.h"
// Recibe como parametros los contadores de cada clase
void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P);

template<class a>
void leer(a tipo[],int &contador,string nombre,int size){
    int cantidad;
    ifstream archivo("data/" + nombre+".dat",ios::binary);
    do{
        archivo.read((char*)&tipo[contador],size);
        cantidad = archivo.gcount();
        if(cantidad == size){
            contador = contador +1;
        }
    }while(cantidad == size);
    archivo.close();
    //contador = contador -1;
    //return n;
}

template<class a>
void guardar(a tipo[],int &n,string nombre,int size){
    int contadorg = 0;
    ofstream archivo("data/" + nombre+".dat",ios::trunc|ios::binary);
    do{
        archivo.write((char*)&tipo[contadorg],size);
        contadorg = contadorg+1;
    }while(contadorg <= n);
    archivo.close();
}


int main(){
    //caratula();
    // Declaracion de los objetos
    Postulante PPos[100];
    Asignatura AAsi[100];
    Escuela EEsc[100];
    Facultad FFacu[100];
    Estudiante EEstu[100];
    // variables temporales
    int nEstudiante,temp2;
    char codigotemp[7],passtemp[20],nuevoEstu;

    // Declaracion de Contadores
    int contP=0,contA=0,contEsc=0,contF=0,contEst=0;
    
    // abrir archivos y recolectar datos
    leer(FFacu,contF,"Facultades",sizeFacultad);
    leer(EEsc,contEsc,"Escuelas",sizeEscuela);
    leer(PPos,contP,"Postulantes",sizePostulante);
    leer(AAsi,contA,"Asignaturas",sizeAsignatura);
    leer(EEstu,contEst,"Estudiantes",sizeEstudiante);
    
    string titulomenu,opcionesEstu[] = {"Realizar Matricula", "Ver Horario" , "Ver info"};
    string opcionesmenu[] = {"Estudiante" , "Postulante","Visualizar","Administrador","Salir"};
    string menuVisu[] = {"Facultades", "Escuelas", "Resultados de Examenes","Volver"};
    string visu[] = {"Facultades", "Escuelas" , "Asignaturas", "Estudiantes" , "Postulantes", "Volver"};
    string contrasenia,tempEstudiante,tempCodigo;
    bool NoSalir = true; // para salir del bucle del menu
    int seleccion,seleccion2;

    system("cls");
    do{
        //MessageBox(0,"¿Guardar cambios?", "Título", MB_YESNO | MB_ICONQUESTION);
        tempEstudiante = "";
        titulomenu = {"Menu principal"};
        seleccion = Menu(titulomenu,opcionesmenu,5);
        titulomenu = opcionesmenu[seleccion-1];
        switch(seleccion){
            case 1:
            // Solicitara usuario y contraseña usuario:(SIGLAS DE ESCUELA)+(codigo)
                system("cls");
                cuadro();
                gotoxy(45,17); cout<<"ESTUDIANTE: ingrese usuario y contrase\244a";
                gotoxy(40,21); cout<<"Codigo:";
                Pequecuadro(49, 20);
                gotoxy(40, 25); cout<<"Password:";  //lagarto
                Pequecuadro(49,24);
                // ingresar datos
                gotoxy(50,21);
                fflush(stdin);cin.getline(codigotemp,7);
                gotoxy(50,25);
                clave(passtemp);
                nEstudiante = usuario(EEstu,contEst,codigotemp,passtemp); 
                gotoxy(40, 28);
                if(nEstudiante != 0){
                    cout<<"Correcto... Iniciando Sesion";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    system("cls");
                    cuadro();
                    gotoxy(45,17);
                    // append concatena strings
                    tempEstudiante.append("Bienvenido ");
                    tempEstudiante.append(EEstu[nEstudiante].getNombre());
                    temp2 = Menu(tempEstudiante,opcionesEstu,3);
                    switch(temp2){
                        case 1: // realizar matricula
                        case 2: // ver horario
                        case 3: // verinfo
                            system("cls");
                            cuadro();
                            gotoxy(45,17);
                            cout<<"-------INFORMACION DE ESTUDIANTE--------";
                            gotoxy(45,19);
                            cout<<"Nombre: "<<EEstu[nEstudiante].getNombre();
                            gotoxy(45,20);
                            cout<<"Apellidos: "<<EEstu[nEstudiante].getApe();
                            gotoxy(45,21);
                            cout<<"Codigo: "<<EEstu[nEstudiante].getCod();
                            gotoxy(45,22);
                            cout<<"Escuela: "<<EEstu[nEstudiante].obtenerSiglas();
                            gotoxy(38,25);
                            system("pause");
                            break;
                    }
    
                }else{
                    cout<<"Incorrecto... Volviendo a Menu Principal";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                    Sleep(500); cout<<".";
                }
                break;
            case 2:
                // 2 opciones buscar por nombre 
                system("cls");
                cuadro();
                gotoxy(45,17);
                cout<<"Postulante: VERIFICAR INGRESO";
                gotoxy(27,19);
                cout<<"Codigo de Postulante";Pequecuadro(47,18);
                gotoxy(48,19);
                fflush(stdin);cin.getline(codigotemp,7);
                temp2 = Buscar(PPos,contP,codigotemp);
                if(temp2 != 0){
                    if(PPos[temp2].Ingresante()){
                        gotoxy(40,22);
                        cout<<"Felicidades...Ingresaste, Puntaje: "<<PPos[temp2].getPunt();
                        Sleep(3000);
                        system("cls");
                        cuadro();
                        gotoxy(45,17);
                        cout<<"Sus datos seran estos.!";
                        gotoxy(40,20);
                        cout<<"Nombre:";Pequecuadro(47,19);
                        gotoxy(37,23);
                        cout<<"Apellidos:"; Pequecuadro(47,22);
                        gotoxy(28,26);
                        cout<<"Codigo:(Ejm 20-001):";Pequecuadro(47,25);
                        gotoxy(36,29);
                        cout<<"Contrase\244a:";Pequecuadro(47,28);
                        contEst = contEst +1;
                        // ingresar datos
                        gotoxy(48,20);
                        cout<<PPos[temp2].getNombre();
                        gotoxy(48,23);
                        cout<<PPos[temp2].getApe();
                        gotoxy(48,26);
                        tempEstudiante = "";
                        tempEstudiante.append("20-");
                        tempEstudiante.append(to_string(contEst));
                        cout<<PPos[temp2].getCod();
                        gotoxy(48,29);
                        fflush(stdin); cin.getline(passtemp,20);
                        for(int j = 1; j <= contEsc; j++){
                            if(PPos[temp2].obtenerSiglas()== EEsc[j].getSiglas()){
                                nuevoEstu = j;
                                j = contEsc+1;
                            }
                        }
                        EEstu[contEst].asignarDatos(PPos[temp2].getNombre(),PPos[temp2].getApe(),PPos[temp2].getCod(),EEsc[nuevoEstu].getSiglas(),passtemp);
                        gotoxy(40,31);
                        system("pause");
                    }
                }else{
                    gotoxy(42,22);
                    cout<<"ERROR... VERIFIQUE EL CODIGO";
                    Sleep(2000);
                }
                break;
            case 3:
                // se usara para mostrar datos generales de las escuelas y facultades
                seleccion2 = Menu(titulomenu,visu,4);
                system("cls");
                cuadro();
                gotoxy(45,17);
                switch(seleccion2){
                    case 1:
                        cout<<"Facultades: ";
                        Lista(FFacu,contF);
                        break;
                    case 2:
                        cout<<"Escuelas: ";
                        Lista(EEsc,contEsc);
                        break;
                    case 3:
                        temp2 = MenuEF("Seleccione Una escuela",EEsc,contEsc);
                        system("cls");
                        cuadro();
                        gotoxy(45,17);
                        cout<<"Asignaturas";
                        for(int i = 1; i <= EEsc[temp2].nCursos;i++){
                            gotoxy(45,18+i);
                            cout<<EEsc[temp2].asignaturas[i]->getNombre();
                        }
                        gotoxy(45,35);
                        system("pause");
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
                gotoxy(40, 25); cout<<"Password:";  //lagarto
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
    guardar(FFacu,contF,"Facultades",sizeFacultad);
    guardar(EEsc,contEsc,"Escuelas",sizeEscuela);
    guardar(PPos,contP,"Postulantes",sizePostulante);
    guardar(AAsi,contA,"Asignaturas",sizeAsignatura);
    guardar(EEstu,contEst,"Estudiantes",sizeEstudiante);
}

void administrador(Facultad Facu[],Escuela escu[],Asignatura asig[],Estudiante estu[],Postulante postu[],int &F,int &Esc, int &A,int &Est,int &P){
    int opcion,opcion2,nSEscuela,nFacu,variabletemp=20; 
    system("cls");
    bool seguir();
    // Variables Temporales
    char nombre[40],apellido[30],codigo[7],pass[15],SSiglas[5],Docentes[3][40];
    float puntaje;
    int nDocentes,vacantes;
    int temp,temp2;
    // menus
    string nombremenu = "Bienvenido, Administrador";
    string opciones[] = {"Modificar","Eliminar","Agregar","Volver"};
    string op2[] = {"Facultades", "Escuelas" , "Asignaturas", "Estudiantes" , "Postulantes", "Volver"};
    opcion = Menu(nombremenu,opciones, 4);
    switch(opcion){
        case 1:
            opcion2 = Menu("ADMINISTRADOR: modificar", op2, 6);
                switch(opcion2){
                    case 1: // Facultades
                        temp = MenuEF("Seleccion Facultad a Modificar",Facu,F);
                        system("cls");
                        cuadro();
                        gotoxy(55,17);
                        cout<<"MODIFICAR FACULTAD";
                        gotoxy(40,20);
                        cout<<"NOMBRE:";
                        Pequecuadro(47,19);
                        strcpy(nombre,Facu[temp].getNombre());
                        gotoxy(48,20);
                        modificar(nombre);
                        Facu[temp].asignarDatos(nombre);
                        break;
                    case 2: // Escuelas
                        temp = MenuEF("Selccion Escuela a Modificar",escu,Esc);
                        system("cls");
                        cuadro();
                        gotoxy(55,17);
                        cout<<"MODIFICAR ESCUELA";
                        gotoxy(40,20);
                        cout<<"Nombre"; Pequecuadro(47,19);
                        gotoxy(38,23);
                        cout<<"Vacantes:";Pequecuadro(47,22);
                        gotoxy(40,26);
                        cout<<"Siglas:";Pequecuadro(47,25);
                        strcpy(nombre,escu[temp].getNombre());
                        strcpy(SSiglas,escu[temp].getSiglas());
                        // modificar
                        gotoxy(48,20);
                        modificar(nombre);
                        gotoxy(48,23);
                        cin>>vacantes;
                        gotoxy(48,26);
                        modificar(SSiglas);
                        escu[temp].asignarDatos(nombre,vacantes,SSiglas);
                        break;
                    case 3: // Asignaturas
                        fflush(stdin); 
                        system("cls");
                        cuadro();
                        gotoxy(55,17);
                        cout<<"MODIFICAR POSTULANTE";
                        gotoxy(40,20);
                        cout<<"Codigo:";
                        Pequecuadro(47,19);
                        gotoxy(48,20);
                        cin.getline(codigo,7);
                        temp = Buscar(asig,A,codigo);
                        if(temp != 0){
                            system("cls");
                            cuadro();
                            gotoxy(55,17);
                            cout<<"MODIFICAR ASIGNATURA";
                            gotoxy(40,20);
                            cout<<"Nombre:";Pequecuadro(47,19);
                            gotoxy(38,23);
                            cout<<"Codigo:";Pequecuadro(47,22);
                            strcpy(nombre,asig[temp].getNombre());
                            strcpy(codigo,asig[temp].getCod());
                            gotoxy(48,20);
                            modificar(nombre);
                            gotoxy(48,23);
                            modificar(codigo);
                            system("cls");
                            asig[temp].modAsignatura(nombre,codigo);
                        }
                        break; 
                    case 4: // Estudiantes
                        system("cls");
                        cuadro();
                        gotoxy(55,17);
                        cout<<"MODIFICAR ESTUDIANTE";
                        gotoxy(40,20);
                        cout<<"Codigo:";
                        Pequecuadro(47,19);
                        gotoxy(48,20);
                        cin.getline(codigo,7);
                        temp = Buscar(estu,Est,codigo);
                        if(temp != 0){
                            system("cls");
                            cuadro(); 
                            gotoxy(55,17); cout<<"MODIFICAR ESTUDIANTE";
                            gotoxy(40,20);
                            cout<<"Nombre:";Pequecuadro(47,19);
                            gotoxy(37,23);
                            cout<<"Apellidos:"; Pequecuadro(47,22);
                            gotoxy(28,26);
                            cout<<"Codigo:(Ejm 20-001):";Pequecuadro(47,25);
                            gotoxy(36,29);
                            cout<<"Contrase\244a";Pequecuadro(47,28);
                            strcpy(nombre,estu[temp].getNombre());
                            strcpy(apellido,estu[temp].getApe());
                            strcpy(codigo,estu[temp].getCod());
                            strcpy(pass,estu[temp].getcontrasena());
                            // ingresar datos
                            gotoxy(48,20);
                            modificar(nombre);
                            gotoxy(48,23);
                            modificar(apellido);
                            gotoxy(48,26);
                            modificar(codigo);
                            gotoxy(48,29);
                            modificar(pass);
                            system("cls");
                            estu[temp].asignarDatos(nombre,apellido,codigo,estu[temp].obtenerSiglas(),pass);
                        }
                        break;  
                    case 5:
                        fflush(stdin); 
                        system("cls");
                        cuadro();
                        gotoxy(55,17);
                        cout<<"MODIFICAR POSTULANTE";
                        gotoxy(40,20);
                        cout<<"Codigo:";
                        Pequecuadro(47,19);
                        gotoxy(48,20);
                        cin.getline(codigo,7);
                        temp = Buscar(postu,P,codigo);
                        if(temp != 0){
                            system("cls");
                            cuadro();
                            gotoxy(55,17); cout<<"MODIFICAR POSTULANTE";
                            gotoxy(40,20);
                            cout<<"Nombre:";Pequecuadro(47,19);
                            gotoxy(37,23);
                            cout<<"Apellidos:"; Pequecuadro(47,22);
                            gotoxy(28,26);
                            cout<<"Codigo:(Ejm 20-001):";Pequecuadro(47,25);
                            strcpy(nombre,postu[temp].getNombre());
                            strcpy(apellido,postu[temp].getApe());
                            strcpy(codigo,postu[temp].getCod());
                            // ingresar datos
                            gotoxy(48,20);
                            modificar(nombre);
                            gotoxy(48,23);
                            modificar(apellido);
                            gotoxy(48,26);
                            modificar(codigo);
                            gotoxy(48,29);
                            system("cls");
                            temp2 = MenuEF("Seleccion la escuela",escu,Esc);
                            postu[temp].asignarDatos(nombre,codigo,escu[temp2].getSiglas(),apellido,puntaje);
                        }else{
                            system("cls");
                            cuadro(); 
                            gotoxy(55,17); cout<<"NO SE HA ENCONTRADO AL POSTULANTE";
                        }
                        break;
                }
            break;
        case 2:
            opcion2 = Menu("ADMINISTRADOR: Eliminar", op2, 6);
            switch(opcion2){

            }
            break;
        case 3:
            opcion2 = Menu("ADMINISTRADOR: Agregar", op2, 6);
            switch(opcion2){
                case 1: // agregar facultades
                    system("cls");
                    cuadro();
                    gotoxy(55,17);cout<<"AGREGAR FACULTAD";
                    gotoxy(40,20);
                    cout<<"Nombre:";Pequecuadro(47,19);
                    gotoxy(48,20);
                    fflush(stdin); cin.getline(nombre,20);
                    F = F+1;
                    Facu[F].asignarDatos(nombre);
                    gotoxy(35,25);cout<<"FACULTAD CREADA CON EXITO..";
                    gotoxy(35,26);cout<<"Cree una Escuela para la Facultad";
                    Sleep(2000);
                    system("cls");
                    Facu[F].crearEscuela(escu,Esc);
                    break;
                case 2: // agregar escuelas - DESARROLLADO
                    system("cls");
                    nFacu = MenuEF("Crear Escuela: SELECCION FACULTAD", Facu,F);
                    Facu[nFacu].crearEscuela(escu,Esc);
                    break;

                case 3:// agregar asignaturas
                    system("cls");
                    cuadro();
                    gotoxy(55,17);
                    cout<<"AGREGAR ASIGNATURA";
                    gotoxy(40,20);
                    cout<<"Nombre:";Pequecuadro(47,19);
                    gotoxy(40,23);
                    cout<<"Codigo:";Pequecuadro(47,22);
                    gotoxy(35,26);
                    cout<<"N° Docentes:";Pequecuadro(47,25);
                    // ingresar datos
                    gotoxy(48,20);
                    fflush(stdin);cin.getline(nombre,40);
                    gotoxy(48,23);
                    fflush(stdin);cin.getline(codigo,7);
                    gotoxy(48,26);
                    cin>>nDocentes;
                    system("cls");
                    cuadro();
                    gotoxy(55,17);
                    cout<<"DOCENTES: "<<nombre;
                    for(int i = 0; i <nDocentes; i++){
                        //if((nDocentes) != i){
                            gotoxy(37,variabletemp);
                            cout<<"Nombre N\370"<<i+1; Pequecuadro(47,variabletemp-1);
                            gotoxy(48,variabletemp);
                            fflush(stdin);cin.getline(Docentes[i],40);
                            variabletemp = variabletemp +3;
                        //}
                    }
                    variabletemp = 20;
                    A = A+1;
                    temp2 = MenuEF("Seleccion la escuela",escu,Esc);
                    asig[A].asignarDatos(nombre,codigo,Docentes,nDocentes,&escu[temp2]);
                    escu[temp2].AgregarAsi(&asig[A]);
                    break;
                case 4: // Agregar Estudiante 
                    system("cls");
                    cuadro(); 
                    gotoxy(55,17); cout<<"AGREGAR ESTUDIANTE";
                    gotoxy(40,20);
                    cout<<"Nombre:";Pequecuadro(47,19);
                    gotoxy(37,23);
                    cout<<"Apellidos:"; Pequecuadro(47,22);
                    gotoxy(28,26);
                    cout<<"Codigo:(Ejm 20-001):";Pequecuadro(47,25);
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
                    system("cls");
                    nSEscuela = MenuEF("Seleccione la Escuela",escu,Esc);
                    Est = Est +1;
                    estu[Est].asignarDatos(nombre,apellido,codigo,escu[nSEscuela].getSiglas(),pass);
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
                    cout<<"Codigo(Ejm 100001):"; Pequecuadro(47,25);
                    gotoxy(39,29);
                    cout<<"Puntaje:"; Pequecuadro(47,28);
                    // Ingresar Datos
                    gotoxy(48,20);
                    fflush(stdin); cin.getline(nombre,20); // nombre
                    gotoxy(48,23);
                    fflush(stdin); cin.getline(apellido,30); // apellidos
                    gotoxy(48,26);
                    fflush(stdin); cin.getline(codigo,sizeof(codigo));
                    gotoxy(48,29);
                    fflush(stdin); cin>>puntaje;
                    P = P+1; // contador de postulantes                    
                    temp = MenuEF("Seleccion a que escuela postula",escu,Esc); // eliminar 
                    postu[P].asignarDatos(nombre,codigo,escu[temp].getSiglas(),apellido,puntaje);
                    // Ordena los postulantes
                    quickshortDes(postu,P);
                    temp2 = Puesto(postu,postu[P],P);
                    if(escu[temp].getVacantes()>= temp2){
                        postu[P].asignarOrden(temp2,true);
                    }else{
                        postu[P].asignarOrden(temp2,false);
                    }
                    break;
            }
            break;
        default: return;
    }
    administrador(Facu,escu,asig,estu,postu,F,Esc,A,Est,P);
}

//  g++ -o programa.exe programa.cpp