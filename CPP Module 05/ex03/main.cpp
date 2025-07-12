#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "--- Intern Form Creation Test Program ---\n" << std::endl;

	try {
		std::cout << "Creating Bureaucrat Boss with grade 1 (All permissions)..." << std::endl;
		Bureaucrat boss("Boss", 1);
		Intern intern;
		std::cout << std::endl;

		AForm *shrubForm = intern.makeForm("shrubbery creation", "Garden");
		AForm *robotForm = intern.makeForm("robotomy request", "Robot");
		AForm *pardonForm = intern.makeForm("presidential pardon", "President");
		std::cout << std::endl;

		if (shrubForm) {
			boss.signForm(*shrubForm);
			boss.executeForm(*shrubForm);
			delete shrubForm;
			std::cout << std::endl;
		}
		if (robotForm) {
			boss.signForm(*robotForm);
			boss.executeForm(*robotForm);
			delete robotForm;
			std::cout << std::endl;
		}
		if (pardonForm) {
			boss.signForm(*pardonForm);
			boss.executeForm(*pardonForm);
			delete pardonForm;
			std::cout << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Creating Bureaucrat Worker with grade 50 (Limited permissions)..." << std::endl;
		Bureaucrat worker("Worker", 50);
		Intern intern;
		std::cout << std::endl;

		AForm *shrubForm = intern.makeForm("shrubbery creation", "Garden");
		AForm *robotForm = intern.makeForm("robotomy request", "Robot");
		AForm *pardonForm = intern.makeForm("presidential pardon", "President");
		std::cout << std::endl;

		if (shrubForm) {
			worker.signForm(*shrubForm);
			worker.executeForm(*shrubForm);
			delete shrubForm;
			std::cout << std::endl;
		}
		if (robotForm) {
			worker.signForm(*robotForm);
			worker.executeForm(*robotForm);
			delete robotForm;
			std::cout << std::endl;
		}
		if (pardonForm) {
			worker.signForm(*pardonForm);
			worker.executeForm(*pardonForm);
			delete pardonForm;
			std::cout << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try {
		std::cout << "Creating Bureaucrat Trainee with grade 150 (No permissions)..." << std::endl;
		Bureaucrat trainee("Trainee", 150);
		Intern intern;
		std::cout << std::endl;

		AForm *shrubForm = intern.makeForm("shrubbery creation", "Garden");
		AForm *robotForm = intern.makeForm("robotomy request", "Robot");
		AForm *pardonForm = intern.makeForm("presidential pardon", "President");
		std::cout << std::endl;

		if (shrubForm) {
			trainee.signForm(*shrubForm);
			trainee.executeForm(*shrubForm);
			delete shrubForm;
			std::cout << std::endl;
		}
		if (robotForm) {
			trainee.signForm(*robotForm);
			trainee.executeForm(*robotForm);
			delete robotForm;
			std::cout << std::endl;
		}
		if (pardonForm) {
			trainee.signForm(*pardonForm);
			trainee.executeForm(*pardonForm);
			delete pardonForm;
			std::cout << std::endl;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "Attempting to create an unknown form..." << std::endl;
		Intern intern;

		AForm *unknownForm = intern.makeForm("unknown form", "Target");

		if (unknownForm) {
			std::cout << "Unknown form created: " << unknownForm->getName() << std::endl;
			delete unknownForm;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
