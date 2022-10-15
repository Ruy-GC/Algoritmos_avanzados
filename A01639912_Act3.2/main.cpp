#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

void printMatrix(vector<vector<int>> matrizAdj)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << matrizAdj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<vector<int>> matrizAdj;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int num = 0;
            cin >> num;
            row.push_back(num);
        }
        matrizAdj.push_back(row);
    }

    printMatrix(matrizAdj);

    Graph grafo(matrizAdj);

    grafo.dijkstra(0);
    grafo.floyd(n);

    return 0;
}