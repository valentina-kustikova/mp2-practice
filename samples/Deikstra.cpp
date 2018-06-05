#include"Algorithms.h"
#include<iostream>

using namespace std;

int main()
{
	int n, m,s,d;
	vector<Vertex> result;
	cout << "Vvedite kol-vo vershin grafa i kol-vo reber" << endl;
	cin >> n >> m;
	cout << "Vvedite arnost D-heap" << endl;
	cin >> d;
	DQueue<Vertex>* queue = new DQueue<Vertex>(d);
	Graph* graph=new Graph(m, n);
	graph->generate(1, 30);
	graph->print();
	cout << "Vvedite nomer startovoi vershini" << endl;
	cin >> s;
	result = Algorithms<void>::deikstra(graph, s, queue);
	for (int i = 0; i < result.size(); i++)
	{
		cout << "Vertex:" << result[i].index << " Dist:" << result[i].dist << " Up:" << result[i].up << endl;
	}

}