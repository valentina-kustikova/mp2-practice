#include "Graph.h"
#include "Set.h"
#include "Edge.h"
#include <iostream>
#include <conio.h>
#include <queue>
#include "Exception.h"
using namespace std;

Graph::Graph()
{
    sizeVertex = 0;
    countEdges = 0;
};

Graph::Graph(const Graph& copy)
{
    sizeVertex = copy.sizeVertex;
    countEdges = copy.countEdges;
    edges = new Edge[countEdges];
    
    for (int i = 0; i < countEdges; i++)
    {
        edges[i].begin = copy.edges[i].begin;
        edges[i].end = copy.edges[i].end;
        edges[i].weight = copy.edges[i].weight;
    }
};

Graph::Graph(int* matrix, int _sizeVertex)
{
    sizeVertex = _sizeVertex;

    for(int i = 0; i < sizeVertex; i++)
        for (int j = 0; j < i; j++)
        {
            if (matrix[i * sizeVertex + j] == 1)
                countEdges++;
        }

    edges = new Edge[countEdges];
    int k = 0;

    while (k != countEdges)
    {
        for (int i = 0; i < sizeVertex; i++)
            for (int j = 0; j < i; j++)
            {
                if (matrix[i * sizeVertex + j] == 1)
                {
                    edges[k].begin = i;
                    edges[k].end = j;
                    k++;
                }

            }
    }

    for (int i = 0; i < countEdges; i++)
    {
        cout << endl << " Weight of edge " << edges[i].begin << " - " << edges[i].end << " : ";
        cin >> edges[i].weight;
    }
};

Graph::~Graph()
{
    sizeVertex = 0;
    countEdges = 0;
    delete[] edges;
};

int Graph::GetSize() const
{
    return sizeVertex;
};

Edge* Graph::GetEdges() const
{
    return edges;
};

int Graph::GetCountEdges() const
{
    return countEdges;
};

void Graph::SetCountEdges(int a)
{
    countEdges = a;
};

bool Graph::IsConnected() const
{
    //Создание списка смежности
    vector<vector<int>> gr(sizeVertex);
    for (int i = 0; i < countEdges; i++)
    {
        gr[edges[i].begin].push_back(edges[i].end);
        gr[edges[i].end].push_back(edges[i].begin);
    };

    int visitedV = 1;
    vector<bool> visit(sizeVertex);
    visit[0] = true;

    queue<int> q;
    q.push(0); // Очередь текущих вершин

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < gr[v].size(); i++) //Просмотр всех ребер из текущей вершины
        {
            int curV = gr[v][i];
            if (!visit[curV])
            {
                visit[curV] = true;
                q.push(curV);
            }
        }
    }

    for (int i = 0; i < sizeVertex; i++)
        if (visit[i] == false)
            return false;
    return true;
};

istream& operator>>(istream& in, Graph& gr)
{
    cout << "  Enter count of vertexes: ";
    cin >> gr.sizeVertex;

    if (gr.sizeVertex <= 0)
        throw Exception_errors("  Count of vertexes isn't correct! ");

    cout << "  Enter count of edges: ";
    cin >> gr.countEdges;

    if (gr.countEdges < 0)
        throw Exception_errors("  Count of edges isn't correct! ");

    gr.edges = new Edge[gr.countEdges];

    for(int i = 0; i < gr.countEdges; i++)
    {
        int begin = 0;
        int end = 0;
        float weight = 0;

        do
        {
            cout << "\nEdge " << i << "\n Begin: ";
            cin >> begin;
            cout << " End: ";
            cin >> end;
            cout << " Weight = ";
            cin >> weight;

        } while ((begin < 0) || (begin >= gr.sizeVertex)
            || (end < 0) || (end >= gr.sizeVertex)
            || (weight < 0) || (begin == end));

        cout << endl;
        gr.edges[i] = Edge(begin, end, weight);
    };

    //Проверка на связность графа
    if (!gr.IsConnected())
        throw Exception_errors(" Graph isn't connected!");

    return in;
};

float* Graph::GetWeightMatrix() const
{
    float* weight_m = new float[sizeVertex * sizeVertex];

    for (int i = 0; i < countEdges; i++)
    {
        weight_m[edges[i].begin + edges[i].end * sizeVertex] = edges[i].weight;
        weight_m[edges[i].begin * sizeVertex + edges[i].end] = edges[i].weight;
    }

    return weight_m;
};