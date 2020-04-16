#include "TEdge.h"

bool TEdge::isIncidental(const TEdge& other) const
{
    return isIncidental(other.startVertex) || isIncidental(other.endVertex);
}

bool TEdge::isIncidental(int vertex) const
{
    return (startVertex == vertex) || (endVertex == vertex);
}

bool TEdge::operator==(const TEdge& edge) const
{
    return (weight == edge.weight) && (((startVertex == edge.startVertex) && (endVertex == edge.endVertex))
        || ((startVertex == edge.endVertex) && (endVertex == edge.startVertex)));
}

bool TEdge::operator>(const TEdge& edge) const
{
    return weight > edge.weight;
}

bool TEdge::operator<(const TEdge& edge) const
{
    return weight < edge.weight;
}

bool TEdge::operator>=(const TEdge& edge) const
{
    return weight >= edge.weight;
}

bool TEdge::operator<=(const TEdge& edge) const
{
    return weight <= edge.weight;
}