#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &cpy);
		ScavTrap &operator=(ScavTrap const &cpy);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
};

#endif
