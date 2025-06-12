#include "ScavTrap.hpp"

int main()
{
	// Create a ScavTrap object
	ScavTrap scav("ScavTrap");
	scav.printStatus();
	std::cout << std::endl;

	// Test the ScavTrap methods
	scav.attack("target");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();
	scav.printStatus();
	std::cout << std::endl;

	// Run out of hit points
	scav.takeDamage(100);
	scav.printStatus();
	std::cout << std::endl;

	// Test the ScavTrap after running out of hit points
	scav.attack("target");
	scav.beRepaired(5);
	scav.takeDamage(10);
	scav.guardGate();
	scav.printStatus();
	std::cout << std::endl;

	ScavTrap scav2("ScavTrap2");
	scav2.printStatus();
	std::cout << std::endl;

	for (int i = 0; i < 50; i++)
		scav2.attack("target");
	scav2.printStatus();
	std::cout << std::endl;

	// Test the ScavTrap after running out of energy points
	scav2.attack("target");
	scav2.beRepaired(5);
	scav2.takeDamage(10);
	scav2.guardGate();
	scav2.printStatus();
	std::cout << std::endl;

	return 0;
}
