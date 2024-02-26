#include "../headers/cyclic_group.h"

CyclicGroup::CyclicGroup() : m_num(0), m_p(1) {}
CyclicGroup::CyclicGroup(int32_t num, int32_t p) : m_num(num), m_p(p) {}

CyclicGroup::operator double() { return static_cast<double>(m_num % m_p); }

std::ostream &operator<<(std::ostream &os, CyclicGroup const &cyc) {
  os << '[' << cyc.m_num << ']';

  return os;
}

std::istream &operator>>(std::istream &is, CyclicGroup &cyc) {
  char parenthesis;
  std::string unparsed_num;

  // [0]

  // [
  is >> parenthesis;
  if (parenthesis != '[')
    throw ParseException();

  // 0
  std::getline(is, unparsed_num, ']');
  // ]
  is >> parenthesis;

  if (parenthesis != ']')
    throw ParseException();

  cyc.m_num = std::stoi(unparsed_num);

  return is;
}
