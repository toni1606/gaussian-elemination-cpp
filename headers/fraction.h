#include <cstdint>
#include <ostream>

#pragma once

class Fraction {
public:
  Fraction();
  Fraction(int32_t nom, int32_t den);
  Fraction(Fraction &&) = default;
  Fraction(const Fraction &) = default;
  Fraction &operator=(Fraction &&) = default;
  Fraction &operator=(const Fraction &) = default;
  ~Fraction() = default;

  operator double();

  friend std::ostream &operator<<(std::ostream &os, Fraction const &frac);
  friend std::istream &operator>>(std::istream &is, Fraction &frac);

  Fraction &operator+=(const Fraction &rhs);
  Fraction &operator-=(const Fraction &rhs);

  Fraction &operator/=(const Fraction &rhs);
  Fraction &operator/(const Fraction &rhs);

  Fraction &operator*(const Fraction &rhs);

  bool operator!=(const Fraction &rhs);
  bool operator==(const Fraction &rhs);

  bool operator!=(const int32_t &rhs);
  bool operator==(const int32_t &rhs);

private:
  int32_t m_nom;
  int32_t m_den;
};
