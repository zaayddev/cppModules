#include <string>
#include <iostream>
#include <cmath>

bool	checkIsDigit(std::string const &str) {

	for (size_t i = 0; i < str.length() ; i++) {
		if (std::isdigit(str[i]) == false) {
			return false;
		}
	}
	return true;
}

int	main(int ac, char **av) {

    if (ac != 2) {
        std::cout << "error; number of arguments" << std::endl;
        exit(EXIT_FAILURE);
    }

	std::string		input(av[1]);
	double			storeNb = std::atof(input.data());

	if (input.length() == 1 && checkIsDigit(input) == false)
		storeNb = static_cast<double>(av[1][0]);

	std::cout << "char: ";
	if ((input.length() > 1 && std::atoi(input.data()) == 0) ||
			static_cast<char>(storeNb) > std::numeric_limits<char>::max() || static_cast<char>(storeNb) < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else if (static_cast<int>(storeNb) < 32 || static_cast<int>(storeNb) > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(storeNb) << "'" << std::endl;


	std::cout << "int: ";
	if ((input.length() > 1 && std::atoi(input.data()) == 0) ||
			std::numeric_limits<int>::min() > static_cast<int>(storeNb) || std::numeric_limits<int>::max() < static_cast<int>(storeNb))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(storeNb) << std::endl;


	std::cout << "float: ";
	if (fmod(storeNb, 1) == 0)
		std::cout << static_cast<float>(storeNb) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(storeNb) << "f" << std::endl;


	std::cout << "double: ";
	if (fmod(storeNb, 1) == 0)
		std::cout << static_cast<double>(storeNb) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(storeNb) << std::endl;

}
