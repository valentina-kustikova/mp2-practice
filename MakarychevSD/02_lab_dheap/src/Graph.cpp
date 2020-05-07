#include "Graph.h"

Graph::Graph()
{
	Edges = nullptr;
	numEdges = 0;
	numVertex = 0;
}

Graph::Graph(int _numVertex, int _numEdges)
{
	if (_numVertex <= 0 || _numEdges < 0)
		throw M_Exeption("invalid parameter");
	if (_numEdges < _numVertex - 1 || _numEdges > _numVertex* (_numVertex - 1) / 2)
		throw M_Exeption("invalid parameter");
	numVertex = _numVertex;
	numEdges = _numEdges;
	Edges = new WeightedEdge[_numEdges];
	GenerateConnectedGraph();
}

Graph::Graph(int _numVertex, int _numEdges, WeightedEdge* _Edges)
{
	if (_numVertex <= 0 || _numEdges < 0)
		throw M_Exeption("invalid parameter");
	numVertex = _numVertex;
	numEdges = _numEdges;
	Edges = new WeightedEdge[_numEdges];
	for (int i = 0; i < _numEdges; i++)
	{
		if (!IsCorrectEdge(_Edges[i]))
			throw M_Exeption("Incorrect Edge");
		Edges[i] = _Edges[i];
	}
}

Graph::Graph(const Graph& G)
{
	numVertex = G.numVertex;
	numEdges = G.numEdges;
	Edges = new WeightedEdge[numEdges];
	for (int i = 0; i < numEdges; i++)
		Edges[i] = G.Edges[i];
}

Graph::~Graph()
{
	delete[] Edges;
}

void Graph::GenerateConnectedGraph()
{
	srand(time(0));
	int i = 0;
	for (i; i < numVertex - 1; i++)
	{
		WeightedEdge E(i, i + 1, rand());
		Edges[i] = E;
	}
	while (i < numEdges)
	{
		WeightedEdge E(rand() % numVertex, rand() % numVertex, rand() % numVertex);
		if (IsCorrectEdge(E))
			Edges[i++] = E;
	}
}

bool Graph::IsCorrectEdge(const WeightedEdge& Edge)
{
	if (Edge.GetbeginV() == Edge.GetendV())
		return false;
	for (int i = 0; i < numEdges; i++)
		if ((Edges[i].GetbeginV() == Edge.GetbeginV() || Edges[i].GetendV() == Edge.GetbeginV())
			&& (Edges[i].GetbeginV() == Edge.GetendV() || Edges[i].GetendV() == Edge.GetendV()))
			return false;
	return true;
}

bool Graph::IsConnected()const
{
	bool* paints = new bool[numVertex];
	memset(paints, 0, numVertex);
	queue<int> q;
	q.push(0);
	paints[0] = 1;

	while (!q.empty())
	{
		int vert = q.front();
		q.pop();
		for (int i = 0; i < numVertex; i++)
		{
			if (Edges[i].adjacent(vert) && !paints[Edges[i].GetAdj(vert)])
			{
				q.push(Edges[i].GetAdj(vert));
				paints[Edges[i].GetAdj(vert)] = 1;
			}
		}
	}

	int numTruepaints = 0;

	for (int i = 0; i < numVertex; i++)
	{
		if (paints[i] == 1)
			numTruepaints++;
	}

	if (numTruepaints == numVertex)
		return true;

	return false;
}

int Graph::GetnumVertex()const
{
	return numVertex;
}

int Graph::GetnumEdges()const
{
	return numEdges;
}

ostream& operator <<(ostream& out, const Graph& G)
{
	for (int i = 0; i < G.numEdges; i++)
		out << G.Edges[i] << endl;
	return out;
}

istream& operator >>(istream& in, Graph& G)
{
	int _numVertex, _numEdges;
	cout << "Enter the number of vertexes" << endl;
	in >> _numVertex;
	cout << "Enter the number of edges" << endl;
	in >> _numEdges;
	if (_numVertex <= 0 || _numEdges < 0)
		throw M_Exeption("invalid parameter");
	if (/*_numEdges < _numVertex - 1 ||*/ _numEdges > _numVertex* (_numVertex - 1) / 2)
		throw M_Exeption("invalid parameter");
	G.numVertex = _numVertex;
	G.numEdges = _numEdges;
	if (G.Edges != nullptr)
		delete[] G.Edges;
	G.Edges = new WeightedEdge[_numEdges];
	for (int i = 0; i < _numEdges; i++)
	{
		WeightedEdge E;
		in >> E;
		G.Edges[i] = E;
	}
	return in;
}
