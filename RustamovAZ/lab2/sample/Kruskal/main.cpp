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
    cout << "Choose method of graph generation" << endl;
    cout << "0: Random Graph" << endl << "1: Input Graph" << endl;
    cin >> mode;
    switch (mode)
    {
    case 0:
    {
        try
        {
            cout << "Random Graph" << endl;
            cout << "Input number of vertices: ";
            cin >> vertexCount;
            Graph graph(vertexCount);
            graph.RandomGraph();
            cout << endl << "Initial Graph: " << endl << graph << endl;
            Kruskal::Algorithm(graph, outGraph);
            if (outGraph.size() == 0)
            {
                cout << "Graph doesn't have edges." << endl;
                return;
            }
            cout << "Minimum spanning tree(s)" << endl;
            for (int i = 0; i < outGraph.size(); i++)
            {
                cout << endl << "Tree #" << i << ": " << endl;

                for (int j = 0; j < outGraph[i].size(); j++)
                    cout << outGraph[i][j] << endl;
            }
            outGraph.clear();
        }
        catch(const exception & ex)
        {
            cout << "Error: " << ex.what() << endl << endl;
        }
    }
    case 1:
    {
        try
        {
            cout << "Input Graph" << endl;
            Graph graph;
            cin >> graph;
            cout << graph << endl;
            Kruskal::Algorithm(graph, outGraph);
            cout << "Minimum spanning tree(s)" << endl;
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
    default:
        cout << "Incorrect input" << endl;
    }
}



    


    