#include "Point.hpp"

// Function to calculate the area of a triangle given its vertices
static Fixed triangleArea(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed two = 2;
	Fixed result = (p1.getX() * (p2.getY() - p3.getY()) +
					p2.getX() * (p3.getY() - p1.getY()) +
					p3.getX() * (p1.getY() - p2.getY())) / two;
	return result.abs();
}
// Function to check if a point is inside a triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = triangleArea(a, b, c);

	Fixed a1 = triangleArea(point, b, c);
	Fixed a2 = triangleArea(a, point, c);
	Fixed a3 = triangleArea(a, b, point);

	if (a1 == 0 || a2 == 0 || a3 == 0)
		return false;

	Fixed result = total - (a1 + a2 + a3);

	if (result.abs() <= 0)
		return true;
	else
		return false;
}


