#include "questions.h"

void question4()
{
	int iNumOfStars;
	cout << "º° °¹¼ö ÀÔ·Â: ";
	cin >> iNumOfStars;
	cout << '\n';
	for (int i = 0; i < iNumOfStars; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << '*';

		for (int j = 0; j < 2 * (iNumOfStars - i) - 1; j++)
			cout << ' ';

		for (int j = 0; j <= i; j++)
			cout << '*';

		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < iNumOfStars; i++)
	{
		for (int j = 0; j < iNumOfStars - i; j++)
			cout << '*';

		for (int j = 0; j <= 2 * i; j++)
			cout << ' ';

		for (int j = 0; j < iNumOfStars - i; j++)
			cout << '*';

		cout << '\n';
	}
	cout << '\n';
}