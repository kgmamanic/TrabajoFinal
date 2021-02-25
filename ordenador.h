 // Ordena listas: Quicksort e inserccion

template<class clases>
void quickshortDes(clases A[],int inicio,int fin){
    if(fin <= inicio){
        return;
    }
    int j,pivote=inicio,i = 1;
    clases aux;
    while(pivote+i<=fin){
        if(A[pivote]<A[pivote+i]){
            aux = A[pivote+i];
            j = i + pivote;
            while(pivote <j){
                A[j] = A[j-1];
                j--;
            }
            A[pivote] = aux;
            pivote = pivote + 1;     
        }else{
            i = i +1;
        }
    }

    quickshortDes(A,inicio,pivote-1);
    quickshortDes(A,pivote+1,fin);
}
template<class clases>
void quickshortDes(clases A[],int &nu){
    //nu = nu-1;
    quickshortDes(A,1,nu);
}