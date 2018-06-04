#pragma once


struct Edge {
	int begin;
	int end;
	double weight;
	Edge(int, int, double);
	Edge();
	
	Edge& operator=(Edge&a)
	{
		begin = a.begin;
		end = a.end;
		weight = a.weight;
		return *this;
	}
};

Edge::Edge()
{
	
}



Edge::Edge(int a, int b, double c)
{
	begin = a;
	end = b;
	weight = c;
}



bool operator ==(Edge a, Edge b)
{
	if ((a.begin == b.begin) && (a.end == b.end) && (a.weight == b.weight))
		return true;
	else 
		return false;
}
