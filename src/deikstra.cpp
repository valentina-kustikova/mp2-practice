#include <DHBPQ.h>
#include <graph.h>
#include <vector>

using namespace std;

vector<vertex> alg_deikstra(const graph& g, const int start) {
	vector<int> points = g.get_points();
	int n = points.size();
	vector<vector<double>> matrix = vector<vector<double>>(n);
	for (int i = 0; i < n; i++) {
		matrix[i] = vector<double>(n, 0);
	}

	vector<edge> edges = g.get_edges();
	int m = edges.size();
	for (int i = 0; i < m; i++) {
		matrix[edges[i].begin][edges[i].end] = edges[i].weight;
		matrix[edges[i].end][edges[i].begin] = edges[i].weight;
	}

	vector<double> distance = vector<double>(g.points_size(), numeric_limits<double>::infinity());
	vector<int> from = vector<int>(g.points_size(), -1);

	distance[start] = 0;

	DHBPQ<vertex> queue = DHBPQ<vertex>();
	queue.push(vertex(start, distance[start], from[start]));

	while (!queue.is_empty()) {
		const vertex p = queue.pop();
		vector<double>& weight = matrix[p.point_index];
		for (unsigned int i = 0; i < weight.size(); i++) {
			if (weight[i] == 0)
				continue;

			const double new_dist = distance[p.point_index] + weight[i];
			if (new_dist < distance[i]) {
				distance[i] = new_dist;
				from[i] = p.point_index;
				queue.push(vertex(i, distance[i], from[i]));
			}
		}
	}

	vector<vertex> result = vector<vertex>();
	result.reserve(n);
	for (int i = 0; i < n; i++) {
		result.push_back(vertex(points[i], distance[i], from[i]));
	}
	return result;
}


int main() {
	char IsEnded = 'y';
	int n, m;
	while (IsEnded == 'Y' || IsEnded == 'y')
	{
		cout << "Enter n,m" << endl;
		cin >> n >> m;
		try {
			graph g = graph(n, m);
			g.print();
			vector<vertex> v = alg_deikstra(g, 0);


			cout << "Point:    ";
			for (int i = 0; i < v.size(); i++) {
				cout.width(4);
				cout << v[i].point_index;
			}
			cout << endl << "Distance: ";
			for (int i = 0; i < v.size(); i++) {
				cout.width(4);
				cout << v[i].distance;
			}
			cout << endl << "From:     ";
			for (int i = 0; i < v.size(); i++) {
				cout.width(4);
				cout << v[i].from;
			}
		}
		catch (exception& l) { cout << l.what() << endl; }
		cout << endl;
		cout << "Do u wanna try again (Y/N)" << endl;
		cin >> IsEnded;
	}
	return 0;
}
