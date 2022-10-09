#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	public:
		Contact();
		~Contact();
		void	requestInput(int index);
		void	displayShort();
		void	displayAll();
		void	fitToTen(std::string str);
		int		getIndex();

	private:
		int				index;
		std::string 	firstName;
		std::string 	lastName;
		std::string 	nickname;
		std::string 	phoneNumber;
		std::string 	darkestSecret;
};
#endif