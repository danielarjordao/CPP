#include "utils.hpp"

void printListLength(std::string &str)
{
	if (str.length() > 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	std::cout << std::setw(10) << str;
}
bool isPrint(const std::string &str)
{
	if ((str).empty())
		return false;
	for (size_t i = 0; i < (str).length(); i++)
	{
		if (str[i] < 32 || str[i] > 126)
			return false;
	}
	return true;
}

bool isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

void safeEOFExit()
{
	std::cout << std::endl << "Input interrupted" << std::endl;
	std::cin.clear();
	exit(1);
}
