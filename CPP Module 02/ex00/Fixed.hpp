#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		// Constructors and Destructor
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed& operator=(const Fixed &copy);

		// Member functions
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int fixedPointValue;
		static const int fractionalBits;
};

#endif
