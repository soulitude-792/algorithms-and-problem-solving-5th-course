#include<iostream>
#include<cstdlib>

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
		arr[i] = i + 1;

		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}


int main()
{

	int arr1[100];
	int length;


	length = ReadPositiveNumber("Enter the length of the array (100 max): ");

	std::cout << "Array 1 elements: ";
	PrintArray(length, arr1);


	return 0;
}