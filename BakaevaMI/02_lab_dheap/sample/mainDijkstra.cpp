#include <iostream>
#include <vector>
#include "../include/Dijkstra.h" 
#include "../include/Exception.h"
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

		float* res_dist = new float[gr.GetSize()];
		memset(res_dist, 0, sizeof(float) * gr.GetSize());

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
	catch (Exception_errors & e)
	{
		cerr << e.what() << endl;
	}
}