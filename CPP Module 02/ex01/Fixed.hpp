#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		// Constructors and Destructor
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


	private:
		int fixedPointValue;
		static const int fractionalBits;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
