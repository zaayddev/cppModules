#include "Bureaucrat.hpp"

int main()
{
	{
		try {
			Form f1 = Form("C00", 10, 11);
			Bureaucrat b1 = Bureaucrat("C01", 9);
			Bureaucrat b2 = Bureaucrat("C02", 1);
			
			std::cout << f1 << std::endl;
			
			b1.signForm(f1);
			std::cout << f1 << std::endl;
			b2.signForm(f1);
			std::cout << f1 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try {
			Form f1 = Form("C00", 10, 11);
			Bureaucrat b1 = Bureaucrat("C01", 44);
			
			std::cout << f1 << std::endl;
			
			b1.signForm(f1);
			std::cout << f1 << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
