#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// Generating windows keys. Use this code to get unlimited keys!!!!!!!! I mean, if you generate a few hundered trillions of these then at least one should work, right??

enum enCharType { SmallLetter = 1, CapitalLetters = 2, SpecialCharacters, Digits };

int ReadPositiveNumber(std::string Message)
{
	int Num;
	do
	{
		std::cout << Message;
		std::cin >> Num;
	} while (Num <= 0);

	return Num;
}

int RandomNumber(int From, int To)
{
	int RandomNumber{ rand() % (To - From + 1) + From };

	return RandomNumber;
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
	std::string Key{""};

	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4) + '-';
	Key += GenerateCombination(enCharType::CapitalLetters, 4);

	return Key;

}

void MakeKeys(short NumberofKeys)
{
	for (int i = 1; i <= NumberofKeys; i++)
	{
		std::cout << "Key Number[" << i << "]: "<<MakeKey();
		std::cout << std::endl;
	}

}

int main()
{
	srand((unsigned)time(NULL));

	MakeKeys(ReadPositiveNumber("Enter the amount of codes you want to generate: "));

	return 0;
}