#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Brain.hpp"
#include <iostream>
#include <string>


class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		AAnimal &operator=(const AAnimal &copy);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
