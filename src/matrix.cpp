#include "../headers/matrix.h"

// Take for granted that the bounds checking was done before calling the
// constructor. Meaning othe rows and cols are correct.
template <typename T>
Matrix<T>::Matrix(std::istream mat, std::istream sol, std::size_t cols,
                  std::size_t rows) {
  m_data.reserve(rows);

  for (std::string row; std::getline(mat, row);) {
    m_data.push_back(Row<T>(row, cols));
  }

  std::string s;
  for (size_t i; std::getline(sol, s); i++) {
    m_data[i].set_sol(s);
  }
}
