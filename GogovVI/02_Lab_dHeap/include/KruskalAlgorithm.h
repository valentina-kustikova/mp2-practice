#ifndef _KRUSKALALGORITHM_H_
#define _KRUSKALALGORITHM_H_
#include "TGraph.h"
#include "THeap.h"
#include "TSplitSet.h"

class KruskalAlgorithm
{
public:
	static TGraph kruskalAlgorithm(const TGraph& graph);
};

#endif // !_KRUSKALALGORITH_H_

