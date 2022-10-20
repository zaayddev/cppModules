#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap(const std::string& name);

        ~FragTrap();

        FragTrap&	operator=(const FragTrap& other);

        void	highFiveGuys();
};

std::ostream&	operator<<(std::ostream& print, const FragTrap& obj);

#endif