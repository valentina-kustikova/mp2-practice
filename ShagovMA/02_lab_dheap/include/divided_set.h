#pragma once

class DividedSet
{
	int universe;
	int* set;
public:
	DividedSet(int size);
	~DividedSet();
	void createSingleton(int i);
	void createUnitedSet(int i, int j);
	int findSet(int i);
	bool operator!=(const DividedSet&) const;
	bool operator==(const DividedSet&) const;

	friend struct Graph;
};

