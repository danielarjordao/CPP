#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created." << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy)
{
	*this = cpy;
	std::cout << "ScavTrap " << this->name << " has been copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &cpy)
{
	if (this != &cpy)
	{
		name = cpy.name;
		hitPoints = 100;
		energyPoints = 50;
		attackDamage = 20;
	}
	std::cout << "ScavTrap " << this->name << " has been assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (hitPoints <= 0)
		std::cout << name << " is out of hit points, cannot attack!" << std::endl;
	else
		std::cout << name << " is out of energy points, cannot attack!" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}
