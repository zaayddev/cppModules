#include "Casts.hpp"

#include <iostream>
#include <exception>
#include <cctype>
#include <cmath>

Casts::Casts(const std::string &input)
  : input_(input), value_(0.0)
{
  try {
    const_cast<double &>(value_) = std::stod(input);
  } catch (std::exception &e) {
    throw e;
  }
}

Casts::~Casts(void) {}

const std::string &Casts::get_input(void) const { return input_; }

double Casts::get_value(void) const { return value_; }

void Casts::print(void) const {
  std::cout << std::showpoint;
  std::cout.setf(std::ios::fixed);
  std::cout.precision(1);

  print_to_char();
  print_to_int();
  print_to_float();
  print_to_double();

  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(6);
}

void Casts::print_to_char(void) const {
  double value = get_value();

  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << "impossible" << std::endl;
  else if (not std::isprint(value))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void Casts::print_to_int(void) const {
  double value = get_value();

  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void Casts::print_to_float(void) const {
  float value = static_cast<float>(get_value());

  if (std::isnan(value) || std::isinf(value)) {
    std::cout << std::showpos;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << std::noshowpos;
  }
  else
    std::cout << "float: " << value << "f" << std::endl;
}

void Casts::print_to_double(void) const {
  double value = get_value();

  if (std::isnan(value) || std::isinf(value)) {
    std::cout << std::showpos;
    std::cout << "double: " << value << std::endl;
    std::cout << std::noshowpos;
  }
  else
    std::cout << "double: " << value << std::endl;
}
