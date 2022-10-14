#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

void printMatrix(vector<vector<int>> matrizAdj){
for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<matrizAdj[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n = 0;
    //cin>>n;

    vector<vector<int>> matrizAdj;
    /*for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            int num = 0;
            cin>>num;
            row.push_back(num);
        }
        matrizAdj.push_back(row);
    }*/

    matrizAdj = {
                {0,2,-1,3},
                {-1,0,1,5},
                {2,3,0,-1},
                {3,-1,4,0}
                }; 

    printMatrix(matrizAdj);

    Graph grafo(matrizAdj);

    grafo.dijkstra(1);
    //grafo.dijkstra(1);
    //grafo.dijkstra(2);
    //grafo.dijkstra(3);

    
    return 0;
}