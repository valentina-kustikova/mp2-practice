#include "../include/Dijkstra.h"
#include "../include/Graph.h"
#include "../include/Pair.h"
#include <utility>
#include <vector>

void Dijkstra::DijkstraAlg(const Graph& gr, int start, float* res_dist, vector<vector<int>>& paths)
{
	int* visited = new int[gr.GetSize()];
	Pair* dist = new Pair[gr.GetSize()];

	for (int i = 0; i < gr.GetSize(); i++)
	{
		dist[i].SetFirst(i); // Вершины
		dist[i].SetSecond(INT_MAX); //Метки
		visited[i] = start;
	}

	dist[start].SetSecond(0);

	//Priority queue from marks
	TDHeap<Pair> heapVisited(gr.GetSize(), 2, dist, gr.GetSize());
	heapVisited.Hilling();

	/*//Создание списка смежности
	vector<vector<int>> list_sm(gr.GetSize());
	for (int i = 0; i < gr.GetCountEdges(); i++)
	{
		list_sm[gr.GetEdges()[i].GetBegin()].push_back(gr.GetEdges()[i].GetEnd());
		list_sm[gr.GetEdges()[i].GetEnd()].push_back(gr.GetEdges()[i].GetBegin());
	};*/

	float* w = gr.GetWeightMatrix();

	for (int i = 0; i < heapVisited.GetSize(); i++)
	{
		Pair min = heapVisited.GetElements()[0];
		cout << endl << "dist[0].first  " << dist[0].first << endl;
		heapVisited.DeleteMin();
		cout << endl << "dist[0].first  " << dist[0].first << endl;

		for(int j = 0; j < gr.GetSize(); j++)
		{
			cout << endl << "dist[j].first  " << dist[j].first << endl;
			cout << "w[] = " << w[min.first * gr.GetSize() + dist[j].first] << endl;

			if (((min.second +
				w[min.first * gr.GetSize() + dist[j].first]) < dist[j].second) && (w[j] >= 0))
			{
				dist[j].second = min.second +
					w[min.first * gr.GetSize() + dist[j].first];

				visited[dist[j].first] = min.first;

				w[min.first * gr.GetSize() + dist[j].first] = -1;
				w[min.first + dist[j].first * gr.GetSize()] = -1;
			}
		}

		//Вывод dist
		cout << endl;
		for (int i = 0; i < gr.GetSize(); i++)
		{
			cout << "  " << dist[i].second; //Метки
		}
		cout << endl;

		heapVisited.Hilling();
	}

	//Array of result distants
	for (int i = 0; i < gr.GetSize(); i++)
		res_dist[dist[i].first] = dist[i].second;

	paths.resize(gr.GetSize());

	for (int i = 0; i < gr.GetSize(); i++)
	{
		int visit = visited[i];
		int j = 1;
		paths[i].resize(gr.GetSize() - 1);

		while (visit != start)
		{
			paths[i][j - 1] = visit;
			visit = visited[visit];
			j++;
		}

		paths[i][j - 1] = start;
		paths[i].resize(j);
		reverse(paths[i].begin(), paths[i].end());
	}

	delete[] visited;
	delete[] dist;
};