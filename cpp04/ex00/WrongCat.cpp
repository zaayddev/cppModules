#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "WrongCat Default Constructor called" << std::endl;
    return ;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "WrongCat Copy Contructor called" << std::endl;
    *this = other;
    return ;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called" << std::endl;
    return ;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat SOUND [Meow]" << std::endl;
	return ;
}