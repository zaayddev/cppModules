#include "Fixed.hpp"

#include <string>

Fixed::Fixed() {
    _fixedpoint = 0;
}

Fixed::Fixed(const int _fixedpoint) {
	this->_fixedpoint = _fixedpoint << 8;
}

Fixed::Fixed(const float _fixedpoint) {
	this->_fixedpoint = roundf(_fixedpoint * 256);
}

Fixed::Fixed(const Fixed &obj) {
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed &t) {
	_fixedpoint = t.getRawBits();
	return *this;
}

Fixed::~Fixed() {
}

float	Fixed::toFloat() const {
	return ((float) _fixedpoint) / 256;
}

int Fixed::toInt() const {
	return (int) _fixedpoint >> 8;
}

int Fixed::getRawBits(void) const {
    return this->_fixedpoint;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedpoint = raw;
}

std::ostream&	operator<<(std::ostream& print, Fixed const& fixed) {
	print << fixed.toFloat();
	return print;
}

bool	Fixed::operator==(const Fixed& number) {
	if (this->_fixedpoint == number.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& number) {
	if (this->_fixedpoint != number.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(const Fixed &number) {
	if (this->_fixedpoint > number.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &number) {
	if (this->_fixedpoint >= number.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &number) {
	if (this->_fixedpoint < number.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &number) {
	if (this->_fixedpoint <= number.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed &number) {
	return this->toFloat() + number.toFloat();
}

Fixed	Fixed::operator-(const Fixed &number)
{ 
	return (this->toFloat() - number.toFloat());
}

Fixed	Fixed::operator*(const Fixed &number)
{
	return (this->toFloat() * number.toFloat());
}

Fixed	Fixed::operator/(const Fixed &number)
{
	return (this->toFloat() / number.toFloat());
}

Fixed&	Fixed::operator++()
{
	++this->_fixedpoint;
	return *this;	
}

Fixed&	Fixed::operator--()
{
	--this->_fixedpoint;
	return *this;	
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	
	++(*this);
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	
	--(*this);
	return temp;
}

Fixed&	Fixed::min(Fixed& param1, Fixed& param2)
{
	if (param1._fixedpoint < param2._fixedpoint)
		return param1;
	return param2;
}

Fixed	Fixed::min(const Fixed& param1, const Fixed& param2)
{
	if (param1._fixedpoint < param2._fixedpoint)
		return param1;
	return param2;
}

Fixed&	Fixed::max(Fixed& param1, Fixed& param2)
{
	if (param1._fixedpoint > param2._fixedpoint)
		return param1;
	return param2;
}

Fixed	Fixed::max(const Fixed& param1, const Fixed& param2)
{
	if (param1._fixedpoint > param2._fixedpoint)
		return param1;
	return param2;
}
