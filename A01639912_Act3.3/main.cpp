/*
Actividad 3.3 Implementación de knapsack problem
Ruy Guzmán Camacho A01639912
18/10/2022 
*/
#include <iostream>
#include <vector>
using namespace std;

//función que calcula la ganancia máxima
//O(N*W) N siendo la cantidad de elementos y W capacidad de la mochila
int knapsack(vector<int> values,vector<int> weights, int W, int N){
    vector<int>row(W+1,0);
    vector<vector<int>> matrix(N+1,row);

    for(int i = 1; i <N+1; i++){
        int current_w = weights[i-1];
        int current_V = values[i-1];
        
        for(int j = 1; j < W+1;j++){
            matrix[i][j] = matrix[i-1][j];
            if(j >= current_w && matrix[i-1][j-current_w] + current_V > matrix[i][j])
                matrix[i][j] = matrix[i-1][j-current_w] + current_V;
        }
    }

    return matrix[N][W];
}

int main(){
    int N = 0;
    int W = 0;
    vector<int> values;
    vector<int> weights;

    cout<<"\nCantidad de elementos";
    cin>>N;
    cout<<"\nValores:"<<endl;
    for(int i = 0; i<N; i++){
        int num;
        cin>>num;
        values.push_back(num);
    }

    cout<<"\nPesos:"<<endl;
    for(int i = 0; i<N; i++){
        int num;
        cin>>num;
        weights.push_back(num);
    }

    cout<<"\nCapacidad:";
    cin>>W;

    cout<<"\nGanacia Máxima:"<<knapsack(values,weights,W,N)<<endl;
    return 0;
}