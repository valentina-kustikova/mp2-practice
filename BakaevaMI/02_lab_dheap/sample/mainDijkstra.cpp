#include <iostream>
#include <vector>
#include "Dijkstra.h" 
#include "Exception.h"
using namespace std;

void main()
{
	cout << "\t -Dijkstra's Algorithm-" << endl;
	Graph gr;
	int start;
	vector<vector<int> > paths;

	try
	{
		cin >> gr;

		do
		{
			cout << "Enter starting vertex: ";
			cin >> start;
			cout << endl;
		} while ((start < 0) || (start > gr.GetSize()));

		vector<int> res_dist; 
		res_dist.resize(gr.GetSize());
		for (int i = 0; i < gr.GetSize(); i++)
			res_dist[i] = 0;

		Dijkstra::DijkstraAlg(gr, start, res_dist, paths);

		for (int i = 0; i < gr.GetSize(); i++)
		{
			cout << " Vertex " << i << " path ";

			for (int j = 0; j < paths[i].size(); j++)
			{
				cout << " " << paths[i][j];
			}

			cout << "\t W = " << res_dist[i] << endl;
		};
	}
	catch (const Exception_errors & e)
	{
		cerr << e.what() << endl;
	}
}