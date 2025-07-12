#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration of Bureaucrat class
class Bureaucrat;

class AForm
{
	public:
		// Canonical form

		AForm(const std::string &name, const int signGrade, const int executeGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		// Member functions

		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
		// Pure virtual function to be implemented by derived classes
		virtual void execute(const Bureaucrat &executor) const = 0;
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
		// Member attributes

		// The name of the form
		const std::string name;
		// Whether the form is signed or not
		bool isSigned;
		// The grade required to sign the form
		const int signGrade;
		// The grade required to execute the form
		const int executeGrade;

		// Canonical form

		AForm();
};

// Overloaded operator for outputting AForm information
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif

