#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	public:
		// Canonical form
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		// Member functions
		void execute(const Bureaucrat &executor) const;

	private:
		// Member attributes
		// The target of the presidential pardon, which is the name of the person to be pardoned
		const std::string target;

		// Canonical form

		PresidentialPardonForm();
};

#endif
