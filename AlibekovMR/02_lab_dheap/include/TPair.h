#ifndef __TPAIR_H__
#define __TPAIR_H__

#include "iostream"

class TPair
{
private:
  int vertex;
  double distance;

public:
  TPair();
  TPair(int _vertex, double _distance);
  ~TPair();

  int    getVertex()   const;
  double getDistance() const;

  void setVertex(int _vertex);
  void setDistance(double _distance);

  bool operator==(const TPair& _pair) const;
  bool operator!=(const TPair& _pair) const;

  bool operator> (const TPair& _pair) const;
  bool operator< (const TPair& _pair) const;
  bool operator>=(const TPair& _pair) const;
  bool operator<=(const TPair& _pair) const;

  const TPair& operator=(const TPair& _pair);

  friend std::ostream& operator<<(std::ostream& out, const TPair& _pair);
  friend std::istream& operator>>(std::istream& in, TPair& _pair);
};

#endif // !__TPAIR_H__