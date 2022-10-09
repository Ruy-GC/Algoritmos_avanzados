#include "trie.h"
#include <iostream>

using namespace std;

int main(){
    Trie trie;
    trie.insert("hoja");
    trie.insert("hola");
    trie.insert("computadora");
    trie.insert("computar");
    trie.DFS();
    cout<<trie.searchWord("Hoja")<<endl;
    cout<<trie.searchWord("compu")<<endl;

    return 0;
}