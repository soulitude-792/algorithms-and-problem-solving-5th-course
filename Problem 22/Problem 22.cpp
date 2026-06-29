#include<iostream>
#include<string>

int ReadPositiveNumber(std::string Message)
{
	int Num;
	do
	{
		std::cout << Message;
		std::cin >> Num;
	} while (Num <= 0);

	return Num;
}

void ArrayLength(int &Length, int arr[100])
{
	Length = ReadPositiveNumber("Enter the length of the array: ");

	for (int i = 0; i < Length; i++)
	{
		std::cout << "Element [" << i + 1 << "]: ";
		std::cin >> arr[i];

		
	}
	std::cout << '\n';
	
}

void PrintArray(int Length, int arr[100])
{
	for (int i{ 0 }; i < Length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int CheckNumberRecurrsion(int NumbertoCheck, int arr[100], int length)
{
	int Counter{0};

	for (int i = 0; i < length; i++)
	{
		if (NumbertoCheck == arr[i])
		{
			Counter++;
		}
	}

	return Counter;
}

int main()
{
	int arr[100];
	int length{};
	int NumbertoCheck{};

	ArrayLength(length,arr);

	std::cout << "\nOriginal Array: ";
	PrintArray(length, arr);

	NumbertoCheck = ReadPositiveNumber("\nEnter the Number you want to check: ");
	std::cout<<"\nThe number "<<NumbertoCheck<<" has appeared "<<CheckNumberRecurrsion(NumbertoCheck, arr, length)<<" time/s.";


	return 0;
}