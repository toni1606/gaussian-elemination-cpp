#include "row.h"
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#pragma once

template <typename T> class Matrix {
private:
  std::vector<Row<T>> m_rows;
  size_t pivot_row_id;

public:
  // Take for granted that the bounds checking was done before calling the
  // constructor. Meaning othe rows and cols are correct.
  Matrix(std::istream &mat, std::istream &sol) : pivot_row_id(0) {
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

  bool operator!=(const T rhs) {
    for (Row<T> &elem : m_rows) {
      if (elem != rhs)
        return true;
    }

    return false;
  }

  bool rref() {
    if (!elem())
      return false;
    return backprop();
  }

private:
  bool is_elem_over() {
    for (auto &row : m_rows) {
      if (!row.was_pivot() && row != 0)
        return false;
    }

    return true;
  }

  bool is_not_solvable() {
    for (auto &row : m_rows) {
      if (row.is_not_solvable())
        return true;
    }

    return false;
  }

  void select_pivot() {
    for (size_t i = 0; i < m_rows.size(); i++) {
      if (!m_rows[i].was_pivot() && m_rows[i] != 0) {
        pivot_row_id = i;
        break;
      }
    }

    m_rows[pivot_row_id].is_now_pivot();
    m_rows[pivot_row_id].calc_pivot();
  }

  // Performs the elemination phase and returns if system is solvable.
  bool elem() {
    while (!is_elem_over()) {
      select_pivot();

      // Set pivot to 1 (: pivot)
      m_rows[pivot_row_id] /= m_rows[pivot_row_id].get();
    }

    return !this->is_not_solvable();
  }

  bool backprop() { return false; }
};
