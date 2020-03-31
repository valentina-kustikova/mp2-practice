#include "../../includes/DijkstraAlgorithm.h"

void main() {
	try {
		Graph graph(1);
		int vertex;
		int* dist;
		int* path;

		cin >> graph;
		cout << "Enter start algorithm vertex: ";
		cin >> vertex;

		DijkstraAlgorithm::dijkstraAlgorithm(graph, dist, path, vertex);
		for (int i = 0; i < graph.getVertexCount(); i++)
			cout << "Vertex: " << i << " Distance: " << dist[i] << endl;
	}
	catch (const exception & e) {
		cout << e.what() << endl;
	}
}