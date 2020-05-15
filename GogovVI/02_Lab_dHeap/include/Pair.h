#ifndef _PAIR_H_
#define _PAIR_H_
#include <iostream>

struct Pair
{
	int vertex = 0;
	float dist = 0;

	bool operator<(const Pair& temp) const;
	bool operator<=(const Pair& temp) const;
	bool operator>(const Pair& temp) const;
	bool operator>=(const Pair& temp) const;
	bool operator==(const Pair& temp) const;
	bool operator!=(const Pair& temp) const;
	friend std::ostream& operator<<(std::ostream& out, const Pair& temp);
};

#endif //!_PAIR_H_
