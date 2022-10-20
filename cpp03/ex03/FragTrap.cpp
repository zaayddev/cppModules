#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {
	std::cout << "\033[0;34mFragTrap Default Constructor called\033[0m" << std::endl;
	return ;
}

FragTrap::FragTrap(const FragTrap& other) {
	std::cout << "\033[0;34mFragTrap Copy Constructor called\033[0m" << std::endl;
	*this = other;
	return ;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "\033[0;34mFragTrap Constructor called\033[0m" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "\033[0;34mFragTrap Destructor called\033[0m" << std::endl;
	return ;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "\033[0;34mFragTrap assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_life = other._life;
		this->_energy = other._energy;
		this->_attack = other._attack;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& print, const FragTrap& obj) {
	print << static_cast<const ClapTrap&>(obj);
	return (print);
}

void	FragTrap::highFiveGuys() {
	std::cout << "Give it a high five" << std::endl;
	return ;
}
