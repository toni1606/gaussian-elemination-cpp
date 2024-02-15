#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Row {
public:
  Row(std::string row, size_t cols) : pivot_index(0), was_pivot(false) {
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

  void set_sol(std::string sol) { this->sol = from_str(sol); }

private:
  std::vector<T> m_data;
  T sol;
  size_t pivot_index;
  bool was_pivot;

  T from_str(std::string s) {
    std::stringstream ss(s);
    T res;
    ss >> res;
    return res;
  }

  friend std::ostream &operator<<(std::ostream &os, Row const &row) {
    for (auto &elem : row.m_data) {
      os << elem << "\t";
    }
    return os << "|\t" << row.sol;
  }
};
