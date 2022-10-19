#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
    private:
        int _fixedpoint;
        static const int _bit = 8;
    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& t);
        ~Fixed();
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& print, Fixed const& fixed);

#endif