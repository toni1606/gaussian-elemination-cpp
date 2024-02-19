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

  // If there was no '/' so the number is a decimal/int set den to 1.
  if (!(is >> frac.m_den))
    frac.m_den = 1;

  return is;
}

// Implement adding (gcd).
Fraction &Fraction::operator+=(const Fraction &rhs) {
  int32_t lcm = Fraction::lcm(this->m_den, rhs.m_den);

  this->m_nom *= lcm / this->m_den;
  this->m_den = lcm;

  int32_t nom = (lcm / rhs.m_den) * rhs.m_nom;

  this->m_nom += nom;

  this->simplify();
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &rhs) {
  int32_t lcm = Fraction::lcm(this->m_den, rhs.m_den);

  this->m_nom *= lcm / this->m_den;
  this->m_den = lcm;

  int32_t nom = (lcm / rhs.m_den) * rhs.m_nom;

  this->m_nom -= nom;

  this->simplify();
  return *this;
}

Fraction &Fraction::operator/=(const Fraction &rhs) {
  this->m_nom *= rhs.m_den;
  this->m_den *= rhs.m_nom;

  this->simplify();
  return *this;
}

Fraction &Fraction::operator/(const Fraction &rhs) {
  this->m_nom *= rhs.m_den;
  this->m_den *= rhs.m_nom;

  this->simplify();
  return *this;
}

Fraction &Fraction::operator*(const Fraction &rhs) {
  this->m_nom *= rhs.m_nom;
  this->m_den *= rhs.m_den;

  this->simplify();
  return *this;
}

bool Fraction::operator!=(const Fraction &rhs) { return !(*this == rhs); }

// Implement == using cross multiplication
bool Fraction::operator==(const Fraction &rhs) {
  return (this->m_nom * rhs.m_den) == (this->m_den * rhs.m_nom);
}

bool Fraction::operator!=(const int32_t &rhs) {
  return *this != Fraction(rhs, 1);
}
bool Fraction::operator==(const int32_t &rhs) {
  return *this == Fraction(rhs, 1);
}

int32_t Fraction::gcd(int32_t a, int32_t b) {
  if (a == 0)
    return b;

  return gcd(a % b, a);
}

int32_t Fraction::lcm(int32_t a, int32_t b) {
  return std::abs(a) * (std::abs(b) / Fraction::gcd(a, b));
}

void Fraction::simplify() {
  int32_t gcd = Fraction::gcd(m_nom, m_den);

  m_nom /= gcd;
  m_den /= gcd;
}
