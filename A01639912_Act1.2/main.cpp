// Implementación de algoritmos avaros y programación dinámica 
// en el problema de cambio de monedas
// Ruy Guzmán Camacho A01639912
// 30/08/2022

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n)
// Algoritmo Avaro
vector<int> greedyCoins(vector<int> coins,int remaining_P){

    vector<int>result;

    if(remaining_P < coins.back()){
        result.assign(coins.size(),0);
    } else {
        for (int i = 0; i < coins.size(); i++){
            int amount = remaining_P / coins[i];
            remaining_P = remaining_P % coins[i];
            result.push_back(amount);
        } 
    }

    return result;

}

// O(n)
// Algoritmo mediante programación dinámica
vector<int> dynamicCoins(vector<int> coins,int remaining_P){

    vector<int> dynamic (remaining_P+1,-1);
    vector<int> usedIndex (remaining_P+1,-1);
    vector<int> result(coins.size(),0);

    dynamic[0] = 0; 
    usedIndex[0] = 0;
    if(remaining_P < coins.back()){
        result.assign(coins.size(),0);
    } else {
        for (int i = 1; i < remaining_P+1;i++){
            int j = 0;
            for (int coin: coins){
                if(dynamic[i-coin] != -1){
                    if(i - coin >= 0){
                        if(dynamic[i] == -1 || dynamic[i] > dynamic[i-coin]+1){ 
                            dynamic[i] = dynamic[i-coin]+1;
                            usedIndex[i] = j;
                        }
                    }
                }
                j++;
            }
        }

        while(remaining_P > 0){
            result[usedIndex[remaining_P]] += 1;
            remaining_P -= coins[usedIndex[remaining_P]];
        }
    }
    return result;
    
}

// Mostrar resultados
void printVector(vector<int> &coins,vector<int> &res){

    int total = 0;
    cout<<"-----------------------------------\n\n";
    for(int i = 0; i < coins.size();i++){
        for(int j = 0; j < res[i]; j++){
            cout<<coins[i]<<"\n";
        }
        total += res[i];
    }
    cout<<"\nModenas utilizadas: "<<total<<"\n";
    cout<<"\n-----------------------------------\n";

}

int main(){

    vector<int> coins;
    vector<int> grCoins;
    vector<int> dyCoins;
    int N;
    int P;
    int Q;
    cout<<"Cantidad de denominaciones: ";
    cin>>N;

    if (N <= 0){
        cout<<"Cantidad de denominaciones Invalida\n";
        return 0;
    }
    
    for (int i = 0; i < N; i++){
        int temp;
        cout<<"coins["<<i<<"]:";
        cin>>temp;

        coins.push_back(temp);
    }

    sort(coins.begin(), coins.end(), greater<int>());
    cout<<"Precio:";
    cin>>P;

    cout<<"Pago:";
    cin>>Q;

    int remaining_P = Q-P;

    grCoins = greedyCoins(coins,remaining_P);
    dyCoins = dynamicCoins(coins,remaining_P);
    cout<<"\nAlgoritmo Avaro:\n";
    printVector(coins,grCoins);
    cout<<"\nProgramacion Dinamica:\n";
    printVector(coins,dyCoins);

    return 0;

}