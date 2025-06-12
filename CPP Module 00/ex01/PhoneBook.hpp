#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact() const;
		bool addInfo(std::string &info, std::string infoName);
		void printList() const;
	private:
		int index;
		int count;
		Contact contacts[8];
};

#endif
