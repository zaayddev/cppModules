#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <iostream>

template<typename T>
Array<T>::Array(void) : _size(0), _array(0) {
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {
	for (unsigned int i = 0; i < n; i++)
		_array[i] = 0;
	return ;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _array(new T[0]) {
	*this = other;
	return ;
}

template<typename T>
Array<T>::~Array(void) {
	delete[] _array;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		_size = rhs._size;
		delete[] _array;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](int i) {
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw (std::exception());
	return (_array[i]);
}

template<typename T>
const T&	Array<T>::operator[](int i) const
{
	if (i < 0 || static_cast<unsigned int>(i) >= _size)
		throw (std::exception());
	return (_array[i]);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

#endif