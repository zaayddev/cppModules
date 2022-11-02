#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{	
	Form *f1 = new ShrubberyCreationForm("337a");;
	Bureaucrat b1 = Bureaucrat("Donald", 42);		
	std::cout << *f1 << std::endl;
	try {
		f1->beSigned(b1);
		f1->execute(b1);
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	delete f1;
}
