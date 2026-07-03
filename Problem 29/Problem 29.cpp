#include<iostream>
#include<cstdlib>

enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

enPrimNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2; Counter <= M; Counter++)
	{
		if (Number % Counter == 0)
			return enPrimNotPrime::NotPrime;
	}

	return enPrimNotPrime::Prime;
}

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

void CopyArray(int length, int arr1[100], int arr2[100])
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

void CopyPrimeNumbers(int arr1[100], int length1, int arr2[200], int &length2)
{
	int Counter{ 0 };

	for (int i{ 0 }; i < length1; i++)
	{
		if (CheckPrime(arr1[i]) == enPrimNotPrime::Prime)
		{
			arr2[Counter] = arr1[i];

				Counter++;
		}
	}
	length2 = --Counter;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr1[100];
	int length;
	int arr2[100];
	int length2;

	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	FillArrayWithRandomNumbers(arr1, length);

	CopyArray(length, arr1, arr2);

	std::cout << "Array 1 elements: ";
	PrintArray(length, arr1);

	CopyPrimeNumbers(arr1, length, arr2 , length2);

	std::cout << "\nThe Prime Numbers in Array 2: ";
	PrintArray(length2, arr2);

	return 0;
}