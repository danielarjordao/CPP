#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.type;
	this->brain = new Brain(*copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		std::cout << "Cat assignment operator called" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->brain->setIdea(index, idea);
	else
		std::cout << "Index out of range" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->brain->getIdea(index);
	else
		return "Index out of range";
}
