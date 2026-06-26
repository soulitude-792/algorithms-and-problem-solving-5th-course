#include <iostream>
#include <cstdlib>

//Generate randoms from Small letters, captital letters, special characters and digits.

enum enCharType{SmallLetter = 1, CapitalLetters = 2, SpecialCharacters, Digits};

int RandomNumber(int From, int To)
{
	int RandomNumber{ rand() % (To - From + 1) + From };

	return RandomNumber;
}

char GetRandom(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:

		return char(RandomNumber(97, 122));

		break;

	case enCharType::CapitalLetters:

		return char(RandomNumber(65, 90));

		break;

	case enCharType::SpecialCharacters:

		return char(RandomNumber(33, 47));

		break;

	case enCharType::Digits:
		
		return char(RandomNumber(48, 57));

	}

}

int main()
{
	srand((unsigned)time(NULL));

	std::cout << "Random small letter: " << GetRandom(enCharType::SmallLetter) << '\n';
	std::cout << "Random capital letter: " << GetRandom(enCharType::CapitalLetters) << '\n';
	std::cout << "Random special character: " << GetRandom(enCharType::SpecialCharacters) << '\n';
	std::cout << "Random digit: " << GetRandom(enCharType::Digits) << '\n';

	return 0;
}