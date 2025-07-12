#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	public:
		// Canonical form
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		// Member functions
		// - Getters:
		const std::string &getName() const;
		int getGrade() const;
		// - Subject member functions
		void incrementGrade();
		void decrementGrade();
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

	private:
		// Subject attributes
		const std::string name;
		int grade;

		// Canonical form

		Bureaucrat();
};

// Overloaded operator for outputting Bureaucrat information
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
