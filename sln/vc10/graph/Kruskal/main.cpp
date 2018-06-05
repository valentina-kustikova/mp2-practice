#include"Algorithms.h"
#include <iostream>
using namespace std;
int main()
{
	try {
		int n, m, d;
		cout << "Vvedite kol-vo vershin grafa i kol-vo reber" << endl;
		cin >> n >> m;
		Graph graph(m, n);
		graph.generate(1, 30);
		graph.print();
		cout << "Vvedite arnost D-heap" << endl;
		cin >> d;
		DQueue<Edge> queue(d);
		Graph* ResGraph = Algorithms<Edge>::Kruskal(graph, queue);
		cout << "polucheniy graph" << endl;
		ResGraph->print();
	}
	catch (const char*ex)
	{
		cout << endl<<ex;
	}
}