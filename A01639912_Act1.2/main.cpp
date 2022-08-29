#include <iostream>
#include <vector>
using namespace std;

vector<int> greedyCoins(vector<int> coins,int remaining_P){
    vector<int>result;

    for (int i = 0; i < coins.size(); i++){
        int amount = remaining_P / coins[i];
        remaining_P = remaining_P % coins[i];
        result.push_back(amount);
    }

    return result;
}

vector<int> dynamicCoins(){
    
}

void printVector(vector<int> &coins,vector<int> &res){
    cout<<"-----------------------------------\n";
    for(int i = 0; i < coins.size(); i++){
        cout<<coins[i]<<"\t";
    }
    cout<<"\n\n";

    for(int i = 0; i < coins.size(); i++){
        cout<<res[i]<<"\t";
    }
    cout<<"\n-----------------------------------\n";

}

int main(){
    vector<int> coins;
    vector<int> grCoins;
    vector<int> dyCoins;
    int N;
    int P;
    int Q;
    cout<<"Cantidad de denominaciones:";
    cin>>N;
    
    for (int i = 0; i < N; i++){
        int temp;
        cout<<"coins[0]: ";
        cin>>temp;

        coins.push_back(temp);
        grCoins.push_back(0);
        dyCoins.push_back(0);

    }

    cout<<"Precio:";
    cin>>P;

    cout<<"Pago:";
    cin>>Q;

    int remaining_P = P-Q;

    grCoins = greedyCoins(coins,remaining_P);
    
    printVector(coins,grCoins);

    return 0;
}