#pragma once
#include"Graph.h"
#include"PQueue.h"
#include"Dheap.h"
#include"DisjointSet.h"
#include"DQueue.h"

struct Vertex
{
	int index = 0;
	double dist = 0;
	int up = -1;
	double weight;
	Vertex(){}
	Vertex(int index, double dist, int up)
	{
		this->dist = dist;
		this->up = up;
		this->index = index;
		weight = dist;
	}

	bool operator<(const Vertex& p) const
	{
		return dist < p.dist; 
	}
};


template<typename T>
class Algorithms {
public:
	static Graph* Kruskal(Graph&gr, PQueue<T>& queue);
	static void Sort(T*arr, int n, int d);
	static vector<Vertex> deikstra(Graph *graph, int s, PQueue<Vertex>* queue);
};

template<typename T>
Graph* Algorithms<T>::Kruskal(Graph& gr, PQueue<T>& queue)
{
	int n = gr.getsize();
	int m = gr.getrealsize();
	Graph* tree=new Graph(n, m);
	DisjointSet *set = new DisjointSet(n);
	for (int i = 0; i<n; i++)
		set->makesets(i);

	for (int i = 0; i<m; i++)
		queue.push(gr.getEdge(i));

	
	
	T tmp;

	while ((tree->getrealsize() < n - 1) && (!queue.IsEmpty()))
	{
		tmp = queue.checktop();
		queue.pop();

		int u = tmp.begin;
		int v = tmp.end;
		int weight = tmp.weight;

		int An = set->findsets(u);
		int Ak = set->findsets(v);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->insert(u, v, weight);
			
		}
		
	}

	return tree;
}


template<typename T>
void Algorithms<T>::Sort(T*arr, int n, int d)
{
	PArr<T>* data=new PArr<T>[n];
	for (int i = 0; i < n; i++)
	{
		data[i].weight = arr[i];
	}
	Dheap<PArr<T>> heap(data,n,d);
	heap.hilling();
		for (int i = 0; i < n; i++)
		{
			arr[i] = heap.checktop().weight;
			heap.remove(0);
		}
}



vector<Vertex> Algorithms<void>::deikstra(Graph *graph, int s, PQueue<Vertex>* queue)
{
	int m = graph->getrealsize();
	int n = graph->getVerticesNum();
	if ((s < 0) || (s >= n))
		throw "Invalid start vertex!";
	vector<int> vertex = graph->getVertices();
	vector<double> dist = vector<double>(n, numeric_limits<double>::infinity());
	vector<int> up = vector<int>(n, -1);

	vector<vector<double>> matrix = vector<vector<double>>(n);
	for (int i = 0; i < n; i++) {
		matrix[i] = vector<double>(n, -1.0);
	}
	Edge*Edges = graph->getEdges();
	for (int i = 0; i < m; i++)
	{
		matrix[Edges[i].begin][Edges[i].end] = Edges[i].weight;
		matrix[Edges[i].end][Edges[i].begin] = Edges[i].weight;
	}
	dist[s] = 0;
	queue->push(Vertex(s, dist[s], up[s]));

	while (!queue->IsEmpty())
	{
		const Vertex p = queue->checktop();
		queue->pop();
		vector<double> weight = matrix[p.index];
		for (int i = 0; i < weight.size(); i++)
		{
			if (weight[i] == -1)
				continue;

			const double newDist = dist[p.index] + weight[i];
			if (newDist < dist[i])
			{
				dist[i] = newDist;
				up[i] = p.index;
				queue->push(Vertex(i, dist[i], up[i]));
			}
		}
	}

	vector<Vertex> result = vector<Vertex>();
	result.reserve(n);
	for (int i = 0; i < n; i++)
	{
		result.push_back(Vertex(i, dist[i], up[i]));
	}
	return result;
	
}