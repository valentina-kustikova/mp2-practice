#include "tests.h"
#include "E:\Progi\06_Lib\06_Lib\DHeap.h"
#include "E:\Progi\06_Lib\06_Lib\DivSets.h"
#include "E:\Progi\06_Lib\06_Lib\Graph.h"
#include "E:\Progi\06_Lib\06_Lib\PQueue.h"
#include <iostream>

using namespace std;

void Test1()
{
    int n = 10, d = 2;
    int* arr = new int[n] {10, 0, 9, 56, -7, 6, 1, 45, -96, 5};
    DHeap<int> heap(d, n, arr);
    cout << heap << endl;
    heap.Sort();
    cout << heap << endl;
    cin >> n;
}

void Test2()
{
    int n = 3, m = 3;
    Edge* ed = new Edge[m];
    Edge* eda;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        double w;
        cout << "a = ";
        cin >> a;
        cout << endl << "b = ";
        cin >> b;
        cout << endl << "w = ";
        cin >> w;
        cout << endl;
        ed[i] = Edge(a, b, w);
    }
    Graph gr(n, m, ed);
    cout << gr;
    eda = gr.AKraskal(gr);
    for (int i = 0; i < n - 1; i++)
        cout << eda[i] << " ";
    cin >> n;
}

void Test3()
{
    int n = 3, m = 3;
    int* up = new int[n] {0};
    double *dist = new double[n] {0};
    Edge* ed = new Edge[m];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        double w;
        cout << "a = ";
        cin >> a;
        cout << endl << "b = ";
        cin >> b;
        cout << endl << "w = ";
        cin >> w;
        cout << endl;
        ed[i] = Edge(a, b, w);
    }
    Graph gr(n, m, ed);
    gr.ADijkstra(gr, up, dist, 1);
    for (int i = 0; i < n; i++)
        cout << "v " << i << " dist " << dist[i] << " up " << up[i] << endl;
    cin >> n;
}