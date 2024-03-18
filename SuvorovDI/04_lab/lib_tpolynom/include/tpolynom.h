#include "tlist.h"
#include <iostream>
#include <stdint.h>
#include <cstring>

class TMonom : public TData {
private:
  double coeff_;
  int16_t degree_;
public:
  TMonom(double coeff, int16_t degree);
  TData* copy() const override;
  bool operator<(const TData&) const override;
  bool operator<=(const TData&) const override;
  bool operator>(const TData&) const override;
  bool operator>=(const TData&) const override;
  bool operator==(const TData&) const override;
  bool operator!=(const TData&) const override;

  void SetCoeff(double coeff) {
    coeff_ = coeff;
  }
  void SetDegree(int16_t degree) {
    degree_ = degree;
  }

  double GetCoeff() const {
    return coeff_;
  }
  int16_t GetDegree() const {
    return degree_;
  }

  void output_data() const override {
    std::cout << coeff_ << "  " << degree_ << std::endl;
  }
};

class TPolynom {
public:
  std::string name;
  THeadRingList monoms;

  void tokinize_polynom(const std::string& name);

  TPolynom();
  TPolynom(const std::string& name);
  TPolynom(const THeadRingList* l);
  TPolynom(const TPolynom& p);
  ~TPolynom() = default;

  TPolynom operator+(const TPolynom& p);
  TPolynom operator-(const TPolynom& p);
  TPolynom operator*(TPolynom& p);

  double operator()(double x, double y, double z) const;
  TPolynom dx() const;
  TPolynom dy() const;
  TPolynom dz() const;

  const TPolynom& operator=(const TPolynom& p);
};