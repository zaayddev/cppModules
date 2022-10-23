#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "WrongAnimal default Constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal Constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    *this = other;
    return ;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor called" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &other) {
        this ->_type = other.getType();
    }
    return (*this);
}

std::string WrongAnimal::getType() const {
    return (this->_type);
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal SOUND" << std::endl;
    return ;
}