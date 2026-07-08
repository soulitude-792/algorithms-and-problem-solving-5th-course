#include<iostream>
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

int CheckNumberPositionInArray(int NumberToSearchFor, int length, int arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		if (arr[i] == NumberToSearchFor)
		{
			return i;
		}
	}
	return -1;
}

void FillArrayWithRandomNumbers(int length, int arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Length, int arr[100])
{
	for (int i{ 0 }; i < Length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int NumbertoCheck{};
	int length;
	short NumberPositionInArray{};

	length = ReadPositiveNumber("Enter the amount of numbers you want to generate: ");

	FillArrayWithRandomNumbers(length, arr);

	std::cout << "\nArray elements: ";
	PrintArray(length, arr);

	NumbertoCheck = ReadPositiveNumber("\n\nEnter the number you want to check: ");

	NumberPositionInArray = CheckNumberPositionInArray(NumbertoCheck, length, arr);

	if (NumberPositionInArray == -1)
	{
		std::cout << "\nThe number is not found :(" << '\n';
	}

	else
	{
		std::cout << "\nThe number was found at position: " << NumberPositionInArray;
		std::cout << "\nThe Number found it's order: " << NumberPositionInArray + 1 << '\n';
	}


	return 0;
}