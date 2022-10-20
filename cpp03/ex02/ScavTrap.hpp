#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        bool	_is_keeping;

    public:
        ScavTrap();
        ScavTrap(const ScavTrap& src);
        ScavTrap(const std::string& name);

        virtual ~ScavTrap();

        ScavTrap&	operator=(const ScavTrap& other);

        bool	getIsKeeping(void) const;

        void	attack(const std::string& target);
        void	guardGate(void);
};

std::ostream&	operator<<(std::ostream& print, ScavTrap const &obj);

#endif