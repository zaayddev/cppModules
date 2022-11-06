#ifndef CASTS_HPP
# define CASTS_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <cstring>

class Casts
{
	private:
		bool		_charConvOk;
		bool		_intConvOk;
		bool		_floatConvOk;
		bool		_doubleConvOk;

		char		_charValue;
		int			_intValue;
		float		_floatValue;
		double		_doubleValue;

		int			_isLimitBool;
		std::string	_limit;
		bool		_stringError;
		bool		_outOfRange;

		Casts(void);
		Casts(const Casts &Casts);
		Casts	&operator=(const Casts &Casts);

		bool		_isLimit(const char *value);
		int			_getType(const char *value);

		void		_convFromChar(const char *value);
		void		_convFromInt(const char *value);
		void		_convFromFloat(const char *value);
		void		_convFromDouble(const char *value);

	public:
		Casts(const char *value);
		virtual ~Casts();

		void		printChar(std::ostream &o = std::cout) const;
		void		printInt(std::ostream &o = std::cout) const;
		void		printFloat(std::ostream &o = std::cout) const;
		void		printDouble(std::ostream &o = std::cout) const;
		bool		getOutOfRange(void) const;
		bool		getStringError(void) const;

		static const int	charType = 0;
		static const int	intType = 1;
		static const int	floatType = 2;
		static const int	doubleType = 3;
		static const int	wrongType = 4;
};

std::ostream	&operator<<(std::ostream &output, const Casts &Casts);

typedef void (Casts::*convFunction)(const char *);

#endif
