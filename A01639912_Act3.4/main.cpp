/*
Actividad 3.4 Implementación de "Graph coloring"
Ruy Guzmán Camacho A01639912
19/10/2022
*/
#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

void printMatrix(vector<vector<int>> matrizAdj,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrizAdj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> matrizAdj;
    for (int i = 0; i < n; i++){
        vector<int> row;

        for (int j = 0; j < n; j++){
            int num = 0;
            cin >> num;
            row.push_back(num);
        }
        
        matrizAdj.push_back(row);
    }
    cout<<"\n";

    printMatrix(matrizAdj,n);
    
    //Construye un grafo con una amtriz de adyacencia
    Graph grafo(matrizAdj);

    //La función recibe la cantidad máxima de colores a utilizar
    grafo.coloring(2);
    return 0;
}