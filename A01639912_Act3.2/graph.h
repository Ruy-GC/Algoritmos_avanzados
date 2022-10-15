#include <vector>
#include <iostream>
#include <queue>

#define INF 10000

using namespace std;
typedef pair<int, int> pd;

class Graph{
    public:
        vector<vector<int>> matrizAdj;
        int vertices;

        Graph(vector<vector<int>> matrizAdj){
            this->matrizAdj = matrizAdj;
            this->vertices = matrizAdj.size();
        }

        //struct utilizado para definir el min priotiy queue
        struct myComp {
            constexpr bool operator()(
                pair<int, int> const& a,
                pair<int, int> const& b)
                const noexcept{
                return a.second > b.second;
            }
        };

        // imprime la solución del algoritmo de Dijkstra
        // Comlejidad temporal: O(V)
        void printSolution(vector<int> results, int root){
            for (int i = 0; i < this->vertices; i++){
                cout << "node "<< root <<" to node "<<i<<": ";
                if(results[i] == INF){
                    cout<<"INF"<< endl;
                }else{
                    cout<<results[i]<< endl;
                }
            }
        }

        // Función que calcula la ruta más corta entre el nodo raiz y los demás nodos
        // Complejidad temporal: O(E log V) E siendo las aristas y V los vertices
        // Complejidad espacial: O(V)
        void dijkstra(int root){
            vector<int> results(this->matrizAdj.size(),INF);
            vector<bool> visited(this->matrizAdj.size(),false);
            results[root] = 0;
            priority_queue<pd,vector<pd>,myComp> pq;
            
            pq.push(make_pair(root,0));

            while(pq.size() != 0){
                
                int index = pq.top().first;
                int minVal = pq.top().second;
                pq.pop();
                visited[index] = true;

                for(int i = 0; i < this->vertices; i++){
                    if(this->matrizAdj[index][i] != -1){
                        if(visited[i] == false && this->matrizAdj[index][i] != INF){
                            int newDist = results[index] + this->matrizAdj[index][i]; 

                            if(newDist < results[i]){
                                results[i] = newDist;
                                pq.push(make_pair(i,newDist));
                            } 
                        }
                    }
                }
            }

            printSolution(results,root);

        }

        // Función que calcula la distanica entre todos los nodos.
        // Complejidad temporal: O(n^3)
        // Complejidad espacial: O(n^2)
        void floyd(int noVertex){

            vector<vector<int>> provMatrix(noVertex, vector<int>(noVertex));

            for (int i = 0; i < this->matrizAdj.size(); i++){
                for (int j = 0; j < this->matrizAdj[i].size(); j++){
                    if (this->matrizAdj[i][j] == -1){
                        provMatrix[i][j] = INF;
                    }
                    else{
                        provMatrix[i][j] = this->matrizAdj[i][j];
                    }
                }
            }

            for (int k = 0; k < noVertex; k++){
                for (int i = 0; i < noVertex; i++){
                    for (int j = 0; j < noVertex; j++){
                        if (provMatrix[k][j] + provMatrix[i][k] < provMatrix[i][j]){
                            provMatrix[i][j] = provMatrix[k][j] + provMatrix[i][k];
                        }
                    }
                }
            }
            printFloyd(provMatrix);
        }

        // Función que imprime el resultado de Floyd
        // Complejidad temporal: O(n^2)
        void printFloyd(vector<vector<int>> results){
            cout << "Floyd:" << endl;
            for (int i = 0; i < results.size(); i++){
                for (int j = 0; j < results[i].size(); j++){
                    if (results[i][j] == INF){
                        cout << "INF ";
                    }
                    else{
                        cout << results[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
};
