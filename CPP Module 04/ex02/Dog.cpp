#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->brain->setIdea(index, idea);
	else
		std::cout << "Index out of range" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->brain->getIdea(index);
	else
		return "Index out of range";
}
