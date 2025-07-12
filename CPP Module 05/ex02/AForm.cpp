#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Canonical form implementation

// Default constructor
AForm::AForm() : name("Default Form"), isSigned(false), signGrade(150), executeGrade(150) {
	checkGrade();
}

// Constructor with parameters
AForm::AForm(const std::string &name, const int signGrade, const int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	checkGrade();
}

// Copy constructor
AForm::AForm(const AForm &copy)
	: name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade) {
	checkGrade();
}

// Assignment operator
AForm &AForm::operator=(const AForm &copy) {
	if (this != &copy) {
		isSigned = copy.isSigned;
	}
	return *this;
}

// Destructor
AForm::~AForm() {
}

// Member functions implementation

// - Getters

// Get the name of the form
const std::string &AForm::getName() const {
	return name;
}

// Check if the form is signed
bool AForm::getIsSigned() const {
	return isSigned;
}

// Get the sign grade of the form
int AForm::getSignGrade() const {
	return signGrade;
}

// Get the execute grade of the form
int AForm::getExecuteGrade() const {
	return executeGrade;
}


// - Subject member functions

// Attempt to sign the form by a bureaucrat
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

// - Other member functions

// Check if the form's grades are valid
void AForm::checkGrade() const {
	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}
}

// Exception classes implementation

// Exception for when the form grade is too high
const char *AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

// Exception for when the form grade is too low
const char *AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

// Exception for when the form is not signed
const char *AForm::FormNotSignedException::what() const throw() {
	return "it is not signed";
}

// Overloaded operator for outputting AForm information
std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "[Form] Name: " << form.getName()
	<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< " | Required Grade to Sign: " << form.getSignGrade()
	<< " | Required Grade to Execute: " << form.getExecuteGrade();
	return os;
}
