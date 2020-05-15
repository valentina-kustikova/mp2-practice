#include <iostream>
#include <vector>
#include <time.h>

#include "Dijkstra.h"

using namespace std;

int main()
{
    int mode, vertexCount, startVertex;
    vector<vector<int> > paths;
    vector<float> result;
    Graph* pgraph;
    cout << "Dijkstra's Algorithm Demo" << endl;
    srand((unsigned int)time(0));
    cout << "Choose method of graph generation" << endl;
    cout << "0: Random Graph" << endl << "1: Input Graph" << endl;
    cin >> mode;
    try
    {
        switch (mode)
        {
        case 0:
        {
            cout << "Random Graph" << endl;
            cout << "Input number of vertices: ";
            cin >> vertexCount;
            pgraph = new Graph(vertexCount);
            startVertex = rand() % vertexCount;
            (*pgraph).RandomGraph();
            cout << endl << "Initial node = " << startVertex << endl;
            break;
        }
        case 1:
        {
            pgraph = new Graph;
            cout << "Input Graph" << endl;
            cin >> *pgraph;
            cout << *pgraph << endl;
            cout << "Input initial node: ";
            cin >> startVertex;
            vertexCount = (*pgraph).GetVerticesCount();
            break;
        }
        default:
        {
            cout << "Incorrect input" << endl;
            return -1;
        }
        }
        vector<float> result(vertexCount);
        Dijkstra::Algorithm(*pgraph, startVertex, paths, result);
        for (int i = 0; i < vertexCount; i++)
        {
            cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
            for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
                cout << *iter << " ";

            cout << "]" << endl;
        }

        paths.clear();
        result.clear();
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl << endl;
    }
}
