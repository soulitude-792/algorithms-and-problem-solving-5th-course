#include<iostream>
#include<cstdlib>

void AddArrayNumber(int Number, int arr[100], int& length)
{
	length++;
	arr[length - 1] = Number;
}

int ReadNumber()
{
	int Number;

	std::cout << "Enter a number: ";
	std::cin >> Number;

	return Number;
}
void GetUserInput(int arr[100], int &length)
{
	bool AddMore{ true };

	do
	{
		AddArrayNumber(ReadNumber(), arr, length);

		std::cout << "Do you want to add another Number? [0] No, [1] Yes: ";
		std::cin >> AddMore;

	} while (AddMore);

}

void PrintArray(int Length, int arr[100])
{
	for (int i{ 0 }; i < Length; i++)
	{
		std::cout << arr[i] << " ";
	}
}


int main()
{
	int arr[100];
	int length{0};

	GetUserInput(arr, length);

	std::cout << "\nArray length: " << length << '\n';
	std::cout << "Array elements: ";

	PrintArray(length, arr);

	return 0;
}