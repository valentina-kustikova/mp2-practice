#pragma once
#include "Edge.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include<vector>
#include <algorithm>


using namespace std;


class Graph {
private:
	int m;//число ребер
	int n;// число вершин
	Edge* Edges;
	int current;
public:
	Graph(int, int);
	Graph(Graph&);
	~Graph();

	void insert(int, int, int);
	void remove(int, int);
	int findEdge(int, int);
	void generate (int, int);
	int getsize();
	int getrealsize();
	Edge getEdge(int);
	Edge* getEdges();
	double getWeight(int, int);
	void print();
	int getVerticesNum();
	vector<int> getVertices();
};



Graph::Graph(int _m, int _n)
{
	if (_n < 0)
		throw "wrong ver num";
	else
		n = _n;
	if ((_m < 0)|| (_m > _n*(_n - 1) / 2))
		throw "wrong edge num";
	m = _m;
	Edges = new Edge[m];
	current = 0;
}


Graph::Graph(Graph& a)
{
	n = a.n;
	m = a.m;
	Edges = new Edge[m];
	Edge* z = a.getEdges();
	for (int i = 0; i < m; i++)
	{
		Edges[i].begin =z[i].begin;
		Edges[i].end = z[i].end;
		Edges[i].weight = z[i].weight;
	}
}


Graph::~Graph()
{
	
	delete []Edges;
}


int Graph::getsize()
{
	return m;
}

int Graph::getrealsize()
{
	return current;
}


Edge Graph::getEdge(int i)
{
	return Edges[i];
}


int Graph::findEdge(int a, int b)
{
	for (int i = 0; i < current; i++)
	{
		if ((Edges[i].begin == a) && (Edges[i].end == b) || (Edges[i].end == a) && (Edges[i].begin == b))
			return i;
	}
	return -1;
}


void Graph::insert(int a, int b, int c)
{
	Edge newEdge(a, b, c);
	if (current == m+1)
		throw "graph is full";
	if (a == b)
		throw "the graph must be simple";
	if ((a > n) || (b > n))
		throw ("there are no such vertices");

	Edges[current] = newEdge;
	current++;
}


void Graph::remove(int a, int b)
{
	int tmp = findEdge(a, b);
	if (tmp == -1)
		throw ("there is no such edge");
	Edges[tmp].~Edge();
	Edges[tmp] = Edges[current - 1];
	current--;
}


Edge* Graph:: getEdges()
{
	return Edges;
}

double Graph::getWeight(int a, int b)
{
	return Edges[findEdge(a, b)].weight;
}



void Graph::generate(int a, int b)
{

	int u, v;
	double weight;
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		do
		{
			u = rand() % n;
			v = rand() % n;
		} while ((u == v) || (findEdge(u, v) != -1));

		weight = a +  (rand()) / ( (RAND_MAX / (b - a)));
		Edge newEdge(u, v, weight);
		Edges[i] = newEdge;
		current++;
	}
}


void Graph::print()
{
	cout << "Edges:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < current; j++)
		{
			if (Edges[j].begin == i)
				cout << "(" << Edges[j].begin << ")---(" << Edges[j].end <<")  "<< " (" << Edges[j].weight << ")" << endl;
		}
	}
}

int Graph::getVerticesNum()
{
	return n;
}

vector<int> Graph::getVertices()
{
	vector<int> res;
		for (int i = 0; i < m; i++)
	{
			if (find(res.begin(), res.end(), Edges[i].begin) == res.end()) 
			{
				res.push_back(Edges[i].begin);
			}
			if (find(res.begin(), res.end(), Edges[i].end) == res.end())
			{
				res.push_back(Edges[i].end);
			}
	}
	

	return res;
}
