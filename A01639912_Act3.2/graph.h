#include <vector>
#include <iostream>
#include <queue>

using namespace std;


class Graph{
    public:
        vector<vector<int>> matrizAdj;
        int vertices;

        Graph(vector<vector<int>> matrizAdj){
            this->matrizAdj= matrizAdj;
            this->vertices = matrizAdj.size();
        }

        void printSolution(vector<int> results){
            cout << "Vertex \t Distance from Source" << endl;
            for (int i = 0; i < this->matrizAdj.size(); i++)
                cout << i << " \t\t\t\t" << results[i] << endl;
        }

        void dijkstra(int root){
            vector<int> results(this->matrizAdj.size(),1000);
            vector<bool> visited(this->matrizAdj.size(),false);
            results[root] = 0;
            priority_queue<pair<int,int>> pq;
            
            pq.push(make_pair(root,0));

            while(pq.size() != 0){
                int index = pq.top().first;
                int minVal = pq.top().second;
                pq.pop();
                visited[index] = true;

                for(int i = 0; i < this->vertices; i++){
                    if(visited[i] == true)
                        continue;
                    
                    
                    /*int min = INT_MAX; 
                    int minIdx = 0;
                    for(int v = 0; v < this->vertices;v++){
                        if(visited[v] == false && results[v] <= min && results[v] != -1){
                            min = results[v];
                            minIdx = v;
                        }
                    }*/

                    int newDist = results[index] + this->matrizAdj[root][i];
                    if (this->matrizAdj[root][i] == -1 && newDist != -1)
                        newDist++;

                    if (newDist > -1){
                        if (newDist < results[i]){
                            results[i] = newDist;
                            pq.push(make_pair(i,newDist));
                        }
                    }
                    

                }
            }

            printSolution(results);    

        }



        void floyd(){

        }
};


