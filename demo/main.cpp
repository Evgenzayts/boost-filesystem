#include <source.hpp>

int main(int argc, char* argv[]) {
  if (argc > 6)
  {
    std::cout << "Too much args" << std::endl;
    return 1;
  }

  my_func(argv[1]);
}