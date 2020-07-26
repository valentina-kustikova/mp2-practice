#ifndef __TWEIGHTEDEDGE_H__
#define __TWEIGHTEDEDGE_H__

#include "TEdge.h"

class TWeightedEdge : public TEdge
{
private:
  double weight;

public:
  TWeightedEdge();
  TWeightedEdge(int _startVertex, int _endVertex, double _weight);
  TWeightedEdge(const TWeightedEdge& _edge);
  ~TWeightedEdge() {};

  bool operator> (const TWeightedEdge& _edge) const;
  bool operator< (const TWeightedEdge& _edge) const;
  bool operator>=(const TWeightedEdge& _edge) const;
  bool operator<=(const TWeightedEdge& _edge) const;
  bool operator==(const TWeightedEdge& _edge) const;
  bool operator!=(const TWeightedEdge& _edge) const;

  double getWeight() const;
  void   setWeight(double _weight);

  const TWeightedEdge& operator=(const TWeightedEdge& _edge);

  friend std::ostream& operator<<(std::ostream& out, const TWeightedEdge& _edge);
  friend std::istream& operator>>(std::istream& in, TWeightedEdge& _edge);
};

#endif // !__TWEIGHTEDEDGE_H__