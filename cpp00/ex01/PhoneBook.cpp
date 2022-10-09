#include "PhoneBook.hpp"

int	PhoneBook::index = 0;

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact()
{
	this->contacts[this->index].requestInput(this->index);
	this->index++;
	if (this->index > 7)
		this->index = 0;
}

void PhoneBook::search()
{
	std::string	line;

    std::cout << "\033[0;32m" <<  " ------------------------------------------- " << "\033[0;37m" << "\n";
    std::cout << "\033[0;32m" << "|  index   |first name| last name| nickname |" << "\033[0;37m" << "\n";
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].getIndex())
			this->contacts[i].displayShort();	
	}
	std::cout << "\033[0;32m" << " ------------------------------------------- " << "\033[0;37m" << std::endl;
	std::cout << "\033[0;36mEnter the index of the contact you are searching for, or CANCEL to quit:\033[0;37m ";
	while (getline(std::cin, line))
	{
		if (!line.compare("CANCEL"))
			break;
		if (line.length() == 1 && std::isdigit(line[0]) && std::stoi(line) > 0 && std::stoi(line) < 9)
		{
			if (this->contacts[std::stoi(line) - 1].getIndex())
			{
				this->contacts[std::stoi(line) - 1].displayAll();
				break ;
			}
		}
		std::cout << "INVALID INDEX" << "\n";
		std::cout << "\033[0;36mEnter the index of the contact you are searching for :\033[0;37m ";
	}
}
