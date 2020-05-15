#include "Pair.h"

bool Pair::operator<(const Pair& temp) const
{
	return dist < temp.dist;
}

bool Pair::operator<=(const Pair& temp) const
{
	return dist <= temp.dist;
}

bool Pair::operator>(const Pair& temp) const
{
	return dist > temp.dist;
}

bool Pair::operator>=(const Pair& temp) const
{
	return dist >= temp.dist;
}

bool Pair::operator==(const Pair& temp) const
{
	return ((dist == temp.dist) && (vertex == temp.vertex));
}

bool Pair::operator!=(const Pair& temp) const
{
	return ((dist != temp.dist) && (vertex != temp.vertex));
}

std::ostream& operator<<(std::ostream& out, const Pair& temp)
{
	out << temp.vertex << " , " << temp.dist;
	return out;
}
