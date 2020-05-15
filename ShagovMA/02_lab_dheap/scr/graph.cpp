#include "graph.h"

bool Edge::operator>(const Edge & edge) const
{
	return weight > edge.weight;
}

bool Edge::operator<(const Edge & edge) const
{
	return weight < edge.weight;
}

bool Edge::operator==(const Edge & edge) const
{ 
	if ((n == edge.n) && (k == edge.k) || (n == edge.k) && (k == edge.n))
	{
		return true;
	}
	return false;
}

bool Edge::loop_check() const
{
	if (n == k)
	{
		return true;
	}
	return false;
}
 
Graph::Graph(Edge* _edges, int v_count, int e_count)
{
	if (_edges == nullptr)
	{
		throw "Edges were nullptr";
	}
	if (v_count < 0)
	{
		throw "Vertex count <= 0";
	}
	if (e_count <= 0)
	{
		throw "Edges count < 0";
	}
	vertex_count = v_count;
	edges_count = e_count;
	edges = new Edge[edges_count];
	for (int i = 0; i < e_count; i++)
	{
		edges[i] = _edges[i];
	}
}

Graph::Graph(const Graph & graph)
{
	vertex_count = graph.vertex_count;
	edges_count = graph.edges_count;
	edges = new Edge[edges_count];
	for (int i = 0; i < edges_count; i++)
	{
		edges[i] = graph.edges[i];
	}
}

Graph::~Graph()
{
	delete[] edges;
}

const Graph & Graph::operator=(const Graph & graph)
{
	vertex_count = graph.vertex_count;
	edges_count = graph.edges_count;
	edges = new Edge[edges_count];
	for (int i = 0; i < edges_count; i++)
	{
		edges[i] = graph.edges[i];
	}
	return *this;
}

bool Graph::IsGraphConnected() const
{
	DividedSet set(vertex_count);
	for (int i = 0; i < vertex_count; i++)
	{
		set.createSingleton(i);
	}
	for (int i = 0; i < edges_count; i++)
	{
		set.createUnitedSet(set.findSet(edges[i].k), set.findSet(edges[i].n));
	}
	for (int j = 0; j < vertex_count; j++)
	{
		for (int i = 0; i < vertex_count; i++)
		{
			if (set.set[i] != set.set[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool Graph::CheckMultipleEdges() const
{
	for (int j = 0; j < edges_count; j++)
	{
		for (int i = j; i < edges_count; i++)
		{
			if ((edges[i] == edges[j]) && (i != j))
			{
				return true;
			}
		}
	}
	return false;
}

bool Graph::CheckLoop() const
{
	for (int j = 0; j < edges_count; j++)
	{
		if (edges[j].loop_check())
		{
			return true;
		}
	}
	return false;
}

std::istream & operator>>(std::istream & in, Graph & graph)
{
	std::cout << "Enter count of vertex" << std::endl;
	int vertex_count = 0;
	in >> vertex_count;
	if (vertex_count <= 0)
	{
		throw "Count of vertex <= 0";
	}
	std::cout << "Enter count of edges" << std::endl;
	int edges_count = 0;
	in >> edges_count;
	if (edges_count < 0)
	{
		throw "Count of edges < 0";
	}
	Edge* edges = new Edge[edges_count];
	for (int i = 0; i < edges_count; i++)
	{
		std::cout << "Enter weight of " << i + 1 << " edge" << std::endl;
		in >> edges[i].weight;
		std::cout << "Enter start of " << i + 1 << " edge" << std::endl;
		in >> edges[i].n;
		std::cout << "Enter end of " << i + 1 << " edge" << std::endl;
		in >> edges[i].k;
	}
	graph = Graph(edges, vertex_count, edges_count);
	return in;
}

std::ostream & operator<<(std::ostream & out, Graph & graph)
{
	for (int i = 0; i < graph.edges_count; i++)
	{
		out << "("<< graph.edges[i].n << ", " << graph.edges[i].k << ") "
			<< graph.edges[i].weight << "\n";
	}
	return out;
}
