#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

// Forward declaration of AForm class
class AForm;

class Intern
{
	public:
		// Canonical form

		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &copy);
		~Intern();

		// Member functions

		AForm *makeForm(const std::string &formName, const std::string &target) const;
		AForm *createShrubbery(const std::string &target) const;
		AForm *createRobotomy(const std::string &target) const;
		AForm *createPresidential(const std::string &target) const;

		// Exception class

		class UnknownFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
