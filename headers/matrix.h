#include "row.h"
#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Matrix {
public:
  Matrix(std::istream &mat, std::istream &sol);
  Matrix(Matrix &&) = default;
  Matrix(const Matrix &) = default;
  Matrix &operator=(Matrix &&) = default;
  Matrix &operator=(const Matrix &) = default;
  ~Matrix();

private:
  std::vector<T> m_rows;
};
