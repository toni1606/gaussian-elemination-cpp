#include "../headers/cyclic_group.h"
#include "../headers/fraction.h"
#include "../headers/matrix.h"
#include <fstream>
#include <iostream>
#include <ostream>

template <typename T> int run(std::ifstream &mat, std::ifstream &sol) {
  try {
    Matrix<T> m(mat, sol);

    std::cout << "Systemmatrix\n" << m << std::endl;

    if (m.rref())
      std::cout << "The system is solvable!" << std::endl;
    else
      std::cout << "The system is unsolvable!" << std::endl;

    return EXIT_SUCCESS;
  } catch (...) {
    mat.clear();
    mat.seekg(0);
    return EXIT_FAILURE;
  }
}

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

  if (run<Fraction>(mat, sol) == EXIT_SUCCESS) {
    return EXIT_SUCCESS;
  } else if (run<double>(mat, sol) == EXIT_SUCCESS) {
    return EXIT_SUCCESS;
  } else if (run<CyclicGroup>(mat, sol) == EXIT_SUCCESS) {
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}
