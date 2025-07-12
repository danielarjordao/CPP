#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	std::cout << "--- Bureaucrat Test Program ---" << std::endl << std::endl;

	std::cout << "--- Testing Form Initialization with Valid Grades ---" << std::endl << std::endl;
	try {
		Bureaucrat bureaucratHigh("BureaucratHigh", 1);
		Bureaucrat bureaucratMedium("BureaucratMedium", 25);
		Bureaucrat bureaucratLow("BureaucratLow", 50);

		Form form1("Form1", 50, 100);
		std::cout << "Created Form: " << form1 << std::endl;
		std::cout << std::endl;

		std::cout << "Trying to sign the form with a bureaucrat of grade 1:" << std::endl;
		bureaucratHigh.signForm(form1);
		std::cout << "After signing, Form: " << form1 << std::endl
			<< std::endl;

		Form form2("Form2", 50, 100);
		std::cout << "Created Form: " << form2<< std::endl;
		std::cout << std::endl;

		std::cout << "Trying to sign the form with a bureaucrat of grade 50:" << std::endl;
		bureaucratLow.signForm(form2);
		std::cout << "After signing, Form: " << form2 << std::endl
			<< std::endl;

		Form form3("Form3", 50, 100);
		std::cout << "Created Form: " << form3<< std::endl;
		std::cout << std::endl;
		std::cout << "Trying to sign the form with a bureaucrat of grade 25:" << std::endl;
		bureaucratMedium.signForm(form3);
		std::cout << "After signing, Form: " << form3 << std::endl
			<< std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "--- Testing Form Initialization with Invalid Grades (Above Maximum) ---" << std::endl << std::endl;
	try {
		Form form4("Form4", 0, 100);
		std::cout << "Created Form: " << form4 << std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Testing Form Initialization with Invalid Grades (Below Minimum) ---" << std::endl << std::endl;
	try {
		Form form5("Form5", 151, 100); // This should throw GradeTooLowException
		std::cout << "Created Form: " << form5 << std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "--- Testing Form Signing with Insufficient Bureaucrat Grade ---" << std::endl << std::endl;
	try {
		Bureaucrat bureaucratInsufficient("BureaucratInsufficient", 60);

		Form form6("Form6", 50, 100);
		std::cout << "Created Form: " << form6 << std::endl;
		std::cout << std::endl;

		std::cout << "Trying to sign the form with a bureaucrat of grade 60:" << std::endl;
		bureaucratInsufficient.signForm(form6);

		std::cout << "After signing, Form: " << form6 << std::endl
			<< std::endl;
	}
	catch (const Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}
