#include "../include/TGraph.h"

TGraph::TGraph()
{
	vertexCount = 0;
	edgesCount = 0;
	edges = nullptr;
}

TGraph::TGraph(Edge* edges_, int edgesCount_, int vertexCount_)
{
	if (vertexCount_ < 0 || edgesCount_ < 0)
		throw "Invalid Graph.\n";
	vertexCount = vertexCount_;
	edgesCount = edgesCount_;
	edges = new Edge[edgesCount];
	bool* adjacencyMatrix = new bool[vertexCount * vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (int j = 0; j < vertexCount; j++)
			adjacencyMatrix[i * vertexCount + j] = false;
	for (int i = 0; i < edgesCount; i++)
	{
		if (edges_[i].n == edges_[i].k)
		{
			delete[] edges;
			edges = nullptr;
			throw "Self-loop in the Graph.\n";
		}
		if ((adjacencyMatrix[edges_[i].n * vertexCount + edges_[i].k] == false) && (adjacencyMatrix[edges_[i].k * vertexCount + edges_[i].n] == false))
		{
			adjacencyMatrix[edges_[i].n * vertexCount + edges_[i].k] = true;
			adjacencyMatrix[edges_[i].k * vertexCount + edges_[i].n] = true;
			edges[i] = edges_[i];
		}
		else
		{
			delete[] edges;
			edges = nullptr;
			throw "Directed Graph.\n";
		}
	}
	if (!Connectivity(adjacencyMatrix))
	{
		delete[] edges;
		edges = nullptr;
		throw "Graph is not connectivity.\n";
	}
	delete[] adjacencyMatrix;
}

bool TGraph::Connectivity(const bool* adjacencyMatrix) const
{
	std::vector<std::vector<int>> adjacencyList(vertexCount);
	for (int i = 0; i < vertexCount; i++)
		for (int j = i + 1; j < vertexCount; j++)
			if (adjacencyMatrix[i * vertexCount + j] == true)
			{
				adjacencyList[i].push_back(j);
				adjacencyList[j].push_back(i);
			}
	std::vector<bool> used;
	used.resize(vertexCount, false);
	std::queue<int> Queue;
	Queue.push(0);
	used[0] = true;
	while (!Queue.empty())
	{
		int vertex = Queue.front();
		Queue.pop();
		for (int i = 0; i < static_cast<int>(adjacencyList[vertex].size()); ++i)
		{
			int adjacentVertex = adjacencyList[vertex][i];
			if (!used[adjacentVertex])
			{
				used[adjacentVertex] = true;
				Queue.push(adjacentVertex);
			}
		}
	}
	std::vector<bool>::iterator it;
	it = find(used.begin(), used.end(), false);
	if (it == used.end())
		return true;
	else
		return false;
}

TGraph TGraph::KruskalAlgorithm()
{
	if (vertexCount == 0 || edgesCount == 0 || edges == nullptr)
		throw "Invalid graph.\n";
	TSplitSet vertex(vertexCount);
	TGraph result;
	result.vertexCount = vertexCount;
	result.edges = new Edge[vertexCount - 1];
	for (int i = 0; i < vertexCount; i++)
	{
		vertex.createSingleton((i));
	}
	THeap<Edge> tEdges(edges, edgesCount, 2);
	int tCount = 0;
	while ((tCount != vertexCount - 1) && (!tEdges.IsEmpty()))
	{
		Edge edge = tEdges.popMin();
		int firstSet = vertex.findSet(edge.k), secondSet = vertex.findSet(edge.n);
		if (firstSet != secondSet)
		{
			vertex.createUnitedSet(firstSet, secondSet);
			result.edges[tCount] = edge;
			tCount++;
		}
	}
	result.edgesCount = tCount;
	return result;
}

void TGraph::DijkstraAlgorithm(std::vector<std::vector<int>>& path, float*& resultDist, int vertexStart)
{
	if (vertexCount == 0 || edgesCount == 0 || edges == nullptr)
		throw "Invalid graph.\n";
	float* distTGraph = new float[vertexCount];
	int* up = new int[vertexCount];
	Pair* distMark = new Pair[vertexCount];
	for (int i = 0; i < vertexCount; i++)
	{
		if (i == vertexStart)
			distMark[i].dist = 0;
		else
			distMark[i].dist = FLT_MAX;
		distMark[i].vertex = i;
		up[i] = 0;
	}
	THeap<Pair> marks(distMark, vertexCount, 2);
	while (!marks.IsEmpty())
	{
		Pair minMark = marks.topMin();
		int index = 0, indexK = 0, indexN = 0;
		for (int i = 0; i < edgesCount; i++)
		{
			if (edges[i].IsIncidental(minMark.vertex))
			{
				for (int j = 0; j < marks.GetCurrentSize(); j++)
				{
					if (distMark[j].vertex == edges[i].n)
						indexN = j;
					if (distMark[j].vertex == edges[i].k)
						indexK = j;
				}
				if (minMark.dist + edges[i].weight < distMark[indexN].dist)
				{
					distMark[indexN].dist = minMark.dist + edges[i].weight;
					up[edges[i].n] = minMark.vertex;
				}
				if (minMark.dist + edges[i].weight < distMark[indexK].dist)
				{
					distMark[indexK].dist = minMark.dist + edges[i].weight;
					up[edges[i].k] = minMark.vertex;
				}
			}
		}
		distTGraph[minMark.vertex] = minMark.dist;
		marks.popMin();
	}
	resultDist = new float[vertexCount];
	memcpy(resultDist, distTGraph, sizeof(float) * vertexCount);
	path.resize(vertexCount - 1);
	for (int i = 0; i < vertexCount; i++)
	{
		float maxDistation = distTGraph[0];
		int maxDistationIndex = 0;
		for (int j = 1; j < vertexCount; j++)
			if (maxDistation < distTGraph[j])
			{
				maxDistation = distTGraph[j];
				maxDistationIndex = j;
			}
		distTGraph[maxDistationIndex] = -1;
		if (maxDistationIndex == vertexStart)
			continue;
		int v = maxDistationIndex;
		while (v != vertexStart)
		{
			path[i].push_back(v);
			v = up[v];
		}
		path[i].push_back(vertexStart);
		std::reverse(path[i].begin(), path[i].end());
	}
}

std::ostream& operator<<(std::ostream& out, const TGraph& temp)
{
	if (temp.edges == nullptr)
		std::cout << "The Graph is empty.\n";
	else
	{
		for (int i = 0; i < temp.edgesCount; i++)
			out << temp.edges[i] << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream& in, TGraph& temp)
{
	int vertexCount, edgesCount;
	std::cout << "Entering a Graph." << std::endl << "Enter the number of vertexes: ";
	in >> vertexCount;
	if (vertexCount < 0)
		throw "Invalid Graph.\n";
	std::cout << "Enter the number of edges: ";
	in >> edgesCount;
	if (edgesCount < 0)
		throw "Invalid TGraph.\n";
	temp.edges = new Edge[edgesCount];
	int n, k, weight;
	bool* adjacencyMatrix = new bool[vertexCount * vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (int j = 0; j < vertexCount; j++)
			adjacencyMatrix[i * vertexCount + j] = false;
	for (int i = 0; i < edgesCount; i++)
	{
		std::cout << "Enter an edge (vertex, vertex, weight): ";
		in >> n >> k >> weight;
		if (weight < 0)
		{
			delete[] temp.edges;
			temp.edges = nullptr;
			throw "Invalid weight.\n";
		}
		if ((n > vertexCount - 1) || (n < 0) || (k > vertexCount - 1) || (k < 0))
		{
			delete[] temp.edges;
			temp.edges = nullptr;
			throw "Invalid vertex.\n";
		}
		if (n == k)
		{
			delete[] temp.edges;
			temp.edges = nullptr;
			throw "Self-loop in the Graph.\n";
		}
		if ((adjacencyMatrix[n * vertexCount + k] == false) && (adjacencyMatrix[k * vertexCount + n] == false))
		{
			adjacencyMatrix[n * vertexCount + k] = 1;
			adjacencyMatrix[k * vertexCount + n] = 1;
			temp.edges[i] = Edge(n, k, weight);
		}
		else
		{
			delete[] temp.edges;
			temp.edges = nullptr;
			throw "Directed Graph.\n";
		}

	}
	temp.edgesCount = edgesCount;
	temp.vertexCount = vertexCount;
	if (!temp.Connectivity(adjacencyMatrix))
	{
		delete[] temp.edges;
		temp.edges = nullptr;
		throw "Graph is not connectivity.\n";
	}
	delete[] adjacencyMatrix;
	return in;
}