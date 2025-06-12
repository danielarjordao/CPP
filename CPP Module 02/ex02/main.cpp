#include "Fixed.hpp"
#include <iostream>

#include <iostream>
int main( void )
{
	/*
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
	*/

	Fixed a(5.05f);
	Fixed b(2.0f);
	const Fixed c(5.05f);
	const Fixed d(2.0f);
	std::cout << "Variables:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c const: " << c << std::endl;
	std::cout << "d const: " << d << std::endl;
	std::cout << std::endl;
	std::cout << "Test Min and Max" << std::endl;
	std::cout << "Min: " << Fixed::min(a, b) << std::endl;
	std::cout << "Max: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min const: " << Fixed::min(c, d) << std::endl;
	std::cout << "Max const: " << Fixed::max(c, d) << std::endl;
	std::cout << std::endl;
	std::cout << "Test Comparison Operators" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << std::endl;
	std::cout << "Test Arithmetic Operators" << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	std::cout << std::endl;
	std::cout << "Test Increment and Decrement Operators" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << " (incremento antes, novo valor de a)" << std::endl;
	std::cout << "a: " << a << " (valor de a após incremento)" << std::endl;
	std::cout << "a++: " << a++ << " (incremento depois, valor usado é antigo)" << std::endl;
	std::cout << "a: " << a << " (valor de a após pós-incremento)" << std::endl;
	std::cout << "--a: " << --a << " (decremento antes, novo valor de a)" << std::endl;
	std::cout << "a: " << a << " (valor de a após decremento)" << std::endl;
	std::cout << "a--: " << a-- << " (decremento depois, valor usado é antigo)" << std::endl;
	std::cout << "a: " << a << " (valor de a após pós-decremento)" << std::endl;
	std::cout << std::endl;
	return 0;
}
