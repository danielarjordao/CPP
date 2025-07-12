#include "Form.hpp"

// Canonical form implementation

// Default constructor
Form::Form() : name("Default Form"), isSigned(false), signGrade(150), executeGrade(150) {
	checkGrade();
}

// Constructor with parameters
Form::Form(const std::string &name, const int signGrade, const int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	checkGrade();
}

// Copy constructor
Form::Form(const Form &copy)
	: name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade) {
	checkGrade();
}

// Assignment operator
Form &Form::operator=(const Form &copy) {
	if (this != &copy) {
		isSigned = copy.isSigned;
	}
	return *this;
}

// Destructor
Form::~Form() {
}

// Member functions implementation

// - Getters

const std::string &Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecuteGrade() const {
	return executeGrade;
}


// - Subject member functions

// Attempt to sign the form by a bureaucrat
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

// - Other member functions

// Check if the form's grades are valid
void Form::checkGrade() const {
	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}
}

// Exception classes implementation
const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

// Exception for when the form is not signed
const char *Form::FormNotSignedException::what() const throw() {
	return "It is not signed";
}

// Overloaded operator for outputting AForm information
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "[Form] Name: " << form.getName()
	<< " | Signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< " | Required Grade to Sign: " << form.getSignGrade()
	<< " | Required Grade to Execute: " << form.getExecuteGrade();
	return os;
}
