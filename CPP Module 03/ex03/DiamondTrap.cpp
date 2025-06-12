#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap()
{
	this->name = "Default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap " << this->name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap " << this->name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	*this = cpy;
	std::cout << "DiamondTrap " << this->name << " has been copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::name = cpy.ClapTrap::name;
		name = cpy.name;
		hitPoints = cpy.hitPoints;
		energyPoints = cpy.energyPoints;
		attackDamage = cpy.attackDamage;
	}
	std::cout << "DiamondTrap " << this->name << " has been assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
