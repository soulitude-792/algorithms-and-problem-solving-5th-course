#include <iostream>
#include <cmath>

float ReadFloatNumber()
{
	float Num;
	std::cout << "enter a float number: ";
	std::cin >> Num;

	return Num;
}

float MySqrt(float Number)
{
	return (pow(Number, 0.5));
}

int main()
{
	float Number;
	Number = ReadFloatNumber();

	std::cout << "\nMy sqrt function result: " << MySqrt(Number);
	std::cout << "\nC++ sqrt function result: " << sqrt(Number) << std::endl;

	return 0;
}