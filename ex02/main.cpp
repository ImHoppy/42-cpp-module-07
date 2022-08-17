#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750

void	subject_main()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "tmp:  value[ " << tmp[0] << " ], address [ " << &tmp[0] << " ]\n";
		std::cout << "test: value[ " << test[0] << " ], address [ " << &test[0] << " ]\n";
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

}

int main(int, char**)
{
	subject_main();

	Array<std::string> b(10);
	b[0] = "Hi";
	b[1] = "42";
	b[2] = "!";
	for (size_t i = 0; i < b.size(); i++)
	{
		std::cout << b[i] << ' ';
	}
	std::cout << '\n';	
	return 0;
}