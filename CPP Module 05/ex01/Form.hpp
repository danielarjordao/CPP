#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

// Forward declaration of Bureaucrat class
class Bureaucrat;

class Form
{
	public:
		// Canonical form
		Form(const std::string &name, const int signGrade, const int executeGrade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		// Member functions
		// - Getters
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		// - Subject member functions
		void beSigned(const Bureaucrat &bureaucrat);
		// - Other member functions
		void checkGrade() const;

		// Exception classes
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
				class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		// Subject attributes
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;

		// Canonical form
		
		Form();
};

// Overloaded operator for outputting Form information
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif

