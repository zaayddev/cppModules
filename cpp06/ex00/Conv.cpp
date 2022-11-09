#include "Conv.hpp"
/* Default constructor */
Conv::Conv() : _value("") {
}
/* Constructor */
Conv::Conv(char* const value) : _value(value) {
    whichType();
}
/* Copy constructor */
Conv::Conv(Conv const & rhs) : _value(rhs._value) {
    whichType();
}
/* Copy assignment operator */
Conv const Conv::operator=(Conv const & rhs) {
    //new (this) Conv(rhs);
    (void) rhs;
    return *this;
}
/* Destructor */
Conv::~Conv() {
}
/* Exeption */
const char* Conv::IncorrectTypeException::what() const throw() {
    return "error; exception";
}
/* Check if value consist of 1 ascii char diffr than digits chars */
bool Conv::isChar() {
    if (std::strlen(this->_value) == 1 && (this->_value[0] >= 32 && this->_value[0] <= 126)
    && (!(this->_value[0] >= '0' && this->_value[0] <= '9')))
        return 1;                                                 
    return 0;
}
/* Check if value is a posit or negt int number */
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
/* Check if value is a posit or neg float number consist of a point and f or F at the end */
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
    if (this->_value[i] == 'f' || this->_value[i] == 'F')
        return 1;
    return 0;
}
/* Check if value is a posit or neg double number consist of a point */
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
    if (this->_value[i] == 'f' || this->_value[i] == 'F' || !std::isdigit(this->_value[i]))
        return 0;
    return 1;
}
/*  if, value consist of one char, cast it to its decimal value 
    else if, value is more than one char, convert it to a double floating point value
    else, value doesn't match the parsing, throw an error   */
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
        _valueI = static_cast<int>(std::strtod(_value, NULL));
        _valueF = static_cast<float>(std::strtod(_value, NULL));
        _valueD = std::strtod(_value, NULL);
    }
    if (!isConstant() && !isInt() && !isChar() && !isFloat() && !isDouble())
        throw IncorrectTypeException();
}

bool Conv::checkValidC() {
    if ((this->_valueC >= 32 && this->_valueC <= 126))
        return 1;
    return 0;
}

bool Conv::checkValidI() {
    if (this->_valueI >= INT_MIN && this->_valueI <= INT_MAX)
        return 1;
    return 0;
}

bool Conv::checkValidF() {
    if (this->_valueF != 0.0 && this->_valueF >= -FLT_MIN && this->_valueF <= FLT_MIN)
        return 0;
    if (this->_valueF >= -FLT_MAX && this->_valueF <= FLT_MAX && checkValidD())
        return 1;
    return 0;
}

bool Conv::checkValidD() {
    errno = 0;
    std::strtod(_value, NULL);
    if (errno == ERANGE) // https://cplusplus.com/reference/cerrno/errno/
        return 0;
    return 1;
}
// https://cplusplus.com/reference/cmath/isnan/
bool Conv::isConstant() {
    if (_valueD != _valueD || _valueF == INFINITY || -_valueF == INFINITY)
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
            std::cout << _valueD << ".0" << std::endl;
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
