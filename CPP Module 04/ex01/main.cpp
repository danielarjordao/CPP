#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "Creating individual Dog and Cat:" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nDeleting Dog and Cat:" << std::endl;
	delete j;
	delete i;

	std::cout << "\nCreating an array of Animals:" << std::endl;
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();

	std::cout << "\nDeleting the array of Animals:" << std::endl;
	for (int i = 0; i < size; ++i)
		delete animals[i];

	std::cout << "\nTesting deep copy:" << std::endl;
	Dog original;
	original.setIdea(0, "Chase the cat");
	original.setIdea(1, "Bark at the mailman");

	Dog copy = original;
	copy.setIdea(0, "Sleep all day");

	std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea[0]:     " << copy.getIdea(0) << std::endl;

	std::cout << "Original idea[1]: " << original.getIdea(1) << std::endl;
	std::cout << "Copy idea[1]:     " << copy.getIdea(1) << std::endl;

	return 0;
}
