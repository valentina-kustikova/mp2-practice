#ifndef _TSPLITSET_H_
#define _TSPLITSET_H_
#include <iostream>

class TSplitSet
{
	int universe;
	int* set;

public:
	TSplitSet(int size);
	~TSplitSet();
	void createSingleton(int i);
	void createUnitedSet(int i, int j);
	int findSet(int i);

	bool operator!=(const TSplitSet& temp) const;
};
#endif // !_TSPLITSET_H_