#include <source.hpp>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    my_func(nullptr);
  } else {
    my_func(argv[1]);
  }
}