#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _life(100), _energy(50), _attack(20) {
	std::cout << "\033[0;34mDefault Constructor called\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _life(100), _energy(50), _attack(20) {
	std::cout << "\033[0;34mConstructor called\033[0m" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other.getName()), _life(other.getLife()), _energy(other.getEnergy()), _attack(other.getAttack()) {
	std::cout << "\033[0;34mCopy Constructor called\033[0m" << std::endl;
	return ;
}

/*ClapTrap::ClapTrap(const std::string& name, int life, int energy, int attack) : _name(name), _life(life), _energy(energy), _attack(attack)
{
	std::cout << "\033[0;34mClapTrap constructor called\033[0m" << std::endl;
	return ;
}*/

ClapTrap::~ClapTrap() {
	std::cout << "\033[0;34mDestructor called\033[0m" << std::endl;
	return ;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	this->setName(other.getName());
	this->setLife(other.getLife());
	this->setEnergy(other.getEnergy());
	this->setAttack(other.getAttack());
	return (*this);
}

const std::string&	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getLife(void) const {
	return (this->_life);
}

unsigned int	ClapTrap::getEnergy(void) const {
	return (this->_energy);
}

unsigned int	ClapTrap::getAttack(void) const {
	return (this->_attack);
}

void	ClapTrap::setName(const std::string &name) {
	this->_name = name;
	return ;
}

void	ClapTrap::setLife(const unsigned int life) {
	this->_life = life;
	return ;
}

void	ClapTrap::setEnergy(const unsigned int energy) {
	this->_energy = energy;
	return ;
}

void	ClapTrap::setAttack(const unsigned int attack) {
	this->_attack = attack;
	return ;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_energy == 0 || this->_life == 0) {
		std::cout << this->_name << " cannot attack" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacked " << target << " and dealt ";
	std::cout << this->_attack << " attack damage points" << std::endl;
	this->_energy--;
	this->_attack -= _attack;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	unsigned int	damage;

	if (this->_life >= amount)
		damage = amount;
	else
		damage = this->_life;
	std::cout << this->_name << " has been hit for " << damage << " hit points" << std::endl;
	this->_life -= damage;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy == 0) {
		std::cout << this->_name << " cannot heal" << std::endl;
		return ;
	}
	std::cout << this->_name << " is healing " << std::endl;
	this->_life += amount;
	this->_energy--;
	return ;
}

std::ostream	&operator<<(std::ostream &print, const ClapTrap &claptrap) {
	print << "\x1B[31m[" << claptrap.getName()   << "] ";
	print << "life: " 	 << claptrap.getLife() 	 << "; ";
	print << "energy: "  << claptrap.getEnergy() << "; ";
	print << "attack: "  << claptrap.getAttack() << ";\033[0m";
	return (print);
}