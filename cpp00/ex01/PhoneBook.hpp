#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		search();
	
	private:
		Contact		contacts[8];
		static int	index;
};

#endif