#include <vector>
#include <iostream>

using namespace std;

class Graph{
    public:
        vector<vector<int>> matrizAdj;
        int vertices;
        vector<int> colors;

        Graph(vector<vector<int>> matrizAdj){
            this->matrizAdj = matrizAdj;
            this->vertices = matrizAdj.size();
            vector<int> temp(this->vertices,-1);
            this->colors = temp;
        }

        void printColors(){
            for(int i = 0; i < this->vertices; i++){
                cout<<"Node: "<<i<<", Assigned Color: "<<this->colors[i]<<endl;
            }
        }


        //Función que asigna un color a los nodos de un grafo no dirigido
        //O(V^2+E) V siendo vertices y E edges o aristas
        void coloring(){
            if(this->vertices == 0){
                cout<<"No es posible asignar colores a los nodos"<<endl;
                return;
            }

            this->colors[0] = 0; 
            
            for(int i = 1; i < this->vertices; i++){
                vector<bool> used(vertices,false);
                int newColor = -1;
                for(int j = 0; j < this->vertices; j++){
                    if(this->matrizAdj[i][j] == 1 && this->colors[j] != -1){
                        used[this->colors[j]] = true;
                    }
                }
                
                for(int x = 0; x < this->vertices; x++){
                    if(!used[x]){
                        newColor = x;
                        break;
                    }
                }

                if(newColor == -1){
                    cout<<"No es posible asignar colores a los nodos"<<endl;
                    return;
                }

                this->colors[i] = newColor;
            }
        }
};
