#include "WeightedEdge.h"

WeightedEdge::WeightedEdge()
{
	beginV = 0;
	endV = 0;
	weight = 0;
}

WeightedEdge::WeightedEdge(int IdBeginV, int IdEndV, float WeightE)
{
	if (IdBeginV < 0 || IdEndV < 0 || WeightE < 0)
		throw M_Exeption("invalid parameter of vertex index or weight");
	beginV = IdBeginV;
	endV = IdEndV;
	weight = WeightE;
}

WeightedEdge::~WeightedEdge()
{
	beginV = endV = weight = 0;
}

bool WeightedEdge :: operator > (const WeightedEdge& tmpEdge)const
{
	return(weight > tmpEdge.weight);
}

bool WeightedEdge :: operator < (const WeightedEdge& tmpEdge)const
{
	return(weight < tmpEdge.weight);
}

bool WeightedEdge :: operator == (const WeightedEdge& tmpEdge)const
{
	return(weight == tmpEdge.weight);
}

bool WeightedEdge :: operator >= (const WeightedEdge& tmpEdge)const
{
	return(weight >= tmpEdge.weight);
}

bool WeightedEdge :: operator <= (const WeightedEdge& tmpEdge)const
{
	return(weight <= tmpEdge.weight);
}

WeightedEdge& WeightedEdge::operator=(const WeightedEdge& tmpEdge)
{
	beginV = tmpEdge.beginV;
	endV = tmpEdge.endV;
	weight = tmpEdge.weight;
	return *this;
}

ostream& operator <<(ostream& out, const WeightedEdge& E)
{
	out << "edge = (" << E.beginV << " , " << E.endV << "); weight = " << E.weight << endl;
	return out;
}

istream& operator >> (istream& in, WeightedEdge& E)
{
	cout << "Enter begin vert, end vert and weight" << endl;
	in >> E.beginV >> E.endV >> E.weight;
	if (E.beginV < 0 || E.endV < 0 || E.weight < 0)
		throw M_Exeption("invalid parameter of vertex index or weight");
	return in;
}

int WeightedEdge::GetbeginV()const
{
	return beginV;
}

int WeightedEdge::GetendV()const
{
	return endV;
}

bool WeightedEdge::adjacent(int id)const
{
	return(id == beginV || id == endV);
}

int WeightedEdge::GetAdj(int id)const
{
	if (id == beginV)
		return endV;
	else if (id == endV)
		return beginV;
}