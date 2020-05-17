#include "Graph.h"

Edge::Edge() {}
Edge::Edge(int _a, int _b, int _w)
{
    a = _a;
    b = _b;
    w = _w;
}
Edge::Edge(const Edge& tmp)
{
    a = tmp.a;
    b = tmp.b;
    w = tmp.w;
}
Edge::~Edge() {}

Graph::Graph()
{
    n = 0;
    m = 0;
}
Graph::Graph(int _n, int _m, Edge* _E)
{
    n = _n;
    m = _m;
    E = new Edge[m];
    for (int i = 0; i < m; i++)
    {
        E[i] = _E[i];
    }
}
Graph::Graph(const Graph& tmp)
{
    n = tmp.n;
    m = tmp.m;
    E = new Edge[m];
    for (int i = 0; i < m; i++)
    {
        E[i] = tmp.E[i];
    }
}
Graph::~Graph()
{
    delete[] E;
}
int Graph::GetN()
{
    return n;
}

Edge* Graph::AKraskal(const Graph& tmp)
{
    DivSets tops(tmp.n);
    tops.CreateSingl();
    double* weights = new double[tmp.m];
    for (int i = 0; i < tmp.m; i++)
    {
        weights[i] = tmp.E[i].w;
    }
    PQueue<double, Edge> edges(tmp.m, weights, tmp.E);
    Edge* T = new Edge[tmp.n - 1];
    int i = 0;
    Edge e;
    do
    {
        e = edges.Pop();
        if (tops.Subset(e.a) != tops.Subset(e.b))
        {
            T[i++] = e;
            tops.Unification(tops.Subset(e.a), tops.Subset(e.b));
        }
    } while ((!edges.IsEmpty) || (i < tmp.n - 1));
    return T;
}

void Graph::ADijkstra(const Graph& tmp, int* up, double* dist, int start)
{
    double sum = 0;
    PQueueElem<double, PQueueElem<double, int> > min;
    bool* vis = new bool[tmp.m];
    for (int i = 0; i < tmp.m; i++)
    {
        sum += tmp.E[i].w;
        vis[i] = true;
    }
    for (int i = 0; i < tmp.n; i++)
    {
        up[i] = -1;
        dist[i] = sum;
    }
    up[start] = 0;
    dist[start] = 0;
    PQueueElem<double, int>* DistNum = new PQueueElem<double, int>[tmp.n];
    for (int i = 0; i < tmp.m; i++)
    {
        DistNum[i].prior = dist[i];
        *DistNum[i].data = i;
    }
    PQueue<double, PQueueElem<double, int> > Dist(tmp.n, dist, DistNum);
    while (!Dist.IsEmpty())
    {
        min = Dist.Pop();
        for (int i = 0; i < tmp.m; i++)
        {
            if ((*min.data->data == tmp.E[i].a) && (vis[i]))
            {
                if (dist[*min.data->data] + tmp.E[i].w < dist[tmp.E[i].a])
                {
                    dist[tmp.E[i].a] = dist[*min.data->data] + tmp.E[i].w;
                    up[tmp.E[i].a] = *min.data->data;
                }
                vis[i] = false;
            }
            else if ((*min.data->data == tmp.E[i].b) && (vis[i]))
            {
                if (dist[*min.data->data] + tmp.E[i].w < dist[tmp.E[i].b])
                {
                    dist[tmp.E[i].b] = dist[*min.data->data] + tmp.E[i].w;
                    up[tmp.E[i].b] = *min.data->data;
                }
                vis[i] = false;
            }
        }
    }
}