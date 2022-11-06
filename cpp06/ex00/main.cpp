#include "Casts.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Use ./convert litteralValue" << std::endl;
		return (1);
	}
	Casts	conv(argv[1]);
	std::cout << conv;
	return (0);
}
