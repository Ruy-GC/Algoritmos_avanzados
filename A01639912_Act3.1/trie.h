#include <iostream>
#include <cctype>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;

class Node {
    public:
        char c;
        bool terminal;
        Node *children[ALPHABET_SIZE];

        Node(char c){
            this->c = c;
            this->terminal = false;
            for(int i = 0; i < ALPHABET_SIZE; i++){
                this->children[i] = NULL;
            }
        }

};

class Trie{
    public:
        Node *root;

        Trie(){
            Node *new_node = new Node('\0');
            this->root = new_node;
        }

        // inserta palabras al trie
        // O(n) complejidad de tiempo
        // O(n*m) espacio
        void insert(string key){
            Node *current = this->root;
            for(int i = 0; i < key.length(); i++){
                
                char c = tolower(key[i]);
                
                if(current->children[c-'a'] == NULL){
                    Node *new_node = new Node(c);
                    current->children[c-'a'] = new_node;
                }

                current = current->children[c - 'a'];
            }

            current->terminal = true;
        }

        // mostrar recorrido del grafo mediante dfs
        // O(v) complejidad de tiempo
        // O(v*e) espacio
        void DFS(){
            vector <Node *> visited;
            stack <Node *> dfsStack;

            Node *current = this->root;

            visited.push_back(current);
            dfsStack.push(current);

            while (!dfsStack.empty()){
                Node * pop_node = dfsStack.top();
                current = pop_node;
                cout<<pop_node->c<<"->";
                dfsStack.pop();

                for (Node *item: current->children){
                    if(item != NULL){
                        vector<Node *>::iterator it;
                        it = find(visited.begin(),visited.end(),item);
                        if(it == visited.end()){
                            visited.push_back(item);
                            dfsStack.push(item);
                        }
                    }            
                }
            }
            cout<<"\n";
        }

        // busqueda de palabras en el trie
        // O(n) complejidad de tiempo
        // O(1) espacio
        bool searchWord(string word){
            Node * current = this->root;

            for(int i = 0; i < word.length(); i++){
                char c = tolower(word[i]);
                if(current->children[c-'a'] == NULL){
                    return false;
                }
                current = current->children[c - 'a'];
            }

            if(!current->terminal && current != NULL) return false;
            
            return true;
        }
};

