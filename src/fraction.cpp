#include "../headers/fraction.h"
#include <iostream>
#include <string>

Fraction::Fraction() : m_nom(0), m_den(0) {}
Fraction::Fraction(int32_t nom, int32_t den) : m_nom(nom), m_den(den) {}

std::ostream &operator<<(std::ostream &os, Fraction const &frac) {
  os << frac.m_nom << '/' << frac.m_den;

  return os;
}

std::istream &operator>>(std::istream &is, Fraction &frac) {
  std::string tmp;
  std::getline(is, tmp, '/');

  frac.m_nom = std::stoi(tmp);
  is >> frac.m_den;

  return is;
}
