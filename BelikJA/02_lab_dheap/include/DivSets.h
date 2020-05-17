#ifndef _DIVSETS_H_
#define _DIVSETS_H_

class DivSets
{
public:
    int* sets;
    int n;

    DivSets();
    DivSets(int _n);
    DivSets(int* _sets, int _n);
    DivSets(const DivSets& tmp);
    ~DivSets();

    void CreateSingl();
    void Unification(int i, int j);
    int Subset(int i);
};

#endif
