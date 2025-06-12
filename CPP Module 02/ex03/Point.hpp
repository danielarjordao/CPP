#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &copy);
		~Point();
		Point& operator=(const Point &copy);

		// Member functions
		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed x;
		const Fixed y;
};

// Overloading the output operator
std::ostream& operator<<(std::ostream &out, const Point &point);

#endif
