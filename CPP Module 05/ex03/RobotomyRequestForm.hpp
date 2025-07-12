#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	public:
		// Canonical form

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();

		// Member functions

		void execute(const Bureaucrat &executor) const;
		static void seedRandom();

	private:
		// Member attributes

		// The target of the robotomy request, which is the name of the robot to be robotomized
		const std::string target;
		// A flag to indicate if the form has been seeded with a random value
		static bool isSeeded;

		// Canonical form

		RobotomyRequestForm();
};

#endif
