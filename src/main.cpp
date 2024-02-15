#include "../headers/matrix.h"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello, World\n" << std::endl;

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

  // Get Linker Error
  Matrix<int32_t> m(mat, sol);

  std::cout << m;

  return EXIT_SUCCESS;
}
