#include "Kruskal.h" 
#include "Exception.h"

void main()
{
    cout << "\t -Kruskal's Algorithm-" << endl;

    Graph gr;
    try
    {
        cin >> gr;

        TDHeap<Edge> ostavTree;
        Kruskal::KruskalAlg(gr, ostavTree);

        cout << "  Ostav Tree: ";

        for (int i = 0; i < ostavTree.GetSize(); i++)
        {
            cout << endl << "  " << ostavTree.GetElements()[i].begin();
            cout << " - " << ostavTree.GetElements()[i].end();
            cout << " W = " << ostavTree.GetElements()[i].weight();
        }
    }
    catch (const Exception_errors & e)
    {
        cerr << e.what() << endl;
    }
}