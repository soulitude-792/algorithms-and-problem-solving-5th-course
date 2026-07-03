#include<iostream>
#include<cstdlib>

void Swap(int& A, int& B)
{
	int Temp;
	Temp = A;
	A = B;       
	B = Temp;
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

void PrintArray(int Length, int arr[100])
{

	for (int i{ 0 }; i < Length; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

void ShuffleArray(int length, int arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		Swap(arr[RandomNumber(1, length) - 1], arr[RandomNumber(1, length) - 1]);
	}
}

void FillArrayFromOneToX(int arr[100], int X)
{
	for (int i{ 0 }; i < X; i++)
	{
		arr[i] = i + 1;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100];
	int length;


	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	FillArrayFromOneToX(arr1, length);
	
	std::cout << "Array 1 elements: ";
	PrintArray(length, arr1);

	ShuffleArray(length, arr1);

	std::cout << "Array 1 elements after shuffle: ";
	PrintArray(length, arr1);

	return 0;
}