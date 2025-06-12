#include "Fixed.hpp"

// Initialize the static member variable
const int Fixed::fractionalBits = 8;

/* CONSTRUCTORS, DESTRUCTOR, ASSIGNMENT OPERATOR */

// Constructor
Fixed::Fixed() : fixedPointValue(0) {}

// Constructor with int
Fixed::Fixed(const int integerValue)
{
	this->fixedPointValue = integerValue << fractionalBits;
}

// Constructor with float
Fixed::Fixed(const float floatValue)
{
	this->fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}
// Destructor
Fixed::~Fixed() {}

// Assignment operator
Fixed& Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->fixedPointValue = copy.getRawBits();
	return *this;
}

/* MEMBER FUNCTIONS */

// This function returns the raw fixed-point value
int Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}

// This function sets the raw fixed-point value
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

// This function returns the absolute value of the Fixed object
Fixed Fixed::abs() const
{
	// Se o valor de rawBits for negativo, retornamos o valor oposto, caso contrário, retornamos o valor normal.
	if (this->getRawBits() < 0)
		return Fixed(-this->getRawBits()); // Cria um novo objeto Fixed com o valor negativo invertido
	return *this; // Se o valor não for negativo, retornamos o objeto atual
}

/* STATIC MEMBER FUNCTIONS */

/* MIN AND MAX FUNCTIONS */
// These functions return the minimum and maximum of two Fixed objects
// There are two versions of each function: one that takes references to Fixed objects
// and one that takes const references to Fixed objects

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

/* COMPARISON OPERATORS */
// These functions allow us to compare Fixed objects using the standard comparison operators
// They return true or false based on the comparison

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedPointValue > other.fixedPointValue)
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedPointValue < other.fixedPointValue)
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedPointValue >= other.fixedPointValue)
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedPointValue <= other.fixedPointValue)
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedPointValue == other.fixedPointValue)
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedPointValue != other.fixedPointValue)
		return true;
	else
		return false;
}

/* ARITHMETIC OPERATORS */
// These functions allow us to perform arithmetic operations on Fixed objects
// They return a new Fixed object that represents the result of the operation

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue + other.fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->fixedPointValue - other.fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->fixedPointValue * other.fixedPointValue) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->fixedPointValue << fractionalBits) / other.fixedPointValue);
	return result;
}

/* INCREMENT AND DECREMENT OPERATORS */
// These functions allow us to increment or decrement the Fixed object
// Prefix increment and decrement operators return a reference to the current object
// Postfix increment and decrement operators return a copy of the current object before the operation

// Pre-increment operator (prefix)
Fixed& Fixed::operator++()
{
	this->fixedPointValue++;
	return *this;
}

// Post-increment operator (postfix)
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedPointValue++;
	return temp;
}

// Pre-decrement operator (prefix)
Fixed& Fixed::operator--()
{
	this->fixedPointValue--;
	return *this;
}

// Post-decrement operator (postfix)
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedPointValue--;
	return temp;
}


/* OUTPUT OPERATOR */
// Overload the << operator
// This function allows us to print the Fixed object directly using std::cout
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
