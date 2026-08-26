#include<iostream>
#include<cstdlib>

int RandomNumber(int From, int To)
{
	int RandomNumber{ rand() % (To - From + 1) + From };

	return RandomNumber;
}

void FillArrayWithRandomNumbers(int arr[100], int& length)
{
	std::cout << "Enter the number of elements: ";
	std::cin >> length;

	for (int i{ 0 }; i < length; i++)
	{
		arr[i] = RandomNumber(-100, 100);
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

int  NegativeNumberCountInArray(int arr[100], int arrlen)
{
	int NegativeNumberCount = 0;

	for (int i = 0; i < arrlen; i++)
	{
		if (arr[i] < 0)
		{
			NegativeNumberCount++;
		}
	}
	return NegativeNumberCount;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int length = 0;

	FillArrayWithRandomNumbers(arr, length);

	std::cout << "\nArray elements: ";
	PrintArray(length, arr);

	std::cout << "Negative number count is: " << NegativeNumberCountInArray(arr, length) << '\n';

	return 0;
}

/*the purpose of the program is to fill the array with random numbers and then count only the Negative
numbers in the array and return the number of the count. it does this by filling the array with random
numbers first using FillArrayWithRandomNumbers and then it sends that array with the length to a function
called NegativeNumberCountInArray. then it checks every element if it's Postive or Negative, if it's Negative
it adds 1 to the counter and loops until the end*/