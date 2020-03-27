#include "..\include\graph.h"

bool Edge::operator>(const Edge & edge)
{
	return weight > edge.weight;
}

bool Edge::operator<(const Edge & edge)
{
	return weight < edge.weight;
}

bool Edge::operator==(const Edge & edge)
{
	if ((n == edge.n) && (k == edge.k) || (n == edge.k) && (k == edge.n))
	{
		return true;
	}
	return false;
}

bool Edge::loop_check()
{
	if (n == k)
	{
		return true;
	}
	return false;
}

Graph::Graph(Edge* _edges, int v_count, int e_count)
{
	vertex_count = v_count;
	edges_count = e_count;
	edges = new Edge[edges_count];
	for (int i = 0; i < e_count; i++)
	{
		edges[i] = _edges[i];
	}
}

bool Graph::vertexCheck(int i) const
{
	for (int j = 0; j < edges_count; j++)
	{
		if ((edges[j].n == i) || (edges[j].k == i))
		{
			return true;
		}
	}
	return false;
}

std::istream & operator>>(std::istream & in, Graph & graph)
{
	std::cout << "Enter count of vertex" << std::endl;
	in >> graph.vertex_count;
	std::cout << "Enter count of edges" << std::endl;
	in >> graph.edges_count;
	graph.edges = new Edge[graph.edges_count];
	DividedSet set(graph.vertex_count);
	for (int i = 0; i < graph.vertex_count; i++)
	{
		set.set[i] = i;
	}
	for (int i = 0; i < graph.edges_count; i++)
	{
		std::cout << "Enter weight of " << i + 1 << " edge" << std::endl;
		in >> graph.edges[i].weight;
		std::cout << "Enter start of " << i + 1 << " edge" << std::endl;
		in >> graph.edges[i].n;
		std::cout << "Enter end of " << i + 1 << " edge" << std::endl;
		in >> graph.edges[i].k;
		if (graph.edges[i].loop_check())
		{
			throw "There is loop";
		}
		set.createUnitedSet(set.findSet(graph.edges[i].k), set.findSet(graph.edges[i].n));
	}
	for (int j = 0; j < graph.vertex_count; j++)
	{
		for (int i = 0; i < graph.vertex_count; i++)
		{
			if (set.set[i] != set.set[j])
			{
				throw "Graph is not connected";
			}
		}
	}
	for (int j = 0; j < graph.edges_count; j++)
	{
		for (int i = j; i < graph.edges_count; i++)
		{
			if ((graph.edges[i] == graph.edges[j]) && (i != j))
			{
				throw "Multiple edges";
			}
		}
	}
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
