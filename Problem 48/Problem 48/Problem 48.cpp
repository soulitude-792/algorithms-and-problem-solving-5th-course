#include <iostream>

float ReadFloatNumber()
{
	float Num;
	std::cout << "enter a float number: ";
	std::cin >> Num;

	return Num;
}

int MyFloor(float Number)
{
	if (Number > 0)
		return (int)Number;
	else
		return (int)Number - 1;
}

int main()
{
	float Number;
	Number = ReadFloatNumber();

	std::cout << "\nMy floor result: " << MyFloor(Number);
	std::cout << "\nC++ floor result: " << floor(Number) << std::endl;

	return 0;
}