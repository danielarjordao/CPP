#include "Point.hpp"

// Constructor
Point::Point() : x(0), y(0) {}

// Constructor with float
Point::Point(const float x, const float y) : x(x), y(y) {}

// Copy constructor
Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

// Assignment operator
Point& Point::operator=(const Point &copy)
{
	if (this != &copy)
	{
		(Fixed)this->x = copy.x;
		(Fixed)this->y = copy.y;
	}
	return *this;
}

// Destructor
Point::~Point() {}

/* MEMBER FUNCTIONS */

// This function returns the x coordinate
Fixed Point::getX() const
{
	return x;
}

// This function returns the y coordinate
Fixed Point::getY() const
{
	return y;
}

/* OUTPUT OPERATOR */
// Overload the << operator
// This function returns the x coordinate as a Fixed object

std::ostream& operator<<(std::ostream &out, const Point &point)
{
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return out;
}

