#include "../headers/matrix.h"
#include <iostream>

// Take for granted that the bounds checking was done before calling the
// constructor. Meaning othe rows and cols are correct.
template <typename T> Matrix<T>::Matrix(std::istream &mat, std::istream &sol) {
  std::string size_str;
  std::getline(mat, size_str);
  std::stringstream size(size_str);

  size_t rows;
  size_t cols;

  size >> rows;
  size >> cols;

  std::cout << "BIIG: " << rows << " " << cols << std::endl;

  m_rows.reserve();

  for (std::string row; std::getline(mat, row);) {
    m_rows.push_back(Row<T>(std::move(row), cols));
  }

  std::string s;
  for (size_t i; std::getline(sol, s); i++) {
    m_rows[i].set_sol(std::move(s));
  }
}

template <typename T> Matrix<T>::~Matrix() { delete m_rows; }
