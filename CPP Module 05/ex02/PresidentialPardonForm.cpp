#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


// Canonical form implementation

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), target("Default Target") {
}

// Constructor with parameters
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), target(copy.target) {
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	if (this != &copy) {
		AForm::operator=(copy);
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
}

// Member functions implementation

// Execute the form
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw FormNotSignedException();
	} else if (executor.getGrade() > getExecuteGrade()) {
		throw GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
