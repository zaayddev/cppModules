#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	killer("Zodiac");

	killer.attack("John Wayne Gacy");
	std::cout << killer << std::endl;
	killer.takeDamage(25);
	std::cout << killer << std::endl;
	killer.takeDamage(18);
	std::cout << killer << std::endl;
	killer.attack("Jeffrey Dahmer");
	killer.attack("Harold Shipman");
	std::cout << killer << std::endl;
	killer.beRepaired(40);
	killer.whoAmI();
	std::cout << killer << std::endl;
	killer.attack("Richard Ramirez");
	killer.highFiveGuys();
	killer.takeDamage(8);
	std::cout << killer << std::endl;
	killer.attack("Ted Bundy");
	killer.highFiveGuys();
}
