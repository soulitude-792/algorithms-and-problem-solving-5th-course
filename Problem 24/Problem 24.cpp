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

int FindMaxNumberinArray(int arr[100], int length)
{
	int MaxNumber{ 0 };

	for (int i{ 0 }; i < length; i++)
	{
		if (arr[i] > MaxNumber)
		{
			MaxNumber = arr[i];
		}
	}

	return MaxNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int length;
	int MaxNumberinArray;

	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	FillArrayWithRandomNumbers(arr, length);


	std::cout << "Array elements: ";
	PrintArray(length, arr);

	MaxNumberinArray = FindMaxNumberinArray(arr, length);
	std::cout << "\nThe biggest number in your array is: " << MaxNumberinArray << '\n';


	return 0;
}
