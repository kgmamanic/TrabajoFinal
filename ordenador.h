 // Ordena listas: Quicksort e inserccion

template<class clases>
void quickshort(clases A[],int inicio,int fin){
    if(fin <= inicio){
        return;
    }
    int aux,j,pivote=inicio,i = 1;
    while(pivote+i<=fin){
        if(A[pivote]>A[pivote+i]){
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
    for(int i = 0; i<=fin; i++){ // imprime solo para 
        cout<<A[i];
        if(i!=fin){
            cout<<", ";
        }
    }
    cout<<endl;
    quickshort(A,inicio,pivote-1);
    quickshort(A,pivote+1,fin);
}
template<class clases>
void quickshort(clases A[],int &nu){
    nu = nu-1;
    quickshort(A,0,nu);
}