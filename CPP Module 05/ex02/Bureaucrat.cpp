#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Canonical form implementation

// Default constructor
Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150) {
	checkGrade();
}

// Constructor with parameters
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
	checkGrade();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {
	checkGrade();
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	if (this != &copy) {
		grade = copy.grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Member functions implementation

// - Getters:

// Get the name of the bureaucrat
const std::string &Bureaucrat::getName() const {
	return name;
}

// Get the grade of the bureaucrat
int Bureaucrat::getGrade() const {
	return grade;
}

// - Subject member functions

// Increment the bureaucrat's grade (decrease the grade number)
void Bureaucrat::incrementGrade() {
	--grade;
	checkGrade();
}

// Decrement the bureaucrat's grade (increase the grade number)
void Bureaucrat::decrementGrade() {
	++grade;
	checkGrade();
}

// Function to attempt to sign a form
void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred while signing the form: " << e.what() << std::endl;
	}
}

// Function to execute a form
void Bureaucrat::executeForm(const AForm &form) const {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (const AForm::GradeTooLowException &e) {
		std::cout << name << " couldn’t execute " << form.getName() << " because " << e.what() << "." << std::endl;
	} catch (const AForm::FormNotSignedException &e) {
		std::cout << name << " couldn’t execute " << form.getName() << " because " << e.what() << "." << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred while executing the form: " << e.what() << std::endl;
	}
}

// - Other member functions

// Check if the bureaucrat's grade is valid
void Bureaucrat::checkGrade() const
{
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

// Exception classes implementation

// GradeTooHighException: Thrown when the grade is too high (less than 1)
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

// GradeTooLowException: Thrown when the grade is too low (greater than 150)
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Overloaded operator for outputting Bureaucrat information
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
