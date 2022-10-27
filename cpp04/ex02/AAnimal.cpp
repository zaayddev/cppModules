#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("default") {
    std::cout << "AAnimal default Constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << "AAnimal Constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "AAnimal Copy Constructor called" << std::endl;
    *this = other;
    return ;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal Destructor called" << std::endl;
    return ;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignment operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

std::string AAnimal::getType() const {
    return (this->_type);
}
