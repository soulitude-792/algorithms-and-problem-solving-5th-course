#include<iostream>
#include<cstdlib>

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

void FillArrayWithRandomNumbers(int length, int arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
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

bool IsTheNumberInArray(int length, int arr[100], int Number)
{
	return (CheckNumberPositionInArray(Number, length, arr) !=-1);
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

	length = ReadPositiveNumber("Enter the amount of numbers you want to generate(100 max): ");

	FillArrayWithRandomNumbers(length, arr);

	std::cout << "\nArray elements: ";
	PrintArray(length, arr);

	NumbertoCheck = ReadPositiveNumber("\n\nEnter the number you want to check: ");

	std::cout << "\n\nThe number you are looking for is: " << NumbertoCheck;

	if (IsTheNumberInArray(length, arr, NumbertoCheck) == true)
	{
		std::cout << "\nThe number is found :)\n";
	}
	else
	{
		std::cout << "\nThe number is not found :(\n";
	}
	
	return 0;
}