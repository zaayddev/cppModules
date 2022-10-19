#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _fixedpoint = 0;
}

Fixed::Fixed(const Fixed& obj) {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedpoint = number << _bit;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    this->_fixedpoint = roundf(number * 256);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_fixedpoint;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedpoint = raw;
}

float	Fixed::toFloat() const
{
	return ((float) _fixedpoint) / 256;
}

int Fixed::toInt() const 
{
	return (int) _fixedpoint >> _bit;
}

Fixed& Fixed::operator=(const Fixed& t){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedpoint = t.getRawBits();
    return *this;
}

std::ostream&	operator<<(std::ostream& print, Fixed const& fixed)
{
	print << fixed.toFloat();
	return print;
}