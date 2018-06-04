#pragma once



class DisjointSet
{
private:
	int *marks;
	int *sizes;
	int n;
public:
	DisjointSet(int);
	~DisjointSet();

	void makesets(int);
	int findsets(int);
	void unionsets(int, int);

};


DisjointSet::DisjointSet(int i)
{
	if (i < 0) throw "the number must be positive";
	marks = new int[i];
	for (int j = 0; j < i; j++)
	{
		marks[j] = -1;
	}
	sizes = new int[i];
	n = i;
}


DisjointSet::~DisjointSet()
{
	delete marks;
	delete sizes;
}

void DisjointSet::makesets(int x)
{
	if ((x > n) || (x < 0))
		throw ("out of range");

	if (marks[x] != -1)
		return;

	marks[x] = x;
	sizes[x] = 1;
}

int DisjointSet::findsets(int x)
{
	if ((x > n) || (x < 0))
		throw ("out of range");
	if (sizes[x] == -1)
		return -1;

	while (marks[x] != x)
		x = marks[x];
	return x;
}

void DisjointSet::unionsets(int x, int y)
{
	if ((x > n) || (x < 0) || (y > n) || (y < 0))
		throw ("out of range");
	if ((marks[x] == -1) || (marks[y] == -1))
		throw ("Set is empty");

	x = findsets(x);
	y = findsets(y);
	if (sizes[x] > sizes[y])
		marks[y] = x;
	else if (sizes[x] < sizes[y])
		marks[x] = y;
	else
	{
		marks[y] = x;
		sizes[x]++;
	}
}

