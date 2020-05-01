#include "stdafx.h"
#include "DijkstrasAlgorithm.h"

bool DistanceAndUp::operator<(const DistanceAndUp& tmp) const
{
	return (distance < tmp.distance);
}

bool DistanceAndUp::operator>(const DistanceAndUp& tmp) const
{
	return (distance > tmp.distance);
}

bool DistanceAndUp::operator==(const DistanceAndUp& tmp) const
{
	return (distance == tmp.distance);
}

DistanceAndUp& DistanceAndUp::operator=(const DistanceAndUp& tmp)
{
	vertex = tmp.vertex;
	distance = tmp.distance;
	prev = tmp.prev;

	return *this;
}


void DijkstrasAlgorithm::DijAlg(const Graph& graph, DistanceAndUp* Dist, int s)
{
	for (int i = 0; i < graph.count_vertices; i++)
	{
		Dist[i].vertex = i;
		Dist[i].distance = INT_MAX;
		Dist[i].prev = -1;
	}
	Dist[s].distance = 0;
	Dist[s].prev = s;


	// 3
	THeap<DistanceAndUp>
		heap_dist(Dist, graph.count_vertices, graph.count_vertices, 2);

	Graph used_edges; // создаём граф под использованные рёбра
	used_edges.count_vertices = graph.count_vertices;
	used_edges.edges = new Edge[graph.count_edges];

	while (!heap_dist.Empty())
	{
		// 4
		DistanceAndUp min_mark = heap_dist.GetMinKey(); // первая вершина
		// 4.1
		Graph tmp = graph.IncidentEdges(min_mark.vertex);
		for (int i = 0; i < tmp.count_edges; i++)
		{
			// проверка на пройденные рёбра
			if (used_edges.CheckEdge(tmp.edges[i]))
				continue;
			used_edges.InsertEdge(tmp.edges[i]);
			// 4.2
			// запоминаем индекс второй вершины для ребра
			int second_vertex;
			if (tmp.edges[i].start == min_mark.vertex)
				second_vertex = tmp.edges[i].end;
			else
				second_vertex = tmp.edges[i].start;

			for (int j = 0; j < graph.count_vertices; j++)
			{
				if (heap_dist.keys[j].vertex == second_vertex)
				{
					if ((tmp.edges[i].weight + min_mark.distance)
						< heap_dist.keys[j].distance)
					{
						heap_dist.keys[j].distance =
							tmp.edges[i].weight + min_mark.distance;
						heap_dist.keys[j].prev = min_mark.vertex;
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < graph.count_vertices; i++)
	{
		Dist[i].vertex = heap_dist.keys[graph.count_vertices - i - 1].vertex;
		Dist[i].distance = heap_dist.keys[graph.count_vertices - i - 1].distance;
		Dist[i].prev = heap_dist.keys[graph.count_vertices - i - 1].prev;
	}
}