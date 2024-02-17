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
  size_t m_pivot_row_id;

  size_t cols;

public:
  // Take for granted that the bounds checking was done before calling the
  // constructor. Meaning othe rows and cols are correct.
  Matrix(std::istream &mat, std::istream &sol) : m_pivot_row_id(0) {
    std::string tmp_str;

    // Parse the size of the matrix.
    std::getline(mat, tmp_str);
    std::stringstream size(tmp_str);

    size_t rows;
    size_t cols;

    size >> rows >> cols;

    this->cols = cols;

    m_rows.reserve(rows);

    // Remove blank line and parse each string subsequently.
    std::getline(mat, tmp_str);
    for (std::string row; std::getline(mat, row);) {
      m_rows.push_back(Row<T>(std::move(row), cols));
    }

    // Ignore the firs line, because it is the same as rows.
    // And blank line.
    std::getline(sol, tmp_str);
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
    if (!resub())
      return false;

    solution_space();

    return true;
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
        m_pivot_row_id = i;
        break;
      }
    }

    m_rows[m_pivot_row_id].is_now_pivot();
    m_rows[m_pivot_row_id].calc_pivot();
  }

  size_t last_pivot() {
    for (size_t i = m_rows.size() - 1; i < m_rows.size(); i--) {
      if (m_rows[i].was_pivot())
        return i;
    }

    assert(0 && "ERROR: Unreachable");
  }

  // Performs the elemination phase and returns if system is solvable.
  bool elem() {
    std::cout << "Eleminationphase" << std::endl;

    while (!is_elem_over()) {
      select_pivot();

      // Set pivot to 1 (: pivot)
      m_rows[m_pivot_row_id] /= m_rows[m_pivot_row_id].get_pivot();

      // Subtract the right amount from each row.
      for (size_t i = m_pivot_row_id + 1; i < m_rows.size(); i++) {
        m_rows[i] -= m_rows[m_pivot_row_id];
      }

      std::cout << *this << std::endl;
    }

    return !this->is_not_solvable();
  }

  bool resub() {
    std::cout << "Resubstitutionphase" << std::endl;

    // Weird check because when 0 it underflows and i >= 0 is true.
    for (size_t i = last_pivot(); i < m_rows.size(); i--) {

      // Subtract the right amount from each row.
      for (size_t j = 0; j < i; j++) {
        m_rows[j] -= m_rows[i];
      }

      std::cout << *this << std::endl;
    }

    return true;
  }

  std::vector<size_t> get_free_vars() {
    std::vector<size_t> vars;
    for (size_t i = 0; i < cols; i++) {
      bool flag = false;
      for (auto &row : m_rows) {
        if (i == row.pivot_index()) {
          flag = true;
          break;
        }
      }

      if (!flag) {
        vars.push_back(i);
      }
    }

    return vars;
  }

  void solution_space() {
    // Get free variables (column ids).
    std::vector<size_t> free_variables = get_free_vars();

    std::cout << "The (affine) soultion space is given by the set" << std::endl;

    for (auto &row : m_rows) {
      std::cout << "{ (" << row.sol() << ")\t";
      for (auto &f : free_variables) {
        std::cout << "- mu_" << f << "(" << row.get(f) << ")\t";
      }
      std::cout << "}" << std::endl;
    }
  }
};
