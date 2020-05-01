#pragma once
#include "THeap.h"
#include <iostream>

using namespace std;

struct Edge
{
	int start; // ������ �����
	int end; // ����� �����
	double weight; // ��� �����

	bool operator==(const Edge& edge) const;
	bool operator<=(const Edge& edge) const;
	bool operator>=(const Edge& edge) const;
	bool operator<(const Edge& edge) const;
	bool operator>(const Edge& edge) const;

	// ����� ��� �������� ������� �� ������������� �����
	bool incident(int vertex) const;

	Edge& operator=(const Edge& edge);

	friend ostream& operator<<(ostream& out, const Edge& edge);
	friend istream& operator>>(istream& in, Edge& edge);
};

class Graph
{
private:
	int count_vertices; // ���������� ������
	int count_edges; // ���������� ����
	Edge* edges; // ������ ����
public:
	Graph();
	Graph(int count_vert);
	Graph(int count_vert, int count_edg, Edge* edges_);
	Graph(const Graph& graph);
	~Graph();

	int GetCountVertices() const;
	int GetCountEdges() const;

	Graph& operator=(const Graph& graph);

	bool operator==(const Graph& graph) const;

	// ������� �����
	void InsertEdge(const Edge& edge);

	// ���� ����� ����� ���� � ������������ ������ ��� ���������� �������
	Graph IncidentEdges(int vertex) const;

	// ���������� ������, ���� ����� ����
	bool CheckEdge(const Edge& edge) const;

	friend ostream& operator<<(ostream& out, const Graph& graph);
	friend istream& operator>>(istream& in, Graph& graph);

	friend class KruskalsAlgorithm;
	friend class DijkstrasAlgorithm;
};