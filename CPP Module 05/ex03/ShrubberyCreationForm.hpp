#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

// Forward declaration of Bureaucrat class
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		// Canonical form

		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();

		// Member functions

		void execute(const Bureaucrat &executor) const;
		void write_ASCII_tree(std::ofstream &file) const;

		// Exception classes
		class FileOpenException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		// Member attributes

		// The target for the form, which is the name of the file to create
		std::string target;

		// Canonical form

		ShrubberyCreationForm();
};

#endif
