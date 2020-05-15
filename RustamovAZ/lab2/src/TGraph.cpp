#include "Graph.h"
#include "SeparatedSet.h"

using namespace std;

Graph::Graph()
{
    countVertices = 0;
    weights = nullptr;
};

Graph::Graph(int _size)
{
    if (_size <= 0)
        throw exception("Incorrect number of vertices");

    countVertices = _size;
    weights = new float[countVertices * countVertices];

    for (int i = 0; i < countVertices; i++)
        for (int j = 0; j < i; j++)
        {
            weights[i * countVertices + j] = INT_MAX / 2;
            weights[j * countVertices + i] = INT_MAX / 2;
        }
};

Graph::Graph(float* _vector, int _size)
{
    if (_size <= 0)
        throw exception("Incorrect number of vertices");

    if (_vector == nullptr)
        throw exception("Vector is empty");

    countVertices = _size;
    weights = new float[countVertices * countVertices];

    for (int i = 0; i < countVertices; i++)
        for (int j = 0; j <= i; j++)
        {
            weights[i * countVertices + j] = _vector[i * countVertices + j];
            weights[j * countVertices + i] = weights[i * countVertices + j];
        }
};

Graph::Graph(const Graph& _graph)
{
    countVertices = _graph.countVertices;
    weights = new float[countVertices * countVertices];

    for (int i = 0; i < countVertices; i++)
        for (int j = 0; j <= i; j++)
        {
            weights[i * countVertices + j] = _graph.weights[i * countVertices + j];
            weights[j * countVertices + i] = weights[i * countVertices + j];
        }
};

Graph::~Graph()
{
    countVertices = 0;
    delete[] weights;
};


int Graph::GetVerticesCount() const
{
    return countVertices;
};

void Graph::RandomGraph()
{
    for (int i = 0; i < countVertices; i++)
    {
        for (int j = 0; j < i; j++)
        {
            weights[i * countVertices + j] = (int)(rand() % 12) - 1;
            if (weights[i * countVertices + j] <= 0)
            {
                weights[i * countVertices + j] = INT_MAX/2;
            }
            weights[j * countVertices + i] = weights[i * countVertices + j];
        }

        weights[i * countVertices + i] = -1;
    }
};

void Graph::RandomConnectedGraph()
{
    for (int i = 0; i < countVertices; i++)
    {
        for (int j = 0; j < i; j++)
        {
            weights[i * countVertices + j] = (int)(rand() % 12);
            weights[j * countVertices + i] = weights[i * countVertices + j];
        }

        weights[i * countVertices + i] = -1;
    }
};

void Graph::ListOfEdges(Edge* _edges, int& countEdges) const
{
    countEdges = 0;

    for (int i = 0; i < countVertices; i++)
        for (int j = 0; j < i; j++)
        {
            if (this->weights[i * countVertices + j] >= 0)
            {
                Edge edge(i, j, this->weights[i * countVertices + j]);
                _edges[countEdges++] = edge;
            }
        }
};

float* Graph::AdjacencyMatrix() const
{
    return weights;
};

bool Graph::IsConnected() const
{
    SeparatedSet vertices(countVertices);
    for (int i = 0; i < countVertices; i++)
        vertices.CreateSingleton(i);

    Edge* listOfEdges = new Edge[countVertices * (countVertices - 1) / 2];
    int countOfEdges = 0;

    this->ListOfEdges(listOfEdges, countOfEdges);

    if (countOfEdges == 0)
        return false;

    for (int i = 0; i < countOfEdges; i++)
    {
        Edge edge = listOfEdges[i];
        int setStart = vertices.Definition(edge.startVertex);
        int setEnd = vertices.Definition(edge.endVertex);

        if (setStart != setEnd)
            vertices.Unite(setStart, setEnd);
    }

    int v = vertices.Definition(0);

    for (int i = 0; i < countVertices; i++)
        if (v != vertices.Definition(i))
            return false;

    return true;
};


istream& operator>>(istream& _in, Graph& _graph)
{
    int countOfEdges = 0;

    cout << "Input the number of vertices: ";
    _in >> _graph.countVertices;
    if (_graph.countVertices <= 0)
        throw exception("Incorrect number of vertices");

    _graph.weights = new float[_graph.countVertices * _graph.countVertices];

    for (int i = 0; i < _graph.countVertices; i++)
        for (int j = 0; j < _graph.countVertices; j++)
            _graph.weights[i * _graph.countVertices + j] = -1;

    cout << "Input the count of edges: ";
    _in >> countOfEdges;

    if ((countOfEdges > (_graph.countVertices * (_graph.countVertices - 1) / 2)) || (countOfEdges < 0))
        throw exception("Incorrect number of edges");

    for (int i = 0; i < countOfEdges; i++)
    {
        int v1, v2;

        cout << endl << "Input the first vertex: ";
        _in >> v1;
        if ((v1 < 0) || (v1 >= _graph.countVertices))
            throw exception("Incorrect name of vertex");

        cout << "Input the secound vertex: ";
        _in >> v2;
        if ((v2 < 0) || (v2 >= _graph.countVertices))
            throw exception("Incorrect name of vertex");

        if (v1 == v2)
            throw exception("First vertex is the second");

        if (_graph.weights[v1 * _graph.countVertices + v2] > 0)
            throw exception("This edge already exists");

        cout << "Input the weight for edge: ";
        _in >> _graph.weights[v1 * _graph.countVertices + v2];
        if (_graph.weights[v1 * _graph.countVertices + v2] < 0)
            throw exception("Incorrect weight of edge");
        _graph.weights[v2 * _graph.countVertices + v1] = _graph.weights[v1 * _graph.countVertices + v2];
    }

    cout << endl;

    return _in;
};

ostream& operator<<(ostream& _out, const Graph& _graph)
{
    for (int i = 0; i < _graph.countVertices; i++)
    {
        for (int j = 0; j < i; j++)
            _out << "\t";
        for (int j = i; j < _graph.countVertices; j++)
            if (_graph.weights[j * _graph.countVertices + i] == INT_MAX / 2)
                _out << "-" << "\t";
            else
                _out << _graph.weights[j * _graph.countVertices + i] << "\t";
        _out << endl;
    }

    return _out;
};