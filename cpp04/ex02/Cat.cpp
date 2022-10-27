#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    std::cout << "Cat Default Constructor called" << std::endl;
	this->_brain = new Brain();
	this->_brain->setIdea("EAT");
	this->_brain->setIdea("SLEEP");
	this->_brain->setIdea("REST");
    return ;
}

Cat::Cat(const Cat& other) {
    std::cout << "Cat Copy Contructor called" << std::endl;
	this->_brain = new Brain();
    *this = other;
    return ;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
    return ;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		*(this->_brain) = *other.getBrain();
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "CAT SOUND [Meow]" << std::endl;
	return ;
}

Brain*  Cat::getBrain() const {
	return (this->_brain);
}

void  Cat::thoughts() const {
	unsigned int i;

	i = -1;
	while (++i < this->_brain->getNIdea())
		std::cout << this->_brain->getIdea(i) << std::endl;
	return ;
}