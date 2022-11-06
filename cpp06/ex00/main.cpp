#include "Casts.hpp"

#include <iostream>
#include <exception>
#include <iomanip>

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      Casts casts(argv[1]);
      casts.print();
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  else
    std::cerr << "usage : ./convert [literal] (only one)" << std::endl;
}
