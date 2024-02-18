#include "../headers/fraction.h"
#include "../headers/matrix.h"
#include <fstream>
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <input_file> <solution_file>"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::ifstream mat(argv[1]);
  std::ifstream sol(argv[2]);

  if (!mat.is_open() || !sol.is_open()) {
    std::cout << "Could not open files: " << argv[1] << " and " << argv[2]
              << std::endl;
    return EXIT_FAILURE;
  }

  Matrix<Fraction> m(mat, sol);

  std::cout << "Systemmatrix\n" << m << std::endl;

  if (m.rref())
    std::cout << "The system is solvable!" << std::endl;
  else
    std::cout << "The system is unsolvable!" << std::endl;

  return EXIT_SUCCESS;
}
