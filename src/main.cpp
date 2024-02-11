#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello, World\n" << std::endl;

  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <input_file> <solution_file>"
              << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
