#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_array;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);

		~Array(void);

		Array&	operator=(const Array& rhs);
		T&			operator[](int i);
		const T&	operator[](int i) const;

		unsigned int	size(void) const;
};

#include "Array.tpp"

#endif