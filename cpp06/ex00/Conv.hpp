#ifndef CONV_HPP
#define CONV_HPP

#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <exception>
#include <cerrno>

class Conv
{
    private:
        const char* _value;
        char        _valueC;
        int         _valueI;
        float       _valueF;
        double      _valueD;

        bool isInt();
        bool isChar();
        bool isFloat();
        bool isDouble();
        void whichType();
        bool checkValidC();
        bool checkValidI();
        bool checkValidF();
        bool checkValidD();
        bool isConstant();
        void printChar();
        void printInt();
        void printFloat();
        void printDouble();
        class IncorrectTypeException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    public:
        Conv();
        Conv(char* const value);
        Conv(Conv const & rhs);
        Conv const operator=(Conv const & rhs);
        ~Conv();
        void printConv();
};

#endif