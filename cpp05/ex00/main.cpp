#include "Bureaucrat.hpp"

int main()
{
	{
		try {
			Bureaucrat alex("Alex", 14);
			Bureaucrat alex;
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
	std::cout << std::endl;
	{
		try {
			Bureaucrat alex("Alex", 4);
			Bureaucrat stev;
			stev = alex;
			std::cout << alex << std::endl;
			std::cout << stev << std::endl;		
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
