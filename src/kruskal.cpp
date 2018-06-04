#include <vector>
#include <graph.h>
#include <DHBPQ.h>

using namespace std;

vector<edge> kruskal(const graph& g) {
	vector<int> groups = vector<int>();
	groups.reserve(g.points_size());
	for (int i = 0; i < g.points_size(); i++) {
		groups.push_back(i);
	}
	vector<edge> result;
	DHBPQ<edge> queue(g.get_edges(), 2);
	const int n = g.points_size();
	while (!queue.is_empty() && result.size() < n - 1) {
		const edge edge = queue.pop();
		if (groups[edge.begin] != groups[edge.end]) {
			for (int i = 0; i < n; i++) {
				if (groups[i] == groups[edge.end]) {
					groups[i] = groups[edge.begin];
				}
			}
			result.push_back(edge);
		}
	}
	return result;
}


int main() {
	char IsEnded = 'y';
	int n, m;
	while (IsEnded == 'Y' || IsEnded == 'y')
	{
		try {
			cout << "Enter n,m" << endl;
			cin >> n >> m;
			graph g = graph(n, m);
			g.print();
			vector<edge> v = kruskal(g);
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << endl;
			}
		}
		catch (exception& l) { cout << l.what() << endl; }
		cout << "Do u wanna try again (Y/N)" << endl;
		cin >> IsEnded;
	}
	return 0;
}
