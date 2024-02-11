#include "../headers/matrix.h"

// Take for granted that the bounds checking was done before calling the
// constructor. Meaning othe rows and cols are correct.
template <typename T>
Matrix<T>::Matrix(std::istream mat, std::istream sol, std::size_t cols,
                  std::size_t rows) {
  m_rows.reserve(rows);

  for (std::string row; std::getline(mat, row);) {
    m_rows.push_back(Row<T>(std::move(row), cols));
  }

  std::string s;
  for (size_t i; std::getline(sol, s); i++) {
    m_rows[i].set_sol(std::move(s));
  }
}
