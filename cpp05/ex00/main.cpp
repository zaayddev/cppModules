#include "Bureaucrat.hpp"

int main()
{
	{
		try {
			Bureaucrat alex("Alex", 1);
			alex.decrGrade();
			std::cout << alex << std::endl;
			alex.incrGrade();
			std::cout << alex << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Bureaucrat alex("Alex", 151);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
