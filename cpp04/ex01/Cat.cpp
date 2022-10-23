#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat Default Constructor called" << std::endl;
	
    return ;
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat Copy Contructor called" << std::endl;
    *this = other;
    return ;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
    return ;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "CAT SOUND [Meow]" << std::endl;
	return ;
}