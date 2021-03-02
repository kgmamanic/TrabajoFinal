// Busca#r por separado

#pragma "Extras.h"

template <class clase>
int Lista(clase A[], int n){ //
    string lista[n];
    char temp[60];
    for(int i = 0; i < n;i++){
        strcpy(temp,A[i+1].getNombre());
        lista[i] = temp;
    }
    int opcion = Menu("Seleccione:",lista,n);
    return opcion;
}

template <class clase>
int Buscar(clase A, int n, char t[]){
    int opcion;
    for(int i = 1; i<=n;i++){
        if(strcoll(A->getcod(), t)==0){
            opcion = i;
            break;
        }else{
            opcion = 0;
        }
    }
    return opcion;
}