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

void FillArrayWithRandomNumbers(int arr[100], int length)
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
	std::cout << '\n';
}

int FindMinNumberinArray(int arr[100], int length)
{
	int MinNumber{ arr[0] };

	for (int i{ 0 }; i < length; i++)
	{
		if (arr[i] < MinNumber)
		{
			MinNumber = arr[i];
		}
	}

	return MinNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int length;
	int MinNumberinArray;

	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	FillArrayWithRandomNumbers(arr, length);


	std::cout << "Array elements: ";
	PrintArray(length, arr);

	MinNumberinArray = FindMinNumberinArray(arr, length);
	std::cout << "\nThe smallest number in your array is: " << MinNumberinArray << '\n';


	return 0;
}
