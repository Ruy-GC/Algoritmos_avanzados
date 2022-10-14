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
                    
                    int newDist = results[index] + this->matrizAdj[root][i];

                    if (newDist > -1){
                        if (newDist < results[i]){
                            results[i] = newDist;
                            pq.push(make_pair(i,newDist));
                        }
                    }
                    

                }
            }
            /*results[root] = 0;

            for (int i = 0; i < this->matrizAdj.size()-1;i++){
                int minD = minDistance(results,visited);
                visited[minD] = true;

                for (int j = 0; j < this->matrizAdj.size(); j++){
                    if(!visited[j] && this->matrizAdj[minD][j] && results[j] != INT_MAX && results[minD] + this->matrizAdj[minD][j] < results[j]){
                        results[j] = results[minD] + this->matrizAdj[minD][j];
                    }
                }  
            }*/

            printSolution(results);    

        }



        void floyd(){

        }
};


