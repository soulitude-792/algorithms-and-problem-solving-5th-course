#include <iostream>
#include <cstdlib>

int ReadNumber()
{
	int Num;
	std::cout << "enter a number: ";
	std::cin >> Num;

	return Num;
}

void FillElementsInArray(int Num, int arr[100], int &ArrLength)
{
	ArrLength++;
	arr[ArrLength - 1] = Num;
}

void PrintArray(int Length, int arr[100])
{
	for (int i{ 0 }; i < Length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void GetUserInputInArray(int arr[100], int &ArrLength)
{
	bool AddNumber = true;
	do
	{
		FillElementsInArray(ReadNumber(), arr, ArrLength);
		std::cout << "Do you want to add an element to this array? [0]: No [1]: Yes: ";
		std::cin >> AddNumber;
	} while (AddNumber == true);
}
int main()
{
	int Arr[100];
	int ArrLength = 0;

	GetUserInputInArray(Arr, ArrLength);

	std::cout << "\nArray length: " << ArrLength;

	std::cout << "\nArray Elements: ";
	PrintArray(ArrLength, Arr);

	return 0;
}