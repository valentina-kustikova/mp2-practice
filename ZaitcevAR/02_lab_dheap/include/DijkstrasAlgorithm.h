#pragma once
#include "THeap.h"
#include "Graph.h"

struct DistanceAndUp
{
	int vertex; // ������ �������
	int distance; // ���������� �� �������
	int prev; // ���������� ���������� �������

	DistanceAndUp& operator=(const DistanceAndUp& tmp);

	bool operator<(const DistanceAndUp& tmp) const;
	bool operator>(const DistanceAndUp& tmp) const;
	bool operator==(const DistanceAndUp& tmp) const;
};

static class DijkstrasAlgorithm
{
public:
	static void DijAlg(const Graph& graph, DistanceAndUp* Dist, int start_vertex);
};