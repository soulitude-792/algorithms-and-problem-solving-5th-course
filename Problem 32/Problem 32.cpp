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

void CopyReversedArray(int length, int arr1[100], int arr2[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		arr2[i] = arr1[length-1-i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100];
	int arr2[100];

	int length1{ ReadPositiveNumber("Enter the length of your array (max 100): ") };

	FillArrayWithRandomNumbers(arr1, length1);
	std::cout << "\nArray 1 elements: ";

	PrintArray(length1, arr1);

	CopyReversedArray(length1,arr1, arr2);

	std::cout << "\nArray elements after copying and reversing: ";
	PrintArray(length1, arr2);


	return 0;
}