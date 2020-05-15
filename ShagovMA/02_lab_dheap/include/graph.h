#pragma once
#include <iostream>
#include "divided_set.h"

struct Edge
{
	int n;
	int k;
	float weight;

	bool operator>(const Edge& edge) const;
	bool operator<(const Edge& edge) const;
	Edge() = default;
	Edge(int _n, int _k, float _weight)
	{
		n = _n;
		k = _k;
		weight = _weight;
	};
	bool operator==(const Edge& edge) const;
	bool loop_check() const;
};

struct Graph
{
	Edge* edges;
	int vertex_count;
	int edges_count;

	Graph() = default;
	Graph(Edge* _edges, int v_count, int e_count);
	Graph(const Graph& graph);
	~Graph();

	const Graph& operator=(const Graph& graph);

	friend std::istream& operator>> (std::istream &in, Graph &graph);
	friend std::ostream& operator<< (std::ostream &out, Graph &graph);
	
	bool IsGraphConnected() const;
	bool CheckMultipleEdges() const;
	bool CheckLoop() const;
};
