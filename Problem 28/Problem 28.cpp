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

void CopyArray(int length ,int arr1[100],int arr2[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		arr2[i] = arr1[i];
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

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100];
	int length;
	int arr2[100];

	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	FillArrayWithRandomNumbers(arr1, length);

	CopyArray(length, arr1, arr2);

	std::cout << "Array 1 elements: ";
	PrintArray(length, arr1);

	std::cout << "\nArray 2 elements: ";
	PrintArray(length, arr2);


	return 0;
}