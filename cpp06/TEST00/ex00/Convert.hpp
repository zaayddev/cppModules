#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <exception>
# include <stdio.h>
# include <limits>
# include <climits>

class Convert
{
    private:
        std::string _input;
        char        _c;
        int         _i;
        float       _f;
        double      _d;

    public:
        Convert();
        Convert(std::string input);
        Convert(const Convert& rhs);
        ~Convert();

        Convert& operator=(const Convert& rhs);

        class InvalidInputException: public std::exception
        {
            public:
                const char* what() const throw();
        };

        std::string getInput() const;
        char        getChar() const;
        int         getInt() const;
        float       getFloat() const;
        double      getDouble() const;

        void        setInput(std::string input);
        void        setChar(char c);
        void        setInt(int i);
        void        setFloat(float f);
        void        setDouble(double d);

        bool        isChar(std::string input);
        bool        isInt(std::string input);
        bool        isFloat(std::string input);
        bool        isDouble(std::string input);
        bool        isOther(std::string input);
        bool        isIntOverflow();

        void        detectTypeAndConversion();
};

#endif