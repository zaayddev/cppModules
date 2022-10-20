#include "ClapTrap.hpp"

int	main() {

	ClapTrap	killer("Zodiac");

	std::cout << killer << std::endl;
	killer.attack("Jeffrey Dahmer");
	std::cout << killer << std::endl;
	killer.takeDamage(3);
	std::cout << killer << std::endl;
	killer.takeDamage(4);
	std::cout << killer << std::endl;
	killer.takeDamage(3);
	std::cout << killer << std::endl;
	killer.attack("Jack the Ripper");
	killer.attack("John Wayne Gacy");
	killer.attack("Harold Shipman");
	killer.beRepaired(4);
	std::cout << killer << std::endl;
	killer.attack("Richard Ramirez");
	return (0);
}