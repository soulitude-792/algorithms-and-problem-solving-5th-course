#include <iostream>

void PrintArray(int Length, int arr[100])
{

	for (int i{ 0 }; i < Length / 2; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

void FillArray(int arr[100], int &arrLength)
{
	arrLength = 6;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 1;
	arr[4] = 20;
	arr[5] = 10;
}

bool IsPalindromeArray(int arr[100], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (arr[i] != arr[Length - 1 - i])
			return false;
	}
	return true;
}

int main()
{
	int arr[100];
	int arrlen = 0;

	FillArray(arr, arrlen);

	std::cout << "Array elements : ";
	PrintArray(arrlen, arr);

	if (IsPalindromeArray(arr, arrlen))
	{
		std::cout << "\nThe array entered is a palindrome.\n";
	}
	else
		std::cout << "\nThe array you entered is not a palidrome.\n";
	
	return 0;
}

/*the main purpose of the program is to check weather an array follows the palindrome rule
first we hardcoded the numbers in the array, and we then print the original array, then an if statement
follows, that checks if the array is palindrome and prints the correct message accordingly.
it needs a function called IsPalindromeArray, the function is of bool return type and it checks the first 
and last element of the array to see if they match, then it moves on to element 2 and the element that is
before the last one, then it goes on and if it finds ones that don't match it return false. if everything
matches it returns true.*/
