#include "ClapTrap.hpp"

int main()
{
	// Create a ClapTrap object
	ClapTrap claptrap("ClapTrap");
	claptrap.printStatus();
	std::cout << std::endl;

	// Test attack
	claptrap.attack("target");
	// Test takeDamage
	claptrap.takeDamage(5);
	// Test beRepaired
	claptrap.beRepaired(3);
	claptrap.printStatus();
	std::cout << std::endl;

	// Run out of hit points
	claptrap.takeDamage(10);
	// Test more actions after running out of hit points
	claptrap.attack("target");
	claptrap.beRepaired(5);
	claptrap.takeDamage(3);
	claptrap.printStatus();
	std::cout << std::endl;

	ClapTrap claptrap2("ClapTrap2");
	claptrap2.printStatus();
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		claptrap2.attack("target2");
	claptrap2.printStatus();
	std::cout << std::endl;

	// Test actions after running out of energy points
	claptrap2.attack("target2");
	claptrap2.beRepaired(5);
	claptrap2.takeDamage(3);
	claptrap2.printStatus();
	std::cout << std::endl;

	return 0;
}
