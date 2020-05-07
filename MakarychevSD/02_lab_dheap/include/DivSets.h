#ifndef DIVSETS_H    
#define DIVSETS_H

class DivSets
{
private:
	int size;
	int* keys;
public:
	DivSets(int size, int* keys);
	DivSets(int size);
	~DivSets();

	void MakeSingletone(int i);
	void UnSets(int i, int j);
	int Def(int i)const;
};

#endif
