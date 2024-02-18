#include "../headers/fraction.h"
#include <iostream>
#include <string>

Fraction::Fraction() : m_nom(0), m_den(0) {}
Fraction::Fraction(int32_t nom, int32_t den) : m_nom(nom), m_den(den) {}

Fraction::operator double() { return ((double)m_nom) / ((double)m_den); }

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

// Implement adding (gcd).
Fraction &Fraction::operator+=(const Fraction &rhs) { return *this; }
Fraction &Fraction::operator-=(const Fraction &rhs) { return *this; }

Fraction &Fraction::operator/=(const Fraction &rhs) {
  this->m_nom *= rhs.m_den;
  this->m_den *= rhs.m_nom;

  return *this;
}

Fraction &Fraction::operator/(const Fraction &rhs) {
  this->m_nom *= rhs.m_den;
  this->m_den *= rhs.m_nom;

  return *this;
}

Fraction &Fraction::operator*(const Fraction &rhs) {
  this->m_nom *= rhs.m_nom;
  this->m_den *= rhs.m_den;

  return *this;
}

bool Fraction::operator!=(const Fraction &rhs) { return !(*this == rhs); }

bool Fraction::operator==(const Fraction &rhs) {
  return m_nom == rhs.m_nom && m_den == rhs.m_den;
}

bool Fraction::operator!=(const int32_t &rhs) { return m_nom != rhs; }
bool Fraction::operator==(const int32_t &rhs) { return m_nom == rhs; }
