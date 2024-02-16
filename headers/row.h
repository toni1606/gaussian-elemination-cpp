#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Row {
private:
  std::vector<T> m_data;
  T m_sol;
  size_t m_pivot_index;
  bool m_was_pivot;

public:
  Row(std::string row, size_t cols) : m_pivot_index(0), m_was_pivot(false) {
    row.reserve(cols);
    std::stringstream data(row);

    std::string iter;
    while (data >> iter) {
      m_data.push_back(from_str(iter));
    }
  }

  Row(Row &&) = default;
  Row(const Row &) = default;
  Row &operator=(Row &&) = default;
  Row &operator=(const Row &) = default;
  ~Row() = default;

  void set_sol(std::string sol) { this->m_sol = from_str(sol); }

  friend std::ostream &operator<<(std::ostream &os, Row const &row) {
    for (auto &elem : row.m_data) {
      os << elem << "\t";
    }
    return os << "|\t" << row.m_sol;
  }

  Row &operator+=(const Row &rhs) {
    assert(m_data.size() == rhs.m_data.size());

    for (size_t i = 0; i < m_data.size(); ++i)
      m_data[i] += rhs.m_data[i];

    m_sol += rhs.sol;
  }

  bool operator!=(const T rhs) {
    for (T &elem : m_data) {
      if (elem != rhs)
        return true;
    }

    return false;
  }

  bool operator==(const T rhs) {
    for (T &elem : m_data) {
      if (elem != rhs)
        return false;
    }

    return true;
  }

  void calc_pivot() {
    m_pivot_index = std::distance(
        m_data.begin(), std::max_element(m_data.begin(), m_data.end()));
  }

  T get() { return m_data[m_pivot_index]; }

  bool is_not_solvable() { return operator==(0) && m_sol != 0; }
  bool was_pivot() { return m_was_pivot; }
  void is_now_pivot() { m_was_pivot = true; }

  // TODO: Overload Mul and MulAssign

private:
  T from_str(std::string s) {
    std::stringstream ss(s);
    T res;
    ss >> res;
    return res;
  }
};
