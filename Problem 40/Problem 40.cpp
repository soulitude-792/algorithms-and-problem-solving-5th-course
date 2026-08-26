#include <iostream>
#include <cstdlib>

void FillArray(int arr[100], int &arrLength)
{
	arrLength = 10;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}

int CheckNumberPositionInArray(int NumberToSearchFor, int length, int arr[100])
{
	for (int i{ 0 }; i < length; i++)
	{
		if (arr[i] == NumberToSearchFor)
		{
			return i;
		}
	}
	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrlength)
{
	if (!(CheckNumberPositionInArray(Number, arrlength, arr) == -1))
		return 1;
	else
		return 0;
}

void AddArrayNumber(int element, int arr2[100], int& length)
{
	length++;
	arr2[length - 1] = element;
}

void CopyDistinctNumbersToArray(int arr1[100], int arr2[100], int arr1len, int& arr2len)
{
	for (int i = 0; i < arr1len; i++)
	{
		if (!IsNumberInArray(arr1[i], arr2, arr2len))
		{
			AddArrayNumber(arr1[i], arr2, arr2len);
		}
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

	int arr1[100], arr2[100];

	int arrlength1 = 0;
	int arrLength2 = 0;

	FillArray(arr1, arrlength1);

	CopyDistinctNumbersToArray(arr1, arr2, arrlength1, arrLength2);

	std::cout << "\nArray 1 elements: ";
	PrintArray(arrlength1, arr1);

	std::cout << "Array distinct elements: ";
	PrintArray(arrLength2, arr2);

	return 0;

}

/*The idea of the program is to search the source array which is hard coded, and filter out any 
elements that are duplicates, and print only the distinct elements after you put them in second array.
to do this first we have to fill the array in a seperate function called FillArray.
secondly we use the function CopyDistinctNumbersToArray to check every elemet in the source array
and copy the distinct array arr2. arrlen2 is passed by reference because it starts at 0 and we
change the length after we know how many distinct elements we have. if we have 2 distinct elements, we
pass 2 back to int main and it updates the value from 0 to 2. anyway, a function we use inside
said function is IsNumberInArray, the function is a bool return type and takes in the number we want to 
check, it being the iteration of arr1[i] in the for loop, and sees if it is in the array, if it isn't 
it gets passed to another function called AddArrayNumber which takes that number, and adds it to the second
array that is only for the distinct elements. the way IsNumberInArray works is it takes in that number
we want to check,passes it to an function called CheckNumberPositionInArray the original array and it's 
length and checks via for loop for every element in the original array if that number is there or not
if it is there it return the number index position if not it returns -1. if it is there, say number 50
is found at index 3, then 3 != -1 is true and it confirms the exitence in the array*/
