/*
Actividad 3.2 Implementación de "Dijkstra and Floyd"
Ruy Guzmán Camacho A01639912
Luis David lópez Magaña A00344656
14/10/2022

*/
#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

void printMatrix(vector<vector<int>> matrizAdj)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrizAdj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<vector<int>> matrizAdj;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int num = 0;
            cin >> num;
            while(num < -1){
                cout<<"No ingrese negativos (solo -1 en caso de que no haya conexión)\n";
                cin >> num;
            }
            row.push_back(num);
        }
        matrizAdj.push_back(row);
    }
    cout<<"\n";

    printMatrix(matrizAdj);
    Graph grafo(matrizAdj);

    cout<<"\nDijkstra :"<<endl;
    
    for(int i = 0; i < n; i++){
        grafo.dijkstra(i);
    }
    
    cout<<"\n";

    grafo.floyd(n);
    return 0;
}