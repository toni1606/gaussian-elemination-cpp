#include "../headers/error.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <ostream>

#pragma once

class CyclicGroup {
public:
  CyclicGroup();
  CyclicGroup(int32_t m_num, uint32_t m_p);
  CyclicGroup(CyclicGroup &&) = default;
  CyclicGroup(const CyclicGroup &) = default;
  CyclicGroup &operator=(CyclicGroup &&) = default;
  CyclicGroup &operator=(const CyclicGroup &) = default;
  ~CyclicGroup() = default;

  operator double();

  friend std::ostream &operator<<(std::ostream &os, CyclicGroup const &frac);
  friend std::istream &operator>>(std::istream &is, CyclicGroup &frac);

  CyclicGroup &operator+=(const CyclicGroup &rhs);
  CyclicGroup &operator-=(const CyclicGroup &rhs);

  CyclicGroup &operator/=(const CyclicGroup &rhs);
  CyclicGroup operator/(const CyclicGroup &rhs);

  CyclicGroup &operator*=(const CyclicGroup &rhs);
  CyclicGroup operator*(const CyclicGroup &rhs);

  bool operator!=(const CyclicGroup &rhs);
  bool operator==(const CyclicGroup &rhs);

  bool operator!=(const int32_t &rhs);
  bool operator==(const int32_t &rhs);

private:
  static int32_t gcd(int32_t a, int32_t b);
  static int32_t lcm(int32_t a, int32_t b);
  void simplify();

private:
  int32_t m_num;
  uint32_t m_p;
};
