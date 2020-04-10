#include "Kruskal.h"
#include "DHeap.h"

void Kruskal::KruskalAlg(const Graph& graph, TDHeap<Edge>& result)
{
    Set nodeSet(graph.GetSize());

    //Создание n синглетонов
    for (int i = 0; i < graph.GetSize(); i++)
    {
        nodeSet.CreateSingleton(i);
    }

    //Создание очереди
    TDHeap<Edge> heapEdge(graph.GetCountEdges(), 2, graph.GetEdges(), graph.GetCountEdges());
    heapEdge.Hilling();

    //Создание пустого множества ребер, которые включены в оставное дерево
    Edge* edgeSet = new Edge[graph.GetCountEdges()];
    int edgeSetSize = 0;

    while ((edgeSetSize != (graph.GetSize() - 1)) && (heapEdge.GetSize() != 0))
    {
        //Ребро с минимальным весом
        Edge e = heapEdge.GetElements()[0];

        //Поиск подмножества А, которому принадлежит начало ребра
        int subsetA = nodeSet.Find(e.GetBegin());

        //Поиск подмножества В, которому принадлежит конец ребра
        int subsetB = nodeSet.Find(e.GetEnd());

        //Объединение А и В, кладем ребро е в edgeSet
        if (subsetA != subsetB)
        {
            nodeSet.Combination(subsetA, subsetB);
            edgeSet[edgeSetSize++] = e;
        }

        heapEdge.DeleteMin();
    }

    TDHeap<Edge> ostavTree(edgeSetSize, 2, edgeSet, edgeSetSize);
    result = ostavTree;
};