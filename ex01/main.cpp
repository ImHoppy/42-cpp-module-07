#include "iter.hpp"
#include <iostream>

#define PURPLE(A) "\033[35m" << A << "\033[0m"
#define GREEN(A) "\033[92m" << A << "\033[0m"

template<typename T>
void	print_array(T & a)
{
	std::cout << a << " ";
}

void	mul(int &i)
{
	i *= 2;
}

void	toUpper(std::string & s)
{
	for (int i = s.length() - 1; i >= 0; i--)
		s[i] = std::toupper(s[i]);
}

int	main(void)
{

	std::cout << PURPLE("Int array\n");
	{
		int int_array[] = {4, 1, 5, 2};

		iter<int>(int_array, 4, print_array);
		std::cout << '\n' << GREEN("Multiply by 2\n");
		iter<int>(int_array, 4, mul);
		iter<int>(int_array, 4, print_array);
		std::cout << "\n\n";
	}

	std::cout << PURPLE("String array\n");
	{
		std::string string_array[] = {"Hello", "world", "!"};
		
		iter<std::string>(string_array, 3, print_array);
		std::cout << '\n' << GREEN("To upper\n");
		iter<std::string>(string_array, 3, ::toUpper);
		iter<std::string>(string_array, 3, print_array);
		std::cout << std::endl;
	}

	return (0);
}