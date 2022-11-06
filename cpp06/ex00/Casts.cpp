#include "Casts.hpp"

static bool	isOutOfRange(double value, int type) {
	if (type == Casts::floatType)
		return (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max());
	if (type == Casts::intType)
		return (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max());
	if (type == Casts::charType)
		return (value < 0 || value > std::numeric_limits<char>::max());
	return (true);
}

Casts::Casts(void) :
	_charConvOk(false), _intConvOk(false), _floatConvOk(false), _doubleConvOk(false),
	_charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0),
	_isLimitBool(false), _limit(""), _stringError(false) {
	return ;
}

Casts::Casts(const char *value) : 
	_charConvOk(false), _intConvOk(false), _floatConvOk(false), _doubleConvOk(false),
	_charValue(0), _intValue(0), _floatValue(0.0f), _doubleValue(0.0),
	_isLimitBool(false), _limit(""), _stringError(false) {
	int				type;
	convFunction	Castss[4] = {&Casts::_convFromChar, &Casts::_convFromInt,
									&Casts::_convFromFloat, &Casts::_convFromDouble};

	if (_isLimit(value))
		return ;
	type = _getType(value);
	if (type == Casts::wrongType)
		_stringError = true;
	else
		(this->*(Castss[type]))(value);
}

Casts::Casts(const Casts &Casts) {
	*this = Casts;
}

Casts::~Casts() {
	return ;
}

Casts	&Casts::operator=(const Casts &Casts) {
	(void)Casts;
	return (*this);
}

std::ostream	&operator<<(std::ostream &output, const Casts &Casts) {
	if (Casts.getOutOfRange())
		output << "Error: values out of range" << std::endl;
	else if (Casts.getStringError())
		output << "Error: string format error" << std::endl;
	else {
		Casts.printChar(output);
		Casts.printInt(output);
		Casts.printFloat(output);
		Casts.printDouble(output);
	}
	return (output);
};

void	Casts::printChar(std::ostream &output) const {
	output << "char: ";
	if (!_charConvOk)
	{
		output << "impossible" << std::endl;
		return ;
	}
	if (_charValue > 31 && _charValue < 127)
		output << "'" << _charValue << "'" << std::endl;
	else
		output << "non displayable" << std::endl;
}

void	Casts::printInt(std::ostream &output) const {
	output << "int: ";
	if (!_intConvOk)
	{
		output << "impossible" << std::endl;
		return ;
	}
	output << _intValue << std::endl;
}

void	Casts::printFloat(std::ostream &output) const {
	output << "float: ";
	if (!_floatConvOk)
	{
		output << "impossible" << std::endl;
		return ;
	}
	if (_isLimitBool)
		output << _limit + "f" << std::endl;
	else
	{
		output.precision(1);
		output << std::fixed << _floatValue << "f" << std::endl;
	}
}

void	Casts::printDouble(std::ostream &output) const {
	output << "double: ";
	if (!_doubleConvOk)
	{
		output << "impossible" << std::endl;
		return ;
	}
	if (_isLimitBool)
		output << _limit << std::endl;
	else
	{
		output.precision(1);
		output << std::fixed << _doubleValue << std::endl;
	}
}

bool	Casts::_isLimit(const char *value) {
	const std::string	limits[4] = {"inf" , "+inf", "-inf", "nan"};

	for (int i = 0; i < 4; i++)
	{
		if (value == limits[i] || value == (limits[i] + "f"))
		{
			_isLimitBool = true;
			_limit = limits[i];
			if (i == 1)
				_limit = limits[0];
			_floatConvOk = true;
			_doubleConvOk = true;
			return (true);
		}
	}
	return (false);
}

bool	Casts::getOutOfRange(void) const {
	return (_outOfRange);
}

bool	Casts::getStringError(void) const {
	return (_stringError);
}

int	Casts::_getType(const char *value) {
	int		i;
	bool	isInteger = true;
	bool	isFloat = false;
	bool	noNumeric = true;

	i = 0;
	if (value[0] && value[1] == '\0' && (value[i] < '0' || value[i] > '9'))
		return (Casts::charType);
	if (value[i] == '-' || value[i] == '+')
		i++;
	while (value[i] && value[i] >= '0' && value[i] <= '9')
	{
		i++;
		noNumeric = false;
	}
	if (value[i] == '.')
	{
		isInteger = false;
		i++;
		while (value[i] && value[i] >= '0' && value[i] <= '9')
		{
			noNumeric = false;
			i++;
		}
	}
	if (value[i] == 'f')
	{
		isFloat = true;
		i++;
	}
	if (value[i] || noNumeric || (isFloat && isInteger))
		return (Casts::wrongType);
	if (isFloat)
		return (Casts::floatType);
	if (isInteger)
		return (Casts::intType);
	return (Casts::doubleType);
}

void	Casts::_convFromChar(const char *value) {
	_charValue = value[0];
	_charConvOk = true;
	_intValue = static_cast<int>(_charValue);
	_intConvOk = true;
	_floatValue = static_cast<float>(_charValue);
	_floatConvOk = true;
	_doubleValue = static_cast<double>(_charValue);
	_doubleConvOk = true;
}

void	Casts::_convFromInt(const char *value) {
	if ((strlen(value) == 10 && strcmp(value, "2147483647") > 0)
		|| (value[0] == '-' && strlen(value) == 11 && strcmp(value + 1, "2147483648") > 0)
		|| (value[0] == '+' && strlen(value) == 11 && strcmp(value + 1, "2147483647") > 0))
	{
		_outOfRange = true;
		return ;
	}
	_intValue = atoi(value);
	_intConvOk = true;
	_floatValue = static_cast<float>(_intValue);
	_floatConvOk = true;
	_doubleValue = static_cast<double>(_intValue);
	_doubleConvOk = true;
	if (!isOutOfRange(_doubleValue, Casts::charType))
	{
		_charValue = static_cast<char>(_intValue);
		_charConvOk = true;
	}
}

void	Casts::_convFromFloat(const char *value) {
	char	*end = NULL;

	_floatValue =  std::strtof(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_floatConvOk = true;
	_doubleValue = static_cast<double>(_floatValue);
	_doubleConvOk = true;
	if (!isOutOfRange(_doubleValue, Casts::intType))
	{
		_intValue = static_cast<int>(_floatValue);
		_intConvOk = true;
	}
	if (!isOutOfRange(_doubleValue, Casts::charType))
	{
		_charValue = static_cast<char>(_floatValue);
		_charConvOk = true;
	}
}

void	Casts::_convFromDouble(const char *value) {
	char	*end;

	_doubleValue = std::strtod(value, &end);
	if (value == end)
	{
		_stringError = true;
		return ;
	}
	if (errno == ERANGE)
	{
		_outOfRange = true;
		return ;
	}
	_doubleConvOk = true;
	if (!isOutOfRange(_doubleValue, Casts::floatType))
	{
		_floatValue =  static_cast<float>(_doubleValue);
		_floatConvOk = true;
	}
	if (!isOutOfRange(_doubleValue, Casts::intType))
	{
		_intValue = static_cast<int>(_floatValue);
		_intConvOk = true;
	}
	if (!isOutOfRange(_doubleValue, Casts::charType))
	{
		_charValue = static_cast<char>(_floatValue);
		_charConvOk = true;
	}
}
