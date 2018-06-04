#pragma once
#include <iostream>
using namespace std;

struct edge
{
	int begin;
	int end;
	double weight;

	bool operator <(const edge& A) const {
		return weight < A.weight;
	}

	edge() = default;

	edge(int begin, int end, double weight) {
		this->begin = begin;
		this->end = end;
		this->weight = weight;
	}

	friend ostream& operator<<(ostream& o, const edge& e) {
		o << "start = " << e.begin << ", weight = " << e.weight << ", finish = " << e.end;
		return o;
	}

	bool operator ==(const edge& a) const {
		return begin == a.begin && end == a.end ||
			end == a.begin && begin == a.end;
	}
};
