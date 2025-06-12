#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	*this = cpy;
	std::cout << "ClapTrap " << this->name << " has been copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &cpy)
{
	if (this != &cpy)
	{
		name = cpy.name;
		hitPoints = cpy.hitPoints;
		energyPoints = cpy.energyPoints;
		attackDamage = cpy.attackDamage;
	}
	std::cout << "ClapTrap " << this->name << " has been assigned." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else if (hitPoints <= 0)
		std::cout << name << " is out of hit points, cannot attack!" << std::endl;
	else
		std::cout << name << " is out of energy points, cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		if (amount > hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;}
	else
		std::cout << name << " is out of hit points, cannot take more damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points!" << std::endl;
	}
	else if (hitPoints <= 0)
		std::cout << name << " is out of hit points, cannot be repaired!" << std::endl;
	else
		std::cout << name << " is out of energy points!, cannot be repaired!" << std::endl;
}

void ClapTrap::printStatus() const
{
	std::cout << "ClapTrap " << name << " status: " << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}
