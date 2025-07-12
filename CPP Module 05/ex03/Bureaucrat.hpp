#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration of AForm class
class AForm;

class Bureaucrat
{
	public:
		// Canonical form

		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		// Member functions

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(class AForm &form) const;
		void executeForm(const AForm &form) const;
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

	private:
		// Member attributes

		// The name of the bureaucrat
		const std::string name;
		// The grade of the bureaucrat (1 is the highest, 150 is the lowest)
		int grade;

		// Canonical form

		Bureaucrat();
};

// Overloaded operator for outputting Bureaucrat information
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
