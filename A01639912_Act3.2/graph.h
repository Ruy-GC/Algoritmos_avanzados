#include <vector>
#include <iostream>
#include <queue>

#define INF 10000

using namespace std;

class Graph
{
public:
    vector<vector<int>> matrizAdj;
    int vertices;

    Graph(vector<vector<int>> matrizAdj)
    {
        this->matrizAdj = matrizAdj;
        this->vertices = matrizAdj.size();
    }

    void printSolution(vector<int> results)
    {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < this->matrizAdj.size(); i++)
            cout << i << " \t\t\t\t" << results[i] << endl;
    }

    void dijkstra(int root)
    {
        vector<int> results(this->matrizAdj.size(), 1000);
        vector<bool> visited(this->matrizAdj.size(), false);
        results[root] = 0;
        priority_queue<pair<int, int>> pq;

        pq.push(make_pair(root, 0));

        while (pq.size() != 0)
        {
            int index = pq.top().first;
            int minVal = pq.top().second;
            pq.pop();
            visited[index] = true;

            for (int i = 0; i < this->vertices; i++)
            {
                if (visited[i] == true)
                    continue;

                int newDist = results[index] + this->matrizAdj[root][i];

                if (newDist > -1)
                {
                    if (newDist < results[i])
                    {
                        results[i] = newDist;
                        pq.push(make_pair(i, newDist));
                    }
                }
            }
        }

        printSolution(results);
    }

    // Función que calcula la distanica entre todos los nodos.
    // Complejidad temporal: O(n^3)
    // Complejidad espacial: O(n^2)
    void floyd(int noVertex)
    {

        vector<vector<int>> provMatrix(noVertex, vector<int>(noVertex));

        for (int i = 0; i < this->matrizAdj.size(); i++)
        {
            for (int j = 0; j < this->matrizAdj[i].size(); j++)
            {
                if (this->matrizAdj[i][j] == -1)
                {
                    provMatrix[i][j] = INF;
                }
                else
                {
                    provMatrix[i][j] = this->matrizAdj[i][j];
                }
            }
        }

        for (int k = 0; k < noVertex; k++)
        {
            for (int i = 0; i < noVertex; i++)
            {
                for (int j = 0; j < noVertex; j++)
                {
                    if (provMatrix[k][j] + provMatrix[i][k] < provMatrix[i][j])
                    {
                        provMatrix[i][j] = provMatrix[k][j] + provMatrix[i][k];
                    }
                }
            }
        }
        printFloyd(provMatrix);
    }

    // Función que imprime el resultado de Floyd
    // Complejidad temporal: O(n^2)
    void printFloyd(vector<vector<int>> results)
    {
        cout << "Floyd:" << endl;
        for (int i = 0; i < results.size(); i++)
        {
            for (int j = 0; j < results[i].size(); j++)
            {
                if (results[i][j] == INF)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << results[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};
