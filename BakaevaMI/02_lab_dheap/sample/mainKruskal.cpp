#include "Kruskal.h" 
#include "Exception.h"
#include <vector>

void main()
{
    cout << "\t -Kruskal's Algorithm-" << endl;

    Graph gr;
    try
    {
        cin >> gr;

        vector<Edge> ostavTree;
        Kruskal::KruskalAlg(gr, ostavTree);

        cout << "  Ostav Tree: ";

        for (int i = 0; i < ostavTree.size(); i++)
        {
            cout << endl << "  " << ostavTree[i].begin;
            cout << " - " << ostavTree[i].end;
            cout << " W = " << ostavTree[i].weight;
        }
    }
    catch (const Exception_errors & e)
    {
        cerr << e.what() << endl;
    }
}