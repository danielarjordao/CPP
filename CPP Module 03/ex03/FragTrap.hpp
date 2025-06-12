#ifndef FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &cpy);
		FragTrap &operator=(FragTrap const &cpy);
		~FragTrap();

		void highFivesGuys();
};

#endif
