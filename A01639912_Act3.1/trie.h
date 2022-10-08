#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    public:
        bool terminal;
        vector<TrieNode *> children;

        TrieNode(){
            this->terminal = false;
            for(int i = 0; i < 26; i++){
                children.push_back(NULL);
            }
        }

        bool insertTrie( TrieNode *root, string key){
            
            TrieNode *temp = root;

            for(int i = 0; i < key.length(); i++){
                int index = key[i] - 'a';
                if (root->children[index]){

                }
            }

            return true;
        }
};