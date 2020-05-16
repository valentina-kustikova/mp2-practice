#ifndef _PAIR_H_
#define _PAIR_H_

class Pair
{
public:
    int first;
    int second;

    Pair();
    Pair(int, int);
    Pair(const Pair&);
    ~Pair();

    bool operator<(const Pair&) const;
};

#endif
