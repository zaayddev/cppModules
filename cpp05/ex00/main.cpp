#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	juliette("Juliette", 0);

	try {
		std::cout << juliette << std::endl;
		juliette.incrGrade();
		std::cout << juliette << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
}