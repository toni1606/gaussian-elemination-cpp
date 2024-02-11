#include <sstream>
#include <string>
#include <vector>

template <typename T> class Matrix {
public:
  Matrix(std::istream mat, std::istream sol, std::size_t cols,
         std::size_t rows);
  Matrix(Matrix &&) = default;
  Matrix(const Matrix &) = default;
  Matrix &operator=(Matrix &&) = default;
  Matrix &operator=(const Matrix &) = default;
  ~Matrix();

private:
  std::vector<T> m_data;
};
