#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "--- Bureaucrat and Form Test Program ---\n" << std::endl;
	try {
		std::cout << "Creating Bureaucrat Boss with grade 1 (All permissions)..." << std::endl;
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrubForm("Shrubbery");
		RobotomyRequestForm robotForm("Robot");
		PresidentialPardonForm pardonForm("President");

		// Signing the forms
		std::cout << "\n--- Signing Forms ---\n" << std::endl;
		boss.signForm(shrubForm);
		boss.signForm(robotForm);
		boss.signForm(pardonForm);

		// Executing the forms
		std::cout << "\n--- Executing Forms ---\n" << std::endl;
		boss.executeForm(shrubForm);
		std::cout << std::endl;
		boss.executeForm(robotForm);
		std::cout << std::endl;
		boss.executeForm(pardonForm);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat Worker with grade 50 (Limited permissions)..." << std::endl;
		Bureaucrat worker("Worker", 50);

		ShrubberyCreationForm shrubForm("Shrubbery");
		RobotomyRequestForm robotForm("Robot");
		PresidentialPardonForm pardonForm("President");

		// Signing the forms
		std::cout << "\n--- Signing Forms ---\n" << std::endl;
		worker.signForm(shrubForm);
		worker.signForm(robotForm);
		worker.signForm(pardonForm);

		// Executing the forms
		std::cout << "\n--- Executing Forms ---\n" << std::endl;
		worker.executeForm(shrubForm);
		std::cout << std::endl;
		worker.executeForm(robotForm);
		std::cout << std::endl;
		worker.executeForm(pardonForm);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat Trainee with grade 150 (No permissions)..." << std::endl;
		Bureaucrat trainee("Trainee", 150);

		ShrubberyCreationForm shrubForm("Shrubbery");
		RobotomyRequestForm robotForm("Robot");
		PresidentialPardonForm pardonForm("President");

		// Signing the forms
		std::cout << "\n--- Signing Forms ---\n" << std::endl;
		trainee.signForm(shrubForm);
		trainee.signForm(robotForm);
		trainee.signForm(pardonForm);

		// Executing the forms
		std::cout << "\n--- Executing Forms ---\n" << std::endl;
		trainee.executeForm(shrubForm);
		std::cout << std::endl;
		trainee.executeForm(robotForm);
		std::cout << std::endl;
		trainee.executeForm(pardonForm);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
