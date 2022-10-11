#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int _fixedpoint;
        static const int _bit = 8;
    public:
        Fixed();
        Fixed& operator=(const Fixed& t);
        Fixed(const Fixed& obj);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif