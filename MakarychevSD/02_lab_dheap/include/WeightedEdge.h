#ifndef WEIGHTEDGE_H    
#define WEIGHTEDGE_H

#include "Exception.h"

class WeightedEdge
{
private:
	int beginV;
	int endV;
	float weight;
public:
	WeightedEdge();
	WeightedEdge(int IdBeginV, int IdEndnV, float WeightE);
	~WeightedEdge();
	bool operator > (const WeightedEdge& tmpEdge)const;
	bool operator < (const WeightedEdge& tmpEdge)const;
	bool operator >= (const WeightedEdge& tmpEdge)const;
	bool operator <= (const WeightedEdge& tmpEdge)const;
	bool operator == (const WeightedEdge& tmpEdge)const;
	WeightedEdge& operator = (const WeightedEdge& tmpEdge);
	friend ostream& operator <<(ostream& out, const WeightedEdge& E);
	friend istream& operator >> (istream& in, WeightedEdge& E);

	bool adjacent(int id)const;
	int GetbeginV()const;
	int GetendV()const;
	int GetAdj(int id)const;
};

#endif
