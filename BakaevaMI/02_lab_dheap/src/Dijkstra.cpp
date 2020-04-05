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
        dist[i].first = i; // Вершины
        dist[i].second = INT_MAX; //Метки
        visited[i] = start;
    }

    dist[start].second = 0;

    //Создание приоритетной очереди из меток
    TDHeap<Pair> heapVisited(gr.GetSize(), 2, dist, gr.GetSize());
    heapVisited.Hilling();

    float* w = gr.GetWeightMatrix();

    while(heapVisited.GetSize() != 0)
    {
        Pair min = heapVisited.GetElements()[0];
        heapVisited.DeleteMin();

        for(int j = 0; j < gr.GetSize(); j++)
        {
            if (((min.second +
                w[min.first * gr.GetSize() + dist[j].first]) < dist[j].second) && 
                (w[min.first * gr.GetSize() + dist[j].first] > 0))
            {
                dist[j].second = min.second + w[min.first * gr.GetSize() + dist[j].first];

                visited[dist[j].first] = min.first;

                w[min.first * gr.GetSize() + dist[j].first] = -1;
                w[min.first + dist[j].first * gr.GetSize()] = -1;
            }
        }

        heapVisited.Hilling();
    }

    //Массив результатирующих расстояний
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