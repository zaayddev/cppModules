#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
    std::cout << "Dog Default Constructor called" << std::endl;
	this->_brain = new Brain();
	this->_brain->setIdea("EAT");
	this->_brain->setIdea("SLEEP");
	this->_brain->setIdea("REST");
	this->_brain->setIdea("PEACE");
    return ;
}

Dog::Dog(const Dog& other) {
    std::cout << "Dog Copy Contructor called" << std::endl;
	this->_brain = new Brain();
    *this = other;
    return ;
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
    return ;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
		*this->_brain = *other._brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "DOG SOUND [Woof]" << std::endl;
	return ;
}

Brain*  Dog::getBrain() const {
	return (this->_brain);
}

void  Dog::thoughts() const {
	unsigned int i;

	i = -1;
	while (++i < this->_brain->getNIdea())
		std::cout << this->_brain->getIdea(i) << std::endl;
	return ;
}