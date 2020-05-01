#pragma once
#include "THeap.h"
#include <iostream>

using namespace std;

struct Edge
{
	int start; // начало ребра
	int end; // конец ребра
	double weight; // вес ребра

	bool operator==(const Edge& edge) const;
	bool operator<=(const Edge& edge) const;
	bool operator>=(const Edge& edge) const;
	bool operator<(const Edge& edge) const;
	bool operator>(const Edge& edge) const;

	// Метод для проверки вершины на инцидентность ребру
	bool incident(int vertex) const;

	Edge& operator=(const Edge& edge);

	friend ostream& operator<<(ostream& out, const Edge& edge);
	friend istream& operator>>(istream& in, Edge& edge);
};

class Graph
{
private:
	int count_vertices; // Количество вершин
	int count_edges; // Количество рёбер
	Edge* edges; // Массив рёбер
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

	// Вставка ребра
	void InsertEdge(const Edge& edge);

	// этот метод вернёт граф с инцидентными рёбрами для переданной вершины
	Graph IncidentEdges(int vertex) const;

	// возвращает истину, если ребро есть
	bool CheckEdge(const Edge& edge) const;

	friend ostream& operator<<(ostream& out, const Graph& graph);
	friend istream& operator>>(istream& in, Graph& graph);

	friend class KruskalsAlgorithm;
	friend class DijkstrasAlgorithm;
};