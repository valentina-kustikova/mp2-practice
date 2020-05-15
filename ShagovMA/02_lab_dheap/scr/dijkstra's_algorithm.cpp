#include "dijkstra's_algorithm.h"

bool Pair::operator<(const Pair & pair) const
{
	return weight < pair.weight;
}

bool Pair::operator>(const Pair & pair) const
{
	return weight > pair.weight;
}

bool Pair::operator<=(const Pair & pair) const
{
	return weight <= pair.weight;
}

bool Pair::operator>=(const Pair & pair) const
{
	return weight >= pair.weight;
}

bool Pair::operator==(const Pair & pair) const
{
	return weight == pair.weight;
}


void DijkstrasAlgorithm::dijkstraAlgorithm(const Graph& graph, int vertex_start, std::vector<std::vector<int>>& path, float*& dist_graph)
{
	bool check = true;
	for (int i = 0; i < graph.edges_count; i++)
	{
		if ((vertex_start == graph.edges[i].n) || (vertex_start == graph.edges[i].k))
		{
			check = false;
			break;
		}
	}
	if (check)
	{
		throw "Vertex_start not belong graph";
	}
	if (graph.CheckLoop() || graph.CheckMultipleEdges() || !graph.IsGraphConnected())
	{
		throw "Incorrect graph";
	}
	dist_graph = new float[graph.vertex_count];
	int* up = new int[graph.vertex_count];
	Pair* dist_mark = new Pair[graph.vertex_count];
	for (int i = 0; i < graph.vertex_count; i++)
	{
		if (i == vertex_start)
		{
			dist_mark[i].weight = 0;
		}
		else
		{
			dist_mark[i].weight = FLT_MAX;
		}
		dist_mark[i].vertex = i;
		up[i] = 0;
	}
	DHeap<Pair> marks(dist_mark, graph.vertex_count, 2);
	while (!marks.IsEmpty())
	{
		Pair min_mark = marks.top();
		int index = 0, indexK = 0, indexN = 0;
		for (int i = 0; i < graph.edges_count; i++)
		{
			if ((graph.edges[i].n == min_mark.vertex) || (graph.edges[i].k == min_mark.vertex))
			{
				for (int j = 0; j < marks.getSize(); j++)
				{
					if (dist_mark[j].vertex == graph.edges[i].n)
					{
						indexN = j;
					}
					if (dist_mark[j].vertex == graph.edges[i].k)
					{
						indexK = j;
					}
				}
				if (min_mark.weight + graph.edges[i].weight < dist_mark[indexN].weight)
				{
					dist_mark[indexN].weight = min_mark.weight + graph.edges[i].weight;
					up[graph.edges[i].n] = min_mark.vertex;
				}
				if (min_mark.weight + graph.edges[i].weight < dist_mark[indexK].weight)
				{
					dist_mark[indexK].weight = min_mark.weight + graph.edges[i].weight;
					up[graph.edges[i].k] = min_mark.vertex;
				}
			}
		}
		dist_graph[min_mark.vertex] = min_mark.weight;
		marks.popMin();
	}
	path.resize(graph.vertex_count);
	for (int i = 0; i < graph.vertex_count; i++)
	{
		int vertex = up[i];
		if (i != vertex_start)
		{
			path[i].push_back(i);
		}
		while (vertex != vertex_start)
		{
			path[i].push_back(vertex);
			vertex = up[vertex];
		}
		path[i].push_back(vertex_start);
		std::reverse(path[i].begin(), path[i].end());
	}
	delete[] dist_mark;
	delete[] up;
}

