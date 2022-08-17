#include "whatever.hpp"
#include <iostream>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"

template<typename T>
inline void	testPrint(T const & a, T const & b)
{
	std::cout << "min( " << GREEN(a) << ", " << GREEN(b) << " ) = " << GREEN(::min<T>(a, b)) << std::endl;
	std::cout << "max( " << GREEN(a) << ", " << GREEN(b) << " ) = " << GREEN(::max<T>(a, b)) << std::endl;
}

template<typename T>
inline void testType(T first, T second)
{
	T	a(first);
	T	b(first);
	
	testPrint<T>(a, b);
	std::cout << "a: "<< GREEN(&a) << " b: " << GREEN(&b) << " min: " << GREEN(&::min<T>(a, b)) << " max: " << GREEN(&::max<T>(a, b)) << std::endl;
	std::cout << "\n";

	a = second;
	testPrint<T>(a, b);
	std::cout << "\n";

	::swap<T>(a, b);
	testPrint<T>(a, b);
	std::cout << "\n";

}

int	main(void)
{
	std::cout << PURPLE("Sujects main test\n");
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl;

	std::cout << PURPLE("Int") << std::endl;
	testType<int>(1, 42);

	std::cout << PURPLE("Double") << std::endl;
	testType<double>(4.2, 42.0);

	std::cout << PURPLE("String") << std::endl;
	testType<std::string>("Integer0", "Integer1");
	return (0);
}