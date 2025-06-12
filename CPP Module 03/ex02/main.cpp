#include "FragTrap.hpp"

int main()
{
	// Create a FlagTrap object
	FragTrap frag("FragTrap");
	frag.printStatus();
	std::cout << std::endl;
	// Test the FlagTrap methods
	frag.attack("target");
	frag.takeDamage(10);
	frag.beRepaired(5);
	frag.highFivesGuys();
	frag.printStatus();
	std::cout << std::endl;
	// Run out of hit points
	frag.takeDamage(100);
	frag.printStatus();
	std::cout << std::endl;
	// Test the FlagTrap after running out of hit points
	frag.attack("target");
	frag.beRepaired(5);
	frag.takeDamage(10);
	frag.highFivesGuys();
	frag.printStatus();
	std::cout << std::endl;
	FragTrap frag2("FragTrap2");
	frag2.printStatus();
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		frag2.attack("target");
	frag2.printStatus();
	std::cout << std::endl;
	// Test the FlagTrap after running out of energy points
	frag2.attack("target");
	frag2.beRepaired(5);
	frag2.takeDamage(10);
	frag2.highFivesGuys();
	frag2.printStatus();
	std::cout << std::endl;

	return 0;
}
