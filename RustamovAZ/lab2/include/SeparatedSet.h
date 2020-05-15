#ifndef __SEPARATEDSET__H__
#define __SEPARATEDSET__H__

class SeparatedSet
{
private:
    int size;
    int* arr;

public:
    SeparatedSet(int);
    SeparatedSet(int, int*);
    SeparatedSet(const SeparatedSet&);
    ~SeparatedSet();

    void CreateSingleton(int);
    void Unite(int, int);
    int Definition(int) const;
};

#endif
