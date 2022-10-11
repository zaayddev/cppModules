#include "Fixed.hpp"

Fixed::Fixed() : _fixedpoint(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedpoint;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedpoint = raw;
}

Fixed& Fixed::operator=(const Fixed& t){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedpoint = t.getRawBits();
    return *this;
}