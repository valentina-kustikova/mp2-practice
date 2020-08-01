#ifndef __TDISTANCES_H__
#define __TDISTANCES_H__

#include "iostream"

class TDistances
{
public:
  int startVertex;
  int verticesCount;
  double* dist;
  int* up;

public:
  TDistances(int _startVertex, int _verticesCount, double* _dist, int* _up);
  TDistances(const TDistances& _distances);
  ~TDistances();

  bool operator==(const TDistances& _distances) const;
  bool operator!=(const TDistances& _distances) const;

  const TDistances& operator=(const TDistances& _distances);

  friend std::ostream& operator<<(std::ostream& out, const TDistances& _distances);
};

#endif // !__TDISTANCES_H__