#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamond("Diamond");
	diamond.printStatus();
	std::cout << std::endl;
	// Test the DiamondTrap methods
	diamond.attack("target");
	diamond.takeDamage(10);
	diamond.beRepaired(5);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.printStatus();
	std::cout << std::endl;

	// Run out of hit points
	diamond.takeDamage(100);
	diamond.printStatus();
	std::cout << std::endl;

	// Test the DiamondTrap after running out of hit points
	diamond.attack("target");
	diamond.beRepaired(5);
	diamond.takeDamage(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	diamond.printStatus();
	std::cout << std::endl;

	// Test copy constructor
	DiamondTrap diamond2("Diamond2");
	diamond2.printStatus();
	std::cout << std::endl;

	// Run out of energy points
	for (int i = 0; i < 50; i++)
		diamond2.attack("target");
	diamond2.printStatus();
	std::cout << std::endl;

	// Test the DiamondTrap after running out of energy points
	diamond2.attack("target");
	diamond2.beRepaired(5);
	diamond2.takeDamage(10);
	diamond2.guardGate();
	diamond2.highFivesGuys();
	diamond2.whoAmI();
	diamond2.printStatus();
	std::cout << std::endl;

	return 0;
}
