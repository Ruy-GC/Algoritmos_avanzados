// Implementación de Tries
// Ruy Guzmán Camacho A01639912
// 10/10/2022

#include "trie.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Trie trie;
    int N = 0;
    int M = 0;
    vector<string> searchWords;
    
    cout<<"-----------------------------------\n";
    cin>>N;

    for(int i = 0; i < N; i++){
        string temp;
        cout<<i+1<<": ";
        cin>>temp;
        trie.insert(temp);
    }
    cout<<"-----------------------------------\n";

    cin>>M;

    for(int i = 0; i < M; i++){
        string temp;
        cout<<i+1<<": ";
        cin>>temp;
        searchWords.push_back(temp);
    }
    cout<<"\nRecorrido DFS----------------------\n";
    trie.DFS();    
    cout<<"-----------------------------------\n";
    
    for(int i = 0; i < M; i++){
        string result = trie.searchWord(searchWords[i]) ? "True" : "False";
        cout<<searchWords[i]<<": "<<result<<"\n";
    }

    cout<<"-----------------------------------\n";

    return 0;
}