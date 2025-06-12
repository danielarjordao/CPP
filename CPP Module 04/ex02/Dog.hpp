#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		virtual ~Dog();

		void makeSound() const;
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;

	private:
		Brain *brain;
};

#endif
