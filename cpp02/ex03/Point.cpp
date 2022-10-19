#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::~Point() {
}
		
Point::Point(Point const & p): x(p.getX()), y(p.getY()) {
}

Point::Point(float const x, float const y): x(x), y(y) {
}

Point::Point(Fixed const x, Fixed const y): x(x), y(y) {
}

Point & Point::operator=( Point & rhs) {
	return (rhs);
}

Fixed Point::getX( void ) const
{
	return (this->x);
}

Fixed Point::getY( void ) const
{
	return (this->y);
}