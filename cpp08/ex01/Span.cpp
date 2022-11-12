#include "Span.hpp"

Span::Span() : _size(0) {
}

Span::Span(unsigned int N) : _size(N) {
}

Span::Span(Span const &src) {
    *this = src;
}

Span::~Span() {
}

Span &Span::operator=(Span const &rhs) {
    this->_size = rhs._size;
    this->_vector = rhs._vector;
    return (*this);
}

const char *Span::VectorFullException::what() const throw() {
	return "Class is full, can't add more numbers!";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
	return "You need at least 2 numbers stored to know the span between them!";
}

void    Span::addNumber(int n) {
    if (this->_vector.size() < this->_size)
        this->_vector.push_back(n);
    else
        throw(Span::VectorFullException());
}

unsigned int Span::longestSpan() {
	if (this->_vector.size() <= 1)
		throw (Span::NotEnoughNumbersException());

	std::vector<int> newVector(this->_vector.size(), 0);
	std::adjacent_difference(this->_vector.begin(), this->_vector.end(), newVector.begin());

	std::vector<int>::iterator iter;
	for (iter = newVector.begin(); iter != newVector.end(); ++iter)
		*iter = std::abs(*iter);

	return (*std::max_element(newVector.begin() + 1, newVector.end()));
}

unsigned int Span::shortestSpan() {
	if (this->_vector.size() <= 1)
		throw (Span::NotEnoughNumbersException());

	std::vector<int> newVector(this->_vector.size(), 0);
	std::adjacent_difference(this->_vector.begin(), this->_vector.end(), newVector.begin());

	std::vector<int>::iterator iter;
	for (iter = newVector.begin(); iter != newVector.end(); ++iter)
		*iter = std::abs(*iter);

	return (*std::min_element(newVector.begin() + 1, newVector.end()));
}