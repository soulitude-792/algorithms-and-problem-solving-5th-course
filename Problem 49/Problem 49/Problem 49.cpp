#include <iostream>
#include <cmath>

float GetFractionPart(float Number)
{
	return (Number - (int)Number);
}

float ReadFloatNumber()
{
	float Num;
	std::cout << "enter a float number: ";
	std::cin >> Num;

	return Num;
}

int MyCeil(float Number)
{
	if (GetFractionPart(Number)> 0.0f)
	{
		return (int)Number + 1;
	}

	return (int)Number;
}

int main()
{
	float Number;
	Number = ReadFloatNumber();
	std::cout << "\nMyCeil result: " << MyCeil(Number);
	std::cout << "\nC++ ciel result: " << ceil(Number) << std::endl;

	return 0;
}