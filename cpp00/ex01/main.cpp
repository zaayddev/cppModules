#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook test;
	std::string	line;
	std::cout << "\033[0;34mWelcome to your PhoneBook!\033[0;37m" 		<< "\n";
    std::cout << "Available operations are : "							<< "\n";
    std::cout << "\033[0;31mADD :\033[0;37m to add a contact." 			<< "\n";
    std::cout << "\033[0;31mSEARCH :\033[0;37m search for a contact." 	<< "\n";
    std::cout << "\033[0;31mEXIT :\033[0;37m to quit the program." <<"\n";
	while (1)
	{
		std::cout << "\033[0;32mWhat is your operation:\033[0;37m ";
		getline(std::cin, line);
		if (std::cin.eof()) exit (1);
		if (!line.compare("EXIT"))
			break ;
		if (!line.compare("ADD"))
			test.addContact();
		if (!line.compare("SEARCH"))
			test.search();
	}
}