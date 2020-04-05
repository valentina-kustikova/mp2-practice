#ifndef _PAIR_H_
#define _PAIR_H_

class Pair
{
private:
    int first;
    int second;
public:
    Pair();
    Pair(int, int);
    Pair(const Pair&);
    ~Pair();

    int GetFirst() const;
    int GetSecond() const;
    void SetFirst(int);
    void SetSecond(int);
    bool operator<(const Pair&) const;

    friend class Dijkstra;
};

#endif
