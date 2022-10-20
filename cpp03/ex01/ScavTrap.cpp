#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 50, 20), _is_keeping(0) {
	std::cout << "\033[0;34mScavTrap Default Constructor called\033[0m" << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "\033[0;34mScavTrap Copy Constructor called\033[0m" << std::endl;
	*this = other;
	return ;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap("", 100, 50, 20), _is_keeping(0) {
	std::cout << "\033[0;34mScavTrap Constructor called\033[0m" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "\033[0;34mScavTrap Destructor called\033[0m" << std::endl;
	return ;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "\033[0;34mScavTrap assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_life = other._life;
		this->_energy = other._energy;
		this->_attack = other._attack;
		this->_is_keeping = other._is_keeping;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& print, const ScavTrap& obj) {
	print << static_cast<const ClapTrap&>(obj);
	print << " \x1B[31mkeeping gate: " << obj.getIsKeeping() << ";\033[0m";
	return (print);
}

bool	ScavTrap::getIsKeeping(void) const {
	return (this->_is_keeping);
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energy == 0 || this->_life == 0)
	{
		std::cout << this->_name << " cannot attack";
		std::cout << std::endl;
		return ;
	}
	std::cout << this->_name << " attacked " << target;
	std::cout << " and dealt " << this->_attack << " damage points" << std::endl;
	this->_energy--;
	return ;
}

void	ScavTrap::guardGate(void) {
	if (this->_is_keeping)
	{
		std::cout << this->_name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
	this->_is_keeping = 1;
	std::cout << this->_name << " is now in Gate keeper mode" << std::endl;
	return ;
}