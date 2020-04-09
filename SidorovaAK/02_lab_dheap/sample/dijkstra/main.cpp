#include <iostream>
#include <vector>
#include <time.h>

#include "exceptions.h"
#include "dijkstra.h"
#include "graph.h"

using namespace std;

void Test_ClassExample()
{
    cout << endl << "CLASS EXAMPLE" << endl;

    int size = 8;
    float weights[64] = { -1, 5, 8, 11, -1, -1, -1, -1,
                           5, -1, 2, -1, 4, -1, -1, -1,
                           8, 2, -1, 3, 2, -1, -1, -1,
                           11, -1, 3, -1, -1, 8, -1, -1,
                           -1, 4, -1, -1, -1, 6, -1, 1,
                           -1, -1, -1, 8, 6, -1, 13, 24,
                           -1, -1, -1, -1, -1, 13, -1, 5,
                           -1, -1, -1, -1, 1, 24, 5, -1 };

    Graph graph(weights, 8);
    cout << graph;
    cout << "Start vertex = 0" << endl;

    vector<vector<int> > paths;
    float* result = new float[size];

    cout << "Dijkstra's Algorithm is loading..." << endl;
    Dijkstra::Algorithm(graph, 0, paths, result);

    for (int i = 0; i < size; i++)
    {
        cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
        for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
            cout << *iter << " ";

        cout << "]" << endl;
    }

    paths.clear();
    delete[] result;
};

void Test_RandomGraph()
{
    cout << endl << endl << "RANDOM GRAPH" << endl;

    int size = 6;
    int startV = rand() % size;

    Graph graph(size);
    graph.GenerateConnectGraph();
    cout << graph;
    cout << "Start vertex = " << startV << endl;

    vector<vector<int> > paths;
    float* result = new float[size];

    cout << "Dijkstra's Algorithm is loading..." << endl;
    Dijkstra::Algorithm(graph, startV, paths, result);

    for (int i = 0; i < size; i++)
    {
        cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
        for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
            cout << *iter << " ";

        cout << "]" << endl;
    }

    paths.clear();
    delete[] result;
};

void Test_IncorrectStartVertex()
{
    cout << endl << endl << "INCORRECT START VERTEX" << endl;

    int size = 4;
    int startV = -5;

    Graph graph(size);
    graph.GenerateConnectGraph();
    cout << graph;
    cout << "Start vertex = " << startV << endl;

    vector<vector<int> > paths;
    float* result = new float[size];

    cout << "Dijkstra's Algorithm is loading..." << endl;
    Dijkstra::Algorithm(graph, startV, paths, result);

    for (int i = 0; i < size; i++)
    {
        cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
        for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
            cout << *iter << " ";

        cout << "]" << endl;
    }

    paths.clear();
    delete[] result;
};

void Test_DisconnectedGraph()
{
    cout << endl << endl << "DICONNECTED GRAPH" << endl;

    int size = 3;
    float weights[9] = { -1, 2, -1,
                         2, -1, -1,
                         -1, -1, -1 };

    Graph graph(weights, size);
    cout << graph;
    cout << "Start vertex = 0" << endl;

    vector<vector<int> > paths;
    float* result = new float[size];

    cout << "Dijkstra's Algorithm is loading..." << endl;
    Dijkstra::Algorithm(graph, 0, paths, result);

    for (int i = 0; i < size; i++)
    {
        cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
        for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
            cout << *iter << " ";

        cout << "]" << endl;
    }

    paths.clear();
    delete[] result;
};

void Test_InputGraph()
{
    cout << endl << "INPUT GRAPH" << endl;

    int start;
    Graph graph;
    cin >> graph;
    cout << graph;

    cout << "Enter start vertex: ";
    cin >> start;

    vector<vector<int> > paths;
    float* result = new float[graph.GetCountVertices()];

    cout << "Dijkstra's Algorithm is loading..." << endl;
    Dijkstra::Algorithm(graph, start, paths, result);

    for (int i = 0; i < graph.GetCountVertices(); i++)
    {
        cout << "Vertex - " << i << " Distance - " << result[i] << " Path: [ ";
        for (auto iter = paths[i].begin(); iter != paths[i].end(); ++iter)
            cout << *iter << " ";

        cout << "]" << endl;
    }

    paths.clear();
    delete[] result;
};
//------------------------------------------------------------

void main()
{
    srand((unsigned int)time(0));

    cout << "##### TEST DIJKSTRA'S ALGORITHMS #####" << endl;

    int choice = 0;

    cout << "Auto mode - 0, Input mode - 1. Your choice - ";
    cin >> choice;

    switch (choice)
    {
    case 0:
    {
        try
        {
            Test_ClassExample();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        try
        {
            Test_RandomGraph();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        try
        {
            Test_IncorrectStartVertex();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        try
        {
            Test_DisconnectedGraph();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        break;
    }
    case 1:
    {
        try
        {
            Test_InputGraph();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        break;
    }
    default:
        cout << "Wrong choice!";
    }
}