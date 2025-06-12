#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const int integerValue);
		Fixed(const float floatValue);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed& operator=(const Fixed &copy);

		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		// Static member functions for min and max
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

		// Overloading the comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Overloading the arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Overloading the increment and decrement operators
		Fixed& operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed& operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement

	private:
		int fixedPointValue;
		static const int fractionalBits;
};

// Overloading the output operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
