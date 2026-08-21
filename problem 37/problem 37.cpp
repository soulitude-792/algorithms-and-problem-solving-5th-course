#include <iostream>
#include <cstdlib>

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

int RandomNumber(int From, int To)
{
	int RandomNumber{ rand() % (To - From + 1) + From };

	return RandomNumber;
}

void AddArrayNumber(int element, int arr2[100], int& length)
{
	length++;
	arr2[length - 1] = element;
}

void CopyArrayUsingAddArrayNumber(int arr1[100], int arr2[100], int arrlen1, int &arrlen2)
{
	for (int i = 0; i < arrlen1; i++)
	{
		AddArrayNumber(arr1[i], arr2, arrlen2);
	}
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

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100], arr2[100];

	int arrlength1 = 0;
	int arrLength2 = 0;

	arrlength1 = ReadPositiveNumber("Enter the length of the array: ");

	FillArrayWithRandomNumbers(arr1, arrlength1);

	CopyArrayUsingAddArrayNumber(arr1, arr2, arrlength1, arrLength2);

	std::cout << "\nArray 1 elements: ";
	PrintArray(arrlength1, arr1);

	std::cout << "Array 2 elements: ";
	PrintArray(arrlength1, arr2);

	return 0;

}
