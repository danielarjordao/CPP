#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);

	Point inside(2.5f, 2.0f);
	Point outside(5.0f, 5.0f);
	Point edge(2.5f, 0.0f);

	std::cout << "Triangle vertices: " << a << ", " << b << ", " << c << std::endl;

	std::cout << "Checking a inside point " << inside << ": ";
	if (bsp(a, b, c, inside))
		std::cout << "Inside the triangle" << std::endl;
	else
		std::cout << "Outside the triangle" << std::endl;

	std::cout << "Checking an outside point " << outside << ": ";
	if (bsp(a, b, c, outside))
		std::cout << "Inside the triangle" << std::endl;
	else
		std::cout << "Outside the triangle" << std::endl;

	std::cout << "Checking an edge point " << edge << ": ";
	if (bsp(a, b, c, edge))
		std::cout << "Inside the triangle" << std::endl;
	else
		std::cout << "Outside the triangle" << std::endl;

	return 0;
}
