#pragma once
#include <iostream>

struct Edge
{
	int n;
	int k;
	float weight;

	bool operator>(const Edge& edge);
	bool operator<(const Edge& edge);
	Edge() = default;
	Edge(int _n, int _k, float _weight)
	{
		n = _n;
		k = _k;
		weight = _weight;
	};
	bool operator==(const Edge& edge);
	bool loop_check();
};

struct Graph
{
	Edge* edges;
	int vertex_count;
	int edges_count;

	Graph() = default;
	Graph(Edge* _edges, int v_count, int e_count);
	friend std::istream& operator>> (std::istream &in, Graph &graph);
	friend std::ostream& operator<< (std::ostream &out, Graph &graph);
};
