#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	killer("Zodiac");

	killer.attack("Jeffrey Dahmer");
	std::cout << killer << std::endl;
	killer.takeDamage(25);
	std::cout << killer << std::endl;
	killer.takeDamage(18);
	std::cout << killer << std::endl;
	killer.attack("John Wayne Gacy");
	killer.attack("Jack the Ripper");
	std::cout << killer << std::endl;
	killer.beRepaired(40);
	std::cout << killer << std::endl;
	killer.attack("Richard Ramirez");
	killer.highFiveGuys();
	killer.takeDamage(8);
	std::cout << killer << std::endl;
	killer.attack("Ted Bundy");
	killer.highFiveGuys();
	return (0);
}
