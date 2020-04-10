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
            cout << endl << "  " << ostavTree.GetElements()[i].GetBegin();
            cout << " - " << ostavTree.GetElements()[i].GetEnd();
            cout << " W = " << ostavTree.GetElements()[i].GetWeight();
        }
    }
    catch (Exception_errors & e)
    {
        cerr << e.what() << endl;
    }
}