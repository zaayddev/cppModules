#include "ClapTrap.hpp"

int	main() {
	{
		ClapTrap	a;
		ClapTrap	b(a);
		ClapTrap	c = b;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}
	std::cout << std::endl;
	{
		ClapTrap	killer;

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
	}
	return (0);
}