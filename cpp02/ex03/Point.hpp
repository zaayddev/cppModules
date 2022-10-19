#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		~Point();
		Point(Point const & p);
		Point(float const x, float const y);
		Point(Fixed const x, Fixed const y);
		Point & operator=( Point & rhs);
		void	setX(Fixed f);
		void	setY(Fixed f);
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		Fixed	const x;
		Fixed	const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif