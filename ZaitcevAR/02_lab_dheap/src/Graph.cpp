#include "stdafx.h"
#include "Graph.h"

bool Edge::operator==(const Edge& edge) const
{
	if ((weight == edge.weight) && ((start == edge.start && end == edge.end)
		|| (end == edge.start && start == edge.end)))
		return true;
	else
		return false;
}

bool Edge::operator<=(const Edge& edge) const
{
	return (weight <= edge.weight);
}

bool Edge::operator>=(const Edge& edge) const
{
	return (weight >= edge.weight);
}

bool Edge::operator<(const Edge& edge) const
{
	return (weight < edge.weight);
}

bool Edge::operator>(const Edge& edge) const
{
	return (weight > edge.weight);
}

bool Edge::incident(int vertex) const
{
	return ((start == vertex) || (end == vertex));
}

Edge& Edge::operator=(const Edge& edge)
{
	start = edge.start;
	end = edge.end;
	weight = edge.weight;
	return *this;
}

ostream& operator<<(ostream& out, const Edge& edge)
{
	out << " Start: " << edge.start;
	out << "\n End: " << edge.end;
	out << "\n Weight: " << edge.weight << endl;

	return out;
}

istream& operator>>(istream& in, Edge& edge)
{
	cout << " Start of edge: ";
	in >> edge.start;
	cout << " End of edge: ";
	in >> edge.end;
	cout << " Weight of edge: ";
	in >> edge.weight;
	cout << endl;

	return in;
}


Graph::Graph()
{
	count_vertices = 0;
	count_edges = 0;
	edges = nullptr;
}

Graph::Graph(int count_vert)
{
	count_vertices = count_vert;
	count_edges = 0;
	edges = new Edge[count_vertices * (count_vertices - 1) / 2];
}

Graph::Graph(int count_vert, int count_edg, Edge* edges_)
{
	count_vertices = count_vert;
	count_edges = 0;
	edges = new Edge[count_vertices * (count_vertices - 1) / 2];
	for (int i = 0; i < count_edg; i++)
		InsertEdge(edges_[i]); // число рёбер будет увеличиваться из-за функции
}

Graph::Graph(const Graph& graph)
{
	count_vertices = graph.count_vertices;
	count_edges = graph.count_edges;
	edges = new Edge[count_vertices * (count_vertices - 1) / 2];
	for (int i = 0; i < count_edges; i++)
		edges[i] = graph.edges[i];
}

Graph::~Graph()
{
	count_vertices = 0;
	count_edges = 0;
	delete[] edges;
}

int Graph::GetCountVertices() const
{
	return count_vertices;
}

int Graph::GetCountEdges() const
{
	return count_edges;
}

bool Graph::operator==(const Graph& graph) const
{
	if ((count_vertices == graph.count_vertices)
		&& (count_edges == graph.count_edges))
	{
		for (int i = 0; i < count_edges; i++)
		{
			if (!(edges[i] == graph.edges[i]))
				return false;
		}
		return true;
	}
	else
		return false;
}

Graph& Graph::operator=(const Graph& graph)
{
	if (*this == graph)
		return *this;
	count_vertices = graph.count_vertices;
	count_edges = graph.count_edges;
	if (edges != nullptr)
		delete[] edges;
	edges = new Edge[count_edges * (count_edges - 1) / 2];
	for (int i = 0; i < count_edges; i++)
		edges[i] = graph.edges[i];

	return *this;
}

void Graph::InsertEdge(const Edge& edge)
{
	if (edge.start < 0 || edge.end < 0)
		throw Exception(" Error, incorrect index of start or end\n");
	if (count_edges == (count_vertices * (count_vertices - 1) / 2))
		throw Exception(" Error, array is full\n");
	if (edge.start == edge.end)
		throw Exception(" Error, start and end are 1 vertex\n");

	// Теперь в цикле проверяем, не пытаеся ли мы добавить уже сущ-щее ребро
	for (int i = 0; i < count_edges; i++)
	{
		if (edges[i].incident(edge.start) && (edges[i].incident(edge.end)))
			return;
	}
	// Если такого ребра нет, то вставляем его в конец
	edges[count_edges] = edge;
	count_edges++;
}

Graph Graph::IncidentEdges(int vertex) const
{
	Graph tmp(count_vertices);
	int new_vertex = 1;
	for (int i = 0; i < count_edges; i++)
	{
		if ((edges[i].start == vertex && edges[i].end != vertex)
			|| (edges[i].end == vertex && edges[i].start != vertex))
		{
			tmp.InsertEdge(edges[i]);
			new_vertex++;
		}
	}
	Graph result(new_vertex, tmp.count_edges, tmp.edges);

	return result;
}

bool Graph::CheckEdge(const Edge& edge) const
{
	for (int i = 0; i < count_edges; i++)
	{
		if (edges[i] == edge)
			return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Graph& graph)
{
	out << " Count of vertices: " << graph.GetCountVertices();
	out << "\n Count of edges: " << graph.GetCountEdges();
	out << "\n Datas of edges:\n";
	for (int i = 0; i < graph.GetCountEdges(); i++)
		out << " " << i + 1 << ")\n" << graph.edges[i];

	return out;
}

istream& operator>>(istream& in, Graph& graph)
{
	int previous_count_vertices = graph.count_vertices;
	cout << " Count of vertices: ";
	in >> graph.count_vertices;
	if (graph.count_vertices <= 0)
		throw Exception(" Count of vertices incorrect\n");
	cout << " Count of edges: ";
	in >> graph.count_edges;
	if ((graph.count_edges >
		(graph.count_vertices * (graph.count_vertices - 1) / 2))
		|| graph.count_edges < 0)
		throw Exception(" Error, count of edges incorrect\n");
	cout << " Enter data for " << graph.count_edges
		<< " edges (vertices from 0 to " << graph.count_vertices - 1
		<< "). Start is vertex 1, end is vertex 2 for edge\n";

	if (graph.edges != nullptr)
		delete[] graph.edges;
	graph.edges =
		new Edge[graph.count_vertices * (graph.count_vertices - 1) / 2];

	int tmp = graph.GetCountEdges();
	// Делается через обнуление, так как количество рёбер восст-ся после цикла
	graph.count_edges = 0;
	for (int i = 0; i < tmp; i++)
	{
		cout << " " << i + 1 << ")" << endl;
		Edge edge;
		in >> edge;
		if (edge.start >= graph.count_vertices || edge.start < 0
			|| edge.end >= graph.count_vertices || edge.end < 0)
			throw Exception
			(" Error, start or end of edge were written incorrect\n");
		graph.InsertEdge(edge);
	}

	return in;
}