#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Default Constructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog Copy Contructor called" << std::endl;
    *this = other;
    return ;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
    return ;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "DOG SOUND [Woof]" << std::endl;
	return ;
}