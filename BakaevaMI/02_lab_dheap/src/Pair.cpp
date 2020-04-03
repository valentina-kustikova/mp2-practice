#include "../include/Pair.h"

Pair::Pair()
{
	first = 0;
	second = 0;
};

Pair::Pair(int f, int s)
{
	first = f;
	second = s;
};

Pair::Pair(const Pair& tmp)
{
	first = tmp.first;
	second = tmp.second;
};

Pair::~Pair()
{
	first = 0;
	second = 0;
};

int Pair::GetFirst() const
{
	return first;
};

int Pair::GetSecond() const
{
	return second;
};

void Pair::SetFirst(int f)
{
	first = f;
};

void Pair::SetSecond(int d)
{
	second = d;
};

bool Pair::operator<(const Pair& tmp) const
{
	return (second < tmp.second);
};