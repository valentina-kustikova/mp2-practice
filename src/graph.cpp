#include "graph.h"
#include "DHBPQ.h"
#include <ostream>
#include <iostream>
#include <ctime>
using namespace std;

bool exists(const vector<int>& points, int p) {
	for (double point : points) {
		if (p == point) {
			return true;
		}
	}
	return false;
}

void graph::generate(int cPoints, int cEdges) {
	if (cPoints <= 1 || cEdges <= 0 || cPoints * (cPoints - 1) / 2 < cEdges || cPoints - 1 > cEdges) {
		throw exception("Can't generate graph");
	}

	points = vector<int>();
	points.reserve(cPoints);
	for (int i = 0; i < cPoints; i++) {
		points.push_back(i);
	}

	srand(time(nullptr));
	edges.reserve(cEdges);
	for (int i = 0; i < cPoints - 1; i++) {
		edges.push_back(edge(i, i + 1, rand() % 45 + 1));
		cEdges--;
	}

	while (cEdges > 0) {
		const edge e = edge(rand() % cPoints, rand() % cPoints, rand() % 45 + 1);
		if (e.begin == e.end) continue;
		int i;
		for (i = 0; i < edges.size(); i++) {
			if (e == edges[i]) {
				break;
			}
		}
		if (i == edges.size()) {		
			edges.push_back(e);
			cEdges--;
		}
	}
}


graph::graph(int cPoints, int cEdges) {
	generate(cPoints, cEdges);
}

graph::graph(vector<edge> edges) {
	points.reserve(2 * edges.size());
	for (int i = 0; i < edges.size(); i++) {
		if (!exists(points, edges[i].begin)) {
			points.push_back(edges[i].begin);
		}
		if (!exists(points, edges[i].end)) {
			points.push_back(edges[i].end);
		}
	}

	this->edges = edges;
}


int graph::points_size() const {
	return points.size();
}

int graph::edges_size() const {
	return edges.size();
}

vector<edge> graph::get_edges() const {
	return edges;
}

vector<int> graph::get_points() const {
	return points;
}

void graph::print() {
	cout << "points" << endl;
	for (int i = 0; i < points.size(); i++) {

		cout.width(4);
		cout << points[i];
	}
	cout << endl << "edges" << endl;
	for (edge e : edges) {
		cout.width(4);
		cout << e.begin;
		cout.width(4);
		cout << e.end;
		cout.width(4);
		cout << e.weight << endl;
	}
}
