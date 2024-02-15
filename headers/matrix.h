#include "row.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Matrix {
private:
  std::vector<Row<T>> m_rows;

public:
  // Take for granted that the bounds checking was done before calling the
  // constructor. Meaning othe rows and cols are correct.
  Matrix(std::istream &mat, std::istream &sol) {
    std::string tmp_str;

    // Parse the size of the matrix.
    std::getline(mat, tmp_str);
    std::stringstream size(tmp_str);

    size_t rows;
    size_t cols;

    size >> rows >> cols;

    m_rows.reserve(rows);

    // Remove blank line and parse each string subsequently.
    std::getline(mat, tmp_str);
    for (std::string row; std::getline(mat, row);) {
      m_rows.push_back(Row<T>(std::move(row), cols));
    }

    // Ignore the firs line, because it is the same as rows.
    std::getline(sol, tmp_str);
    for (size_t i = 0; std::getline(sol, tmp_str); i++) {
      m_rows[i].set_sol(tmp_str);
    }
  }

  Matrix(Matrix &&) = default;
  Matrix(const Matrix &) = default;
  Matrix &operator=(Matrix &&) = default;
  Matrix &operator=(const Matrix &) = default;
  ~Matrix() = default;

  friend std::ostream &operator<<(std::ostream &os, Matrix const &mat) {
    for (auto &elem : mat.m_rows) {
      os << elem << '\n';
    }

    return os;
  }
};
