#include "../headers/row.h"

template <typename T>
Row<T>::Row(std::string row, size_t cols) : pivot_index(0), was_pivot(false) {
  row.reserve(cols);
  std::stringstream data(row);

  for (std::string elem; std::getline(data, elem, '\t');) {
    row.push_back(T::parse(elem));
  }
}

template <typename T> void Row<T>::set_sol(std::string sol) {
  this->sol = T::parse(sol);
}
