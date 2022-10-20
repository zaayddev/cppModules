#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);

		~ClapTrap(void);

		ClapTrap& operator=(const ClapTrap& other);

		const std::string&	getName(void) const;
		unsigned int		getLife(void) const;
		unsigned int		getEnergy(void) const;
		unsigned int		getAttack(void) const;

		void	setName(const std::string &name);
		void	setLife(const unsigned int life);
		void	setEnergy(const unsigned int energy);
		void	setAttack(const unsigned int attack);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		unsigned int	_life;
		unsigned int	_energy;
		unsigned int	_attack;
};

std::ostream	&operator<<(std::ostream &print, const ClapTrap &claptrap);

#endif