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
        bool    operator>(const Fixed& number); 
        bool    operator<(const Fixed& number);
        bool    operator>=(const Fixed& number);
        bool    operator<=(const Fixed& number);
        bool    operator==(const Fixed& number);
        bool    operator!=(const Fixed& nummber);
        Fixed   operator+(const Fixed& number);
        Fixed   operator-(const Fixed& number);
        Fixed   operator*(const Fixed& number);
        Fixed   operator/(const Fixed& number);
        Fixed&   operator++();
        Fixed&   operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);
        static Fixed&	min(Fixed& parm1, Fixed& param2);
        static Fixed	min(const Fixed& parm1, const Fixed& param2);
        static Fixed&	max(Fixed& parm1, Fixed& param2);
        static Fixed	max(const Fixed& parm1, const Fixed& param2);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& print, Fixed const& fixed);

#endif