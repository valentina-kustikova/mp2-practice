#pragma once
#include"edge.h"
#include <vector>
using namespace std;

struct vertex
{
	int point_index = 0;
	double distance = 0;
	int from = -1;

	vertex(int point_index, double distance, int from)
		: point_index(point_index), distance(distance), from(from) {
	}

	bool operator<(const vertex& p) const { return distance < p.distance; }
};


class graph
{
	void generate(int n, int m);
	vector<edge> edges;
	vector<int> points;
public:
	graph(int n, int m);
	graph(vector<edge> edges);
	int points_size() const;
	int edges_size() const;
	vector<edge> get_edges() const;
	vector<int> get_points() const;
	void print();
};
