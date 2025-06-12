#include "Fixed.hpp"

// Initialize the static member variable
const int Fixed::fractionalBits = 8;

// Constructor
Fixed::Fixed() : fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with int
Fixed::Fixed(const int integerValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = integerValue << fractionalBits;
}

// Constructor with float
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
// Assignment operator
Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedPointValue = copy.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}
// This function converts the fixed-point value to a float
float Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (1 << fractionalBits);
}

// This function converts the fixed-point value to an integer
int Fixed::toInt(void) const
{
	return this->fixedPointValue >> fractionalBits;
}

// Overload the << operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
