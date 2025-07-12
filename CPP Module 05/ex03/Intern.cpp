#include "Intern.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Canonical form implementation

// Default constructor
Intern::Intern() {
}

// Copy constructor
Intern::Intern(const Intern &copy) {
	(void)copy;
}

// Assignment operator
Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

// Destructor
Intern::~Intern() {
}

// Member functions implementation

// Function to create a ShrubberyCreationForm
AForm *Intern::createShrubbery(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}

// Function to create a RobotomyRequestForm
AForm *Intern::createRobotomy(const std::string &target) const {
	return new RobotomyRequestForm(target);
}

// Function to create a PresidentialPardonForm
AForm *Intern::createPresidential(const std::string &target) const {
	return new PresidentialPardonForm(target);
}


// Member function to create a form based on the form name and target
AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*formCreators[3])(const std::string &) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << " form" << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	throw UnknownFormException();
}

// Exception class implementation
const char *Intern::UnknownFormException::what() const throw() {
	return "Unknown form type";
}
