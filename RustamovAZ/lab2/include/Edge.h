#ifndef __TEDGE_H__
#define __TEDGE_H__

#include <iostream>

using namespace std;

struct Edge
{
    int startVertex;
    int endVertex;
    int weight;

    Edge() :startVertex(0), endVertex(0), weight(0) {};
    Edge(int _startVertex, int _endVertex, int _weight);
    ~Edge() {};

    bool isIncidental(const Edge& other) const;
    bool isIncidental(int vertex) const;

    bool operator>(const Edge& _edge)const;
    bool operator<(const Edge& _edge)const;
    bool operator>=(const Edge& _edge)const;
    bool operator<=(const Edge& _edge)const;
    bool operator==(const Edge& _edge)const;

    friend ostream& operator<<(ostream& _out, const Edge& _edge);
};

#endif 