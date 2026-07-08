#include<iostream>
#include<string>
#include<cstdlib>

enum enCharType { SmallLetter = 1, CapitalLetters = 2, SpecialCharacters, Digits };

int RandomNumber(int From, int To)
{
	int RandomNumber{ rand() % (To - From + 1) + From };

	return RandomNumber;
}

int ReadPositiveNumber(std::string Message)
{
	int Num;
	do
	{
		std::cout << Message;
		std::cin >> Num;
	} while (Num <= 0 || Num > 100);

	return Num;
}

char GetRandom(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:

		return char(RandomNumber(97, 122));

		break;

	case enCharType::CapitalLetters:

		return char(RandomNumber(65, 90));

		break;

	case enCharType::SpecialCharacters:

		return char(RandomNumber(33, 47));

		break;

	case enCharType::Digits:

		return char(RandomNumber(48, 57));

	}
	return '\0';

}

std::string GenerateCombination(enCharType CharType, short Length)
{
	std::string Combination{};

	for (int i = 0; i < Length; i++)
	{
		Combination += GetRandom(CharType);
	}
	return Combination;
}

std::string MakeKey()
{
	std::string Key{ "" };

	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4);

	return Key;

}
void FillArrayWithKeys(int length , std::string arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		arr[i] = MakeKey();
	}
}

void PrintStringArray(int length, std::string arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		std::cout << "Array[" << i + 1 << "]: " << arr[i];

		std::cout << '\n';
	}
}

int main()
{
	srand((unsigned)time(NULL));

	std::string arr[100];

	int length{ ReadPositiveNumber("Enter the amount of keys you want to generate: ") };

	FillArrayWithKeys(length, arr);

	PrintStringArray(length, arr);

	return 0;
}