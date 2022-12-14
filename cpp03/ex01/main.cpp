#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	killer("Norbert");

	killer.attack("Jeremy");
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
	killer.attack("Ted Bundy");
	killer.guardGate();
	killer.takeDamage(8);
	std::cout << killer << std::endl;
	killer.attack("Richard Ramirez");
	killer.guardGate();
	return (0);
}
