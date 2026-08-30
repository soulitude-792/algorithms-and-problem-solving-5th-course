#include <iostream>

float ReadNumber()
{
	float Num;
	std::cout << "enter a number: ";
	std::cin >> Num;

	return Num;
}

float MyABS(float Number)
{
	if (Number > 0)
		return Number;
	else
		return (Number * -1);
}

int main()
{
	float Number;
	Number = ReadNumber();

	std::cout << "My ABS result: " << MyABS(Number) << std::endl;

	std::cout << "C++ abs Result: "
		<< abs(Number) << std::endl;

	return 0;
}

/*the program recreates the ABS function in C++*/