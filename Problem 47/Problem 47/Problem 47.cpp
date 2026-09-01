
#include <iostream>

float GetFractionPart(float Number)
{
	return (Number - (int)Number);
}

int MyRound(float Number)
{
	int IntPart;
	IntPart = int(Number);

	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) >= 0.5)
	{
		if (Number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

float ReadFloatNumber()
{
	float Num;
	std::cout << "enter a float number: ";
	std::cin >> Num;

	return Num;
}

int main()
{
	float Number = ReadFloatNumber();

	std::cout << "\nMy round function result: " << MyRound(Number);
	std::cout << "\nOriginal C++ round function result: " << round(Number) << std::endl;

	return 0;
}
