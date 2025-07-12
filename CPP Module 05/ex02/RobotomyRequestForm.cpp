#include "RobotomyRequestForm.hpp"

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// Static member variable to track if the random number generator has been seeded
bool RobotomyRequestForm::isSeeded = false;

// Canonical form implementation

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("Default Target") {
	seedRandom();
}

// Constructor with parameters
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target){
	seedRandom();
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), target(copy.target) {
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	if (this != &copy) {
		AForm::operator=(copy);
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
}

// Member functions implementation

// Execute the form
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > getExecuteGrade()) {
		throw GradeTooLowException();
	}
	std::cout << "Drilling noises... " << std::endl;
	int randomValue = rand() % 2;
	if (randomValue == 0) {
		std::cout << target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << target << "." << std::endl;
	}
}

// Static member function to seed the random number generator
void RobotomyRequestForm::seedRandom() {
	if (!isSeeded) {
		srand(time(NULL));
		isSeeded = true;
	}
}



