#include "THeapSort.h"
#include "KruskalsAlgorithm.h"
#include "DijkstrasAlgorithm.h"
#include "Graph.h"
#include <time.h>
#include <random>
#include <iomanip>

using namespace std;

int main()
{
	try
	{
		// Тест для пирамидальной сортировки
		cout << "\t\t--HEAPSORT--\n\n";
		srand(time(0));
		int size;
		cout << " Enter size of array: ";
		cin >> size;
		double* arr = new double[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 50;
		cout << "\n Your random " << size << " elements of array:\n ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << "\n\n Use HeapSort\n\n";
		THeapSort::Heap_sort(arr, size);
		cout << " Sorted " << size << " elements of array:\n ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl << endl;


		// Тест для алгоритма Краскала
		cout << "\t\t--KRUSKAL'S ALGORITHM--\n\n";
		Graph graph_krusk;
		cout << " Enter connected graph:\n\n";
		cin >> graph_krusk;
		cout << "\n Your source graph:\n" << graph_krusk << endl;
		cout << " Kruskal's Algorithm" << endl;
		Graph krusk_graph = KruskalsAlgorithm::CreateGraph(graph_krusk);
		cout << "\n Your new graph after Kruskal's Algorithm:\n"
			<< krusk_graph << endl;


		// Тест для алгоритма Дейкстры
		cout << "\t\t--DIJKSTRA'S ALGORITHM--\n\n";
		Graph graph_dijks;
		cout << " Enter connected graph:\n\n";
		cin >> graph_dijks;
		cout << "\n Your source graph:\n" << graph_dijks << endl;
		cout << " Dijkstra's Algorithm" << endl;
		int s;
		cout << "\n Enter start vertex from 0 to "
			<< graph_dijks.GetCountVertices() - 1 << ": ";
		cin >> s;
		DistanceAndUp* Dist = new DistanceAndUp[graph_dijks.GetCountVertices()];
		DijkstrasAlgorithm::DijAlg(graph_dijks, Dist, s);
		cout << "\n Vertices:\n";
		for (int i = 0; i < graph_dijks.GetCountVertices(); i++)
			cout << " " << setw(4) << Dist[i].vertex;
		cout << "\n Distance from " << s << " vertex to others:\n";
		for (int i = 0; i < graph_dijks.GetCountVertices(); i++)
			cout << " " << setw(4) << Dist[i].distance;
		cout << "\n Up:\n";
		for (int i = 0; i < graph_dijks.GetCountVertices(); i++)
			cout << " " << setw(4) << Dist[i].prev;
		cout << endl;

		delete[] Dist;
	}
	catch (const Exception& ex)
	{
		cerr << ex.what();
	}

	system("pause");
	return 0;
}