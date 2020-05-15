#include "Edge.h"

Edge::Edge(int n_, int k_, int weight_)
{
	n = n_;
	k = k_;
	weight = weight_;
}

bool Edge::operator<(const Edge& temp) const
{
	return weight < temp.weight;
}

bool Edge::operator<=(const Edge& temp) const
{
	return weight <= temp.weight;
}

bool Edge::operator>(const Edge& temp) const
{
	return weight > temp.weight;
}

bool Edge::operator>=(const Edge& temp) const
{
	return weight >= temp.weight;
}

bool Edge::operator==(const Edge& temp) const
{
	return ((weight == temp.weight) && (n == temp.n) && (k == temp.k));
}

bool Edge::operator!=(const Edge& temp) const
{
	return ((weight != temp.weight) && (n != temp.n) && (k != temp.k));
}

bool Edge::IsIncidental(int vertex) const
{
	return ((n == vertex) || (k == vertex));
}

std::ostream& operator<<(std::ostream& out, const Edge& temp)
{
	out << "( " << temp.n << " , " << temp.k << " ) " << temp.weight;
	return out;
}

std::istream& operator>>(std::istream& in, Edge& temp)
{
	int n, k, weight;
	std::cout << "Enter an edge (vertex, vertex, weight): ";
	in >> n >> k >> weight;
	if (weight < 0)
		throw "Invalid weight.\n";
	temp = Edge(n, k, weight);
	return in;
}
