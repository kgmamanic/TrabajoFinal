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
// busca recibe como parametro un arreglo de clase, numero elementos en el arreglo y el codigo a buscarw
template <class clase>
int Buscar(clase A[], int n, char t[]){
    int opcion;
    for(int i = 1; i<=n;i++){
        // compara 2 elementos a == A
        if(strcoll(A[i].getCod(), t)==0){
            opcion = i;
            i = n+1;
        }else{
            opcion = 0;
        }
    }
    return opcion;
}
template <class clase>
int usuario(clase A[],int n, char co[],char pass[]){
    int usuario = Buscar(A,n,co);
    // strcmp compara 2 elementos a != A
    if(strcmp(A[usuario].getcontrasena(),pass)==0){
        return usuario;
    }else{
        return 0;
    }
}