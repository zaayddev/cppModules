#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    private:
        std::string	_name;

    public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);

        ~DiamondTrap();

        DiamondTrap&	operator=(const DiamondTrap& other);

        void	setName(const std::string &name);
        const   std::string&	getName(void) const;

        void	attack(const std::string& target);
        void	whoAmI(void);
};

std::ostream&	operator<<(std::ostream& os, const DiamondTrap& obj);

#endif