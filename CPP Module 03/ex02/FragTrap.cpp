#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created." << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
	*this = cpy;
	std::cout << "FragTrap " << this->name << " has been copied." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &cpy)
{
	if (this != &cpy)
	{
		name = cpy.name;
		hitPoints = 100;
		energyPoints = 100;
		attackDamage = 30;
	}
	std::cout << "FragTrap " << this->name << " has been assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}
