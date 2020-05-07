#include "KruskalsAlgorithm.h"
#include <iostream>

void TestDisconnectedGr()
{
	int m;
	cout << "Enter the number of edges in the graph" << endl;
	cin >> m;
	if (m < 0)
		throw M_Exeption("Invalid parameter");
	WeightedEdge* a = new WeightedEdge[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];
	Graph G(m * 4, m, a);
	cout << KruskalsAlgorithm::MinWeightTree(G);
}

void TestgenGr()
{
	int n,m;
	cout << "Enter the number of edges in the graph" << endl;
	cin >> m;
	cout << "Enter the number of vertex in the graph" << endl;
	cin >> n;
	Graph G(n, m);
	cout << "Your graph: " << endl << G;
	cout << "Min weight graph: " << endl << KruskalsAlgorithm::MinWeightTree(G);
}

void TestInputdGr()
{
	int m,n;
	cout << "Enter the number of edges in the graph" << endl;
	cin >> m;
	if (m < 0)
		throw M_Exeption("Invalid parameter");
	cout << "Enter the number of vertex in the graph" << endl;
	cin >> n;
	WeightedEdge* a = new WeightedEdge[m];
	for (int i = 0; i < m; i++)
		cin >> a[i];
	Graph G(n, m,a);
	cout << "Your graph: " << endl << G;
	cout << "Min weight graph: " << endl << KruskalsAlgorithm::MinWeightTree(G);
}

int main()
{
	try
	{
		TestgenGr();
		TestInputdGr();
		TestDisconnectedGr();
	}
	catch (const M_Exeption & exception)
	{
		cerr << " Error: " << exception.what() << endl;
	}
	return 0;
}