#include <iostream>
#include <vector>
#include <time.h>

#include "Kruskal.h"
#include "Graph.h"

using namespace std;

int main()
{
    cout << "Kruskal Algorithm Demo" << endl;
    int mode, vertexCount;
    vector<vector<Edge> > outGraph;
    Graph* pgraph;
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
            (*pgraph).RandomGraph();
            break;
        }
        case 1:
        {
            pgraph = new Graph;
            cout << "Input Graph" << endl;
            cin >> *pgraph;
            break;
        }
        default:
        {
            cout << "Incorrect input" << endl;
            return -1;
        }
        }
        cout << endl << "Initial Graph: " << endl << *pgraph << endl;
        Kruskal::Algorithm(*pgraph, outGraph);
        if (outGraph.size() == 0)
        {
            cout << "Graph doesn't have edges." << endl;
            return -1;
        }
        cout << "Minimum spanning tree(s):";
        for (int i = 0; i < outGraph.size(); i++)
        {
            cout << endl << "Tree #" << i << ": " << endl;

            for (int j = 0; j < outGraph[i].size(); j++)
                cout << outGraph[i][j] << endl;
        }
        outGraph.clear();
    }
    catch (const exception& ex)
    {
        cout << "Error: " << ex.what() << endl << endl;
    }
}