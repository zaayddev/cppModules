#include "Bureaucrat.hpp"

int main()
{
	try {
		//Form f1 = Form("M37", 10, 5);
		//Bureaucrat b1 = Bureaucrat("Ash", 30);
		//Bureaucrat b2 = Bureaucrat("Quad", 1);
		
		//b1.signForm(f1);
		//b2.signForm(f1);
		Form f1 = Form("C28", 1, 5);
		std::cout << f1 << std::endl;
		Bureaucrat b1 = Bureaucrat("Alex", 30);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		std::cout << b1 << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
