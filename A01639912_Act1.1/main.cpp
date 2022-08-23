// Ruy Guzmán Camacho A01639912

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double> &lista,int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    vector<double> left;
    vector<double> right;

    int i = 0;
    int j = 0;

    for(i = 0; i<n1;i++) left.push_back(lista[l+i]);
    for(j = 0; j<n2;j++) right.push_back(lista[m+1+j]);

    int k = l;
    i = 0;
    j = 0;

    while (i < n1 && j < n2){
        if (left[i] >= right[j]){
            lista[k] = left[i];
            i++;
        }else{
            lista[k] = right[j];
            j++;
        }
        k ++;
    }

    while(i<n1){
        lista[k] = left[i];
        i++;
        k++;
    }

    while(j<n2){
        lista[k] = right[j];
        j++;
        k++;
    }
    

}

// O(n log n)
void mergeSort(vector<double> &lista, int l, int r){
    
    int mid = (l+r)/2;

    if(l < r){
        mergeSort(lista,l,mid);
        mergeSort(lista,mid+1,r);
        merge(lista,l,mid,r);
    }

    
}

int main(){
    int n;
    cout<<"Cantidad de numeros a ordenar: ";
    cin>>n;

    if (n < 0){
        cout<<"No se puede generar una lista de menos que 0 elementos\n";
        return 0;
    }

    vector<double> numeros;
    cout<<"Ingrese los numeros (uno por linea):\n";

    // Ingresar números
    for(int i = 0; i < n; i++){
        double num;
        cout<<"Numero["<<i+1<<"]: ";
        cin>>num;
        numeros.push_back(num);  
    }

     // mostrar resultados
    cout<<"\nOriginal --------------------------\n\n[";
    for(int i = 0; i < n; i++){
        cout<<numeros[i]<<",";
    }
    cout<<"]\n";

    // ordenamiento
    mergeSort(numeros,0,n-1);

    // mostrar resultados
    cout<<"\nResultado --------------------------\n\n[";
    for(int i = 0; i < n; i++){
        cout<<numeros[i]<<",";
    }
    cout<<"]\n";
    cout<<"\n------------------------------------\n\n";

    return 0;
}