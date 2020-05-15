#ifndef _EDGE_H_
#define _EDGE_H_
#include <iostream>

struct Edge
{
	int n, k, weight;
	Edge() = default;
	Edge(int n_, int k_, int weight_);

	bool operator<(const Edge & temp) const;
	bool operator<=(const Edge & temp) const;
	bool operator>(const Edge & temp) const;
	bool operator>=(const Edge & temp) const;
	bool operator==(const Edge & temp) const;
	bool operator!=(const Edge & temp) const;
	bool IsIncidental(int vetrtex) const;

	friend std::ostream& operator<< (std::ostream & out, const Edge & temp);
	friend std::istream& operator>>(std::istream & in, Edge & temp);
};

#endif // !_EDGE_H_