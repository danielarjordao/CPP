#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	//	std::cout << "Constructor called" << std::endl;
	this->index = 0;
	this->count = 0;
}
PhoneBook::~PhoneBook()
{
//	std::cout << "Destructor called" << std::endl;
}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	if (this->count == 8)
		std::cout << "Phonebook is full, overwriting the oldest contact" << std::endl;
	while (!addInfo(firstName, "first name")) {}
	while (!addInfo(lastName, "last name")) {}
	while (!addInfo(nickname, "nickname")) {}
	while (!addInfo(phoneNumber, "phone number")) {}
	while (!addInfo(darkestSecret, "darkest secret")) {}
	this->contacts[this->index].setFirstName(firstName);
	this->contacts[this->index].setLastName(lastName);
	this->contacts[this->index].setNickname(nickname);
	this->contacts[this->index].setPhoneNumber(phoneNumber);
	this->contacts[this->index].setDarkestSecret(darkestSecret);
	this->index++;
	this->count++;
	if (this->index == 8)
		this->index = 0;
	if (this->count > 8)
		this->count = 8;
}
void PhoneBook::searchContact() const
{
	if (this->count == 0)
	{
		std::cout << "No contacts found" << std::endl;
		return ;
	}
	printList();
	std::string input;
	int inputindex = 0;
	while (inputindex < 1 || inputindex > this->count)
	{
		std::cout << "Enter the index of the contact you want to see: ";
		if (!std::getline(std::cin, input))
			safeEOFExit();
		if (isNumber(input))
			inputindex = std::atoi(input.c_str());
		else
			inputindex = 0;
		if (inputindex < 1 || inputindex > this->count)
			std::cout << "Please enter a number between 1 and " << this->count << "." << std::endl;
	}
	std::cout << "Contact " << inputindex << ":" << std::endl;
	std::cout << "First Name: " << this->contacts[inputindex - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[inputindex - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[inputindex - 1].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[inputindex - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[inputindex - 1].getDarkestSecret() << std::endl;
}
bool PhoneBook::addInfo(std::string &info, std::string infoName)
{
	std::string str;

	std::cout << "Enter " << infoName << ": ";
	if (!std::getline(std::cin, str))
		safeEOFExit();
	if (str.empty())
		return false;
	else if (!isPrint(str))
	{
		std::cout << "Invalid character in input" << std::endl;
		return false;
	}
	info = str;
	return true;
}

void PhoneBook::printList() const
{
	std::cout << "Contacts:" << std::endl;
	std::cout << std::setw(10) << "Index" << " | "
			<< std::setw(10) << "First Name" << " | "
			<< std::setw(10) << "Last Name" << " | "
			<< std::setw(10) << "Nickname" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (int i = 0; i < this->count; i++)
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::string str = this->contacts[i].getFirstName();
		printListLength(str);
		std::cout << " | ";
		str = this->contacts[i].getLastName();
		printListLength(str);
		std::cout << " | ";
		str = this->contacts[i].getNickname();
		printListLength(str);
		std::cout << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
	}
}
