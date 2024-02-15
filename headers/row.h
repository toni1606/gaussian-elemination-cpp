#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Row {
public:
  Row(std::string row, size_t cols);
  Row(Row &&) = default;
  Row(const Row &) = default;
  Row &operator=(Row &&) = default;
  Row &operator=(const Row &) = default;
  ~Row();

  void set_sol(std::string sol);

private:
  std::vector<T> m_data;
  T sol;
  size_t pivot_index;
  bool was_pivot;
};
