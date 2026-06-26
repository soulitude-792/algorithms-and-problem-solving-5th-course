#include <iostream>
#include<cstdlib>

//Random number function but from X to Y

int RandomNumber(int From, int To)
{
	int RandomNumber{rand() % (To - From + 1) + From};
	
	return RandomNumber;
}

int main()
{
	srand((unsigned)time(NULL));

	std::cout << "A random number from 1 to 100: " << RandomNumber(1, 100) << '\n';

	return 0;
}