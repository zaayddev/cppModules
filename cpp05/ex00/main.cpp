#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat chip("Chip", 1);
		std::cout << chip << std::endl;
		chip.decrGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
