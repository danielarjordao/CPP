#include "Bureaucrat.hpp"

int main() {

	std::cout << "--- Bureaucrat Test Program ---" << std::endl << std::endl;

	std::cout << "--- Testing Bureaucrat Initialization with Valid Grades ---" << std::endl << std::endl;
	try {
		Bureaucrat medium("Medium", 75);
		std::cout << "Created Bureaucrat: " << medium << std::endl;
		medium.incrementGrade();
		std::cout << "After incrementing grade: " << medium << std::endl;
		medium.decrementGrade();
		std::cout << "After decrementing grade: " << medium << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing Bureaucrat Initialization with Highest Grade and Incrementing ---" << std::endl << std::endl;
	try {
		Bureaucrat high("High", 1);
		std::cout << "Created Bureaucrat: " << high << std::endl;
		std::cout << "Trying to increment grade:" << std::endl;
		high.incrementGrade();
		std::cout << "After incrementing grade: " << high << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing Bureaucrat Initialization with Lowest Grade and Decrementing ---" << std::endl << std::endl;
	try {
		Bureaucrat low("Low", 150);
		std::cout << "Created Bureaucrat: " << low << std::endl;
		std::cout << "Trying to decrement grade:" << std::endl;
		low.decrementGrade();
		std::cout << "After decrementing grade: " << low << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing Bureaucrat Initialization with Invalid Grades (Above Maximum) ---" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << "Created Bureaucrat: " << invalid << std::endl;
		std::cout << "Trying to increment grade:" << std::endl;
		invalid.incrementGrade();
		std::cout << "After incrementing grade: " << invalid << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing Bureaucrat Initialization with Invalid Grades (Below Minimum) ---" << std::endl;
	try {
		Bureaucrat invalid2("Invalid2", 151);
		std::cout << "Created Bureaucrat: " << invalid2 << std::endl;
		std::cout << "Trying to decrement grade:" << std::endl;
		invalid2.decrementGrade();
		std::cout << "After decrementing grade: " << invalid2 << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
