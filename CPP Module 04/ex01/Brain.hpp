#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain();

		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
		
	private:
		std::string ideas[100];
};

#endif
