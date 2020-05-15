#include <iostream>
#include <vector>
#include <time.h>

#include "Dijkstra.h"
#include "Graph.h"

using namespace std;

int main()
{
    int mode, vertexCount, startVertex;
    vector<vector<int> > paths;
    cout << "Dijkstra's Algorithm Demo" << endl;
    srand((unsigned int)time(0));
    cout << "Choose method of graph generation" << endl;
    cout << "0: Random Graph" << endl << "1: Input Graph" << endl;
    cin >> mode;
    switch (mode)
    {
    case 0:
    {
        cout << "Random Graph" << endl;
        cout << "Input number of vertices: ";
        cin >> vertexCount;
        Graph graph(vertexCount);
        startVertex = rand() % vertexCount;
        cout << endl << "Initial node = " << startVertex << endl;
        float* result = new float[vertexCount];
        Dijkstra::Algorithm(graph, startVertex, paths, result);
        for (int i = 0; i < vertexCount; i++)
        {
            cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
            for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
                cout << *iter << " ";

            cout << "]" << endl;
        }
        paths.clear();
        delete[] result;
    }
    case 1:
    {
        cout << "Input Graph" << endl;
        Graph graph;
        cin >> graph;
        cout << graph << endl;
        cout << "Input initial node: ";
        cin >> startVertex;
        float* result = new float[graph.GetVerticesCount()];
        Dijkstra::Algorithm(graph, startVertex, paths, result);
        for (int i = 0; i < graph.GetVerticesCount(); i++)
        {
            cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
            for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
                cout << *iter << " ";

            cout << "]" << endl;
        }

        paths.clear();
        delete[] result;
    }
    }
}
