#include <iostream>
#include <map>

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

        void insert(string key){
            Node *current = this->root;

            for(int i = 0; i < key.length(); i++){
                char c = key[i];
                if(current->children[c-'a'] == NULL){
                    Node *new_node = new Node(c);
                    current->children[c-'a'] = new_node;
                }

                current = current->children[c - 'a'];
            }

            current->terminal = true;
        }
};

