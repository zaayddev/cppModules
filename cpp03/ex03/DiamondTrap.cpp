#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() , _name(name) {
	std::cout << "\033[0;34mDiamondTrap Default Constructor called\033[0m" << std::endl;
	this->_life = FragTrap::_life;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cout << "\033[0;34mDiamondTrap Copy Constructor called\033[0m" << std::endl;
	*this = other;
	return ;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "\033[0;34mDiamondTrap Destructor called\033[0m" << std::endl;
	return ;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "\033[0;34mDiamondTrap assignment operator called\033[0m" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setLife(other.getLife());
		this->setEnergy(other.getEnergy());
		this->setAttack(other.getAttack());
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const DiamondTrap& obj) {
	os << "\x1B[31m[" << obj.getName() << "]\033[0m";
	os << static_cast<const ClapTrap&>(obj);
	return (os);
}

const std::string&	DiamondTrap::getName(void) const {
	return (this->_name);
}

void	DiamondTrap::setName(const std::string &name) {
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_trap";
	return ;
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "It's me " << this->_name << " ,and also they call me " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	this->ScavTrap::attack(target);
	return ;
}