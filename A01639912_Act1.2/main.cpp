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

vector<int> dynamicCoins(vector<int> coins,int remaining_P){
    vector<int> dynamic (remaining_P+1,-1);
    vector<int> used (remaining_P+1,-1);
    vector<int> results(coins.size(),0);

    dynamic[0] = 0; 
    used[0] = 0;

    for (int i = 1; i < remaining_P+1;i++){
        
        int j = 0;
        for (int coin: coins){
            if(i - coin >= -1){
                if(dynamic[i] == -1 || dynamic[i] > dynamic[i-coin]+1){ 
                    dynamic[i] = dynamic[i-coin]+1;
                    used[i] = coin;
                    results[j] += 1;
                }
            }
            j++;
        }
    }
    cout<<dynamic[remaining_P];
    return results;
}

void printVector(vector<int> &coins,vector<int> &res){
    int total = 0;
    cout<<"-----------------------------------\n\n";
    for(int i = 0; i < coins.size(); i++){
        cout<<coins[i]<<"\t";
    }
    cout<<"\n\n";

    for(int i = 0; i < coins.size(); i++){
        cout<<res[i]<<"\t";
        total += res[i];
    }
    cout<<"\n\nModenas utilizadas: "<<total<<"\n";
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
        cout<<"coins["<<i<<"]:";
        cin>>temp;

        coins.push_back(temp);
        grCoins.push_back(0);
        dyCoins.push_back(0);

    }

    cout<<"Precio:";
    cin>>P;

    cout<<"Pago:";
    cin>>Q;

    int remaining_P = Q-P;

    grCoins = greedyCoins(coins,remaining_P);
    dyCoins = dynamicCoins(coins,remaining_P);
    cout<<"\nAlgoritmo Avaro:\n";
    printVector(coins,grCoins);
    cout<<"\nProgramación Dinámica:\n";
    printVector(coins,dyCoins);

    return 0;
}