#include "Contact.hpp"

Contact::Contact() :
index(0),
firstName(""),
lastName(""),
nickname(""),
phoneNumber(""),
darkestSecret("")
{
}

Contact::~Contact()
{
}

int	EmptyInput(std::string str)
{
	if (str == "" || std::all_of(str.begin(),str.end(), isspace))
	{
		std::cerr << "\x1B[31mBlank Filed ... Please fill it out with propriete informations !\033[0m\t\t" << std::endl;
		return 0;
	}
	return 1;
}

void Contact::requestInput(int index)
{
	this->index = index + 1;
	std::cout << "\033[0;34mFirst name\t:\033[0;37m " ;
    std::getline(std::cin, firstName);
	if (std::cin.eof()) exit (1);
	while (!EmptyInput(firstName))
	{
		std::cout << "\033[0;34mFirst name\t:\033[0;37m " ;
		std::getline(std::cin, firstName);
		if (std::cin.eof()) exit (1);
	}
    std::cout << "\033[0;34mLast name\t:\033[0;37m " ;
    std::getline(std::cin, lastName);
	if (std::cin.eof()) exit (1);
	while (!EmptyInput(lastName))
	{
		std::cout << "\033[0;34mLast name\t:\033[0;37m " ;
		std::getline(std::cin, lastName);
		if (std::cin.eof()) exit (1);
	}
    std::cout << "\033[0;34mNickname\t:\033[0;37m " ;
    std::getline(std::cin, nickname);
	if (std::cin.eof()) exit (1);
	while (!EmptyInput(nickname))
	{
		std::cout << "\033[0;34mNickname\t:\033[0;37m " ;
		std::getline(std::cin, nickname);
		if (std::cin.eof()) exit (1);
	}
    std::cout << "\033[0;34mPhone\t\t:\033[0;37m " ;
    std::getline(std::cin, phoneNumber);
	if (std::cin.eof()) exit (1);
	while (!EmptyInput(phoneNumber))
	{
		std::cout << "\033[0;34mPhone\t:\033[0;37m " ;
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof()) exit (1);
	}
    std::cout << "\033[0;34mDarkest secret\t:\033[0;37m " ;
    std::getline(std::cin, darkestSecret);
	if (std::cin.eof()) exit (1);
	while (!EmptyInput(darkestSecret))
	{
		std::cout << "\033[0;34mDarkest secret\t:\033[0;37m " ;
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof()) exit (1);
	}
}

void Contact::displayShort()
{
	std::cout << "\033[0;32m" << "|" << "\033[0;37m";
	this->fitToTen(std::to_string(this->index));
	this->fitToTen(this->firstName);
	this->fitToTen(this->lastName);
	this->fitToTen(this->nickname);
	std::cout << std::endl;
}

void Contact::displayAll()
{
	std::cout << "\033[0;31mFirst name\t :\033[0;37m "  	<< this->firstName 		<< std::endl;
	std::cout << "\033[0;31mLast name\t :\033[0;37m "  		<< this->lastName		<< std::endl;
	std::cout << "\033[0;31mNickname\t :\033[0;37m " 		<< this->nickname		<< std::endl;
	std::cout << "\033[0;31mPhone\t\t :\033[0;37m " 		<< this->phoneNumber	<< std::endl;
	std::cout << "\033[0;31mDarkest secret\t :\033[0;37m " 	<< this->darkestSecret	<< std::endl;
}

void Contact::fitToTen(std::string str)
{
	if (str.length() > 9)
	{
		str.resize(8);
		str.append(".");
	}
	std::cout << std::setfill(' ') << std::setw(10) << str << "\033[0;32m" << "|"   << "\033[0;37m";
}

int Contact::getIndex()
{
	return (this->index);
}