#include "questions.h"

void question1()
{
	srand(unsigned(time(NULL)));

	int iRandom = rand();
	int iNum = 2;

	while (iNum != 10)
	{
		cout << iNum << "´Ü: " << '\n';
		int iMul = 1;
		while (iMul != 10)
		{
			cout << iNum << " * " << iMul << " = " << iNum * iMul << '\n';
			iMul++;
		}
		iNum++;
		cout << '\n';
	}
}