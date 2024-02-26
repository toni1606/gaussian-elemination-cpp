#include "../headers/error.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <ostream>

#pragma once

class CyclicGroup {
public:
  CyclicGroup();
  CyclicGroup(int32_t m_num, int32_t m_p);
  CyclicGroup(CyclicGroup &&) = default;
  CyclicGroup(const CyclicGroup &) = default;
  CyclicGroup &operator=(CyclicGroup &&) = default;
  CyclicGroup &operator=(const CyclicGroup &) = default;
  ~CyclicGroup() = default;

  operator double();

  friend std::ostream &operator<<(std::ostream &os, CyclicGroup const &cyc);
  friend std::istream &operator>>(std::istream &is, CyclicGroup &cyc);

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
  int32_t m_num;
  int32_t m_p;
};
