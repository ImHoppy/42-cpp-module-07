#include "whatever.hpp"
#include <iostream>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"

template<typename T>
inline void	testPrint(T const & a, T const & b)
{
	std::cout << "min of " << GREEN(a) << " and " << GREEN(b) << " is " << GREEN(min<T>(a, b)) << std::endl;
	std::cout << "max of " << GREEN(a) << " and " << GREEN(b) << " is " << GREEN(max<T>(a, b)) << std::endl;
}

template<typename T>
inline void testType(T first, T second)
{
	T	a(first);
	T	b(first);
	
	testPrint<T>(a, b);
	std::cout << "a: "<< GREEN(&a) << " b: " << GREEN(&b) << " min: " << GREEN(&min<T>(a, b)) << " max: " << GREEN(&max<T>(a, b)) << std::endl;
	std::cout << "\n";

	a = second;
	testPrint<T>(a, b);
	std::cout << "\n";

	swap<T>(a, b);
	testPrint<T>(a, b);
	std::cout << "\n";

}

int	main(void)
{
	std::cout << PURPLE("Int") << std::endl;
	testType<int>(1, 42);

	std::cout << PURPLE("Double") << std::endl;
	testType<double>(4.2, 42.0);
	return (0);
}