#include "Conv.hpp"

Conv::Conv() : _value("") {
    whichType();
}

Conv::Conv(char* const value) : _value(value) {
    whichType();
}

Conv::Conv(Conv const & rhs) : _value(rhs._value) {
    whichType();
}

Conv const Conv::operator=(Conv const & rhs) {
    //new (this) Conv(rhs);
    (void) rhs;
    return *this;
}

Conv::~Conv() {
}

const char* Conv::IncorrectTypeException::what() const throw() {
    return "type exception : types are [ char ] || [ int ] || [ float ] || [ double ]";
}

bool Conv::isChar() {
    if (std::strlen(this->_value) == 1 && (this->_value[0] >= 32 && this->_value[0] <= 126)
    && (!(this->_value[0] >= '0' && this->_value[0] <= '9'))) //check value is a char concist of 1len and value is ascii differ 
        return 1;                                                        // of digits
    return 0;
}

bool Conv::isInt() {
    size_t i = 0;

    if (this->_value[i] == '-')
        i++;
    while (i < std::strlen(this->_value))
    {
        if (!std::isdigit(this->_value[i]))
            return 0;
        i++;
    }
    return 1;
}

bool Conv::isFloat() {
    size_t i = 0;

    if (this->_value[i] == '-')
        i++;
    while (i < std::strlen(this->_value) - 1)
    {
        if (!std::isdigit(this->_value[i]) && _value[i] != '.')
            return 0;
        i++;
    }
    if (this->_value[i] == 'f')
        return 1;
    return 0;
}

bool Conv::isDouble() {
    size_t i = 0;

    if (this->_value[i] == '-')
        i++;
    while (i < std::strlen(this->_value) - 1)
    {
        if (!std::isdigit(this->_value[i]) && _value[i] != '.')
            return 0;
        i++;
    }
    if (this->_value[i] == 'f' || !std::isdigit(this->_value[i]))
        return 0;
    return 1;
}

void Conv::whichType() {
    if (isChar())
    {
        _valueC = _value[0];
        _valueI = static_cast<int>(_valueC);
        _valueF = static_cast<float>(_valueC);
        _valueD = static_cast<double>(_valueC);
    }
    else
    {
        _valueC = static_cast<char>(std::strtod(_value, NULL));
        _valueI = static_cast<int>(std::strtod(_value, NULL)); //check cast without strtod funct
        _valueF = static_cast<float>(std::strtod(_value, NULL));
        _valueD = std::strtod(_value, NULL);
    }
    if (!isConstant() && !isInt() && !isChar() && !isDouble() && !isFloat())
        throw IncorrectTypeException();
}

bool Conv::checkValidC() {
    if ((this->_valueI >= 32 && this->_valueI <= 126))
        return 1;
    return 0;
}

bool Conv::checkValidI() {
    if (this->_valueD >= INT_MIN && this->_valueD <= INT_MAX)
        return 1;
    return 0;
}

bool Conv::checkValidF() {
    if (_valueD != 0.0 && _valueD >= -FLT_MIN && _valueD <= FLT_MIN)
        return 0;
    if (this->_valueD >= -FLT_MAX && this->_valueD <= FLT_MAX && checkValidD())
        return 1;
    return 0;
}

bool Conv::checkValidD() {
    errno = 0;
    std::strtod(_value, NULL);
    if (errno == ERANGE)
        return 0;
    return 1;
}

bool Conv::isConstant() {
    if (this->_valueD != this->_valueD || this->_valueF == INFINITY || -this->_valueF == INFINITY)
        return 1;
    return 0;
}

void Conv::printChar() {
    if (checkValidC())
        std::cout << "char: '" << this->_valueC << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void Conv::printInt() {
    if (checkValidI())
        std::cout << "int: " << this->_valueI << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void Conv::printFloat() {
    if (checkValidF()) {
        std::cout << "float: ";
        if (_valueF - _valueI == 0) {
            std::cout << _valueF << ".0f" << std::endl;
        }
        else
            std::cout << _valueF << "f" << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;  
}

void Conv::printDouble() {
    if (checkValidD()) {
        std::cout << "double: ";
        if (_valueD - _valueI == 0) {
            std::cout << _valueD << ".0" << std::endl; // Check this tmrw
        }
        else
            std::cout << _valueD << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}

void Conv::printConv() {
    if (isConstant()) {
        std::cout << "char: Impossible" << std::endl;
        std::cout << "int: Impossible" << std::endl;
        if (this->_valueD != this->_valueD) {
            std::cout << "float: " << _valueF << "f" << std::endl;
            std::cout << "double: " << _valueD << std::endl;
        }
        else if (this->_valueF == INFINITY) {
            std::cout << "float: " << _valueF << "f" << std::endl;
            std::cout << "double: " << _valueD <<std::endl;
        }
        else {
            std::cout << "float: " << _valueF << "f" << std::endl;
            std::cout << "double: " << _valueD << std::endl;
        }
    }
    else {
        printChar();
        printInt();
        printFloat();
        printDouble();
    }
}
