
#include"Algorithms.h"

template<typename T>
Graph Algorithms<T>::Kruskal(Graph*& gr, PQueue<T>*& queue)
{
	int n = gr->getsize();
	int m = gr->getrealsize();
	Graph *tree = new Graph(n, m);
	DisjointSet *set = new DisjointSet(n);
	for (int i = 0; i<n; i++)
		set->makesets(i);

	for (int i = 0; i<m; i++)
		queue->push(gr->getEdge(i));

	int treeEdgeSize = 0;
	int x = 0;
	T tmp;

	while (treeEdgeSize < n - 1)
	{
		tmp = queue->checktop()-;
		queue->pop();

		int u = gr->getEdge(x)->begin;
		int v = gr->getEdge(x)->end;
		int weight = tmp->weight;

		int An = set->findsets(u);
		int Ak = set->findsets(v);
		if (An != Ak)
		{
			set->unionsets(An, Ak);
			tree->insert(u, v, weight);
			treeEdgeSize++;
		}
		x++;
	}

	return tree;
}
