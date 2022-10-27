#include "Animal.hpp"

Animal::Animal() : _type("default") {
    std::cout << "Animal default Constructor called" << std::endl;
    return ;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal Constructor called" << std::endl;
    return ;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = other;
    return ;
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
    return ;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

std::string Animal::getType() const {
    return (this->_type);
}

void Animal::makeSound() const {
    std::cout << "ANIMAL SOUND" << std::endl;
    return ;
}

void Animal::thoughts() const {
    std::cout << "NO BRAIN" << std::endl;
    return ;
}