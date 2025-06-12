#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			safeEOFExit();
		if (command == "ADD")
		{
			phonebook.addContact();
			std::cout << "Contact added" << std::endl;
		}
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			break;
		}
		else if (command.empty())
			continue;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
