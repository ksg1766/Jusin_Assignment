#include "230221.h"

void q2()
{
	srand(unsigned(time(NULL)));
	int iRound = 1;
	int iStrike = 0;
	int iBall = 0;
	int iDest[3];
	int iInput[3];
	int iTemp;
	cout << "��� :\t";

	for (int i = 0; i < 3; i++)
	{
		iTemp = rand() % 10;
		if (CheckByLinearSearch(iDest, 3, iTemp))
		{
			iDest[i] = iTemp;
			cout << iDest[i] << ' ';
		}
		else
			--i;
	}

	cout << '\n' << "-------------------------------" << '\n';
	while (iRound != 10)
	{
		cout << '\n' << iRound++ << " ȸ�� : ";
		for (int i = 0; i < 3; i++)
			cin >> iInput[i];

		for (int i = 0; i < sizeof(iDest) / sizeof(int); ++i)
		{
			if (iDest[i] == iInput[i])
			{
				++iStrike;
				if (iStrike == 3)
				{
					cout << "\n3 ��Ʈ����ũ\n\n�¸�!\n\n";
					return;
				}
			}
		}

		for (int i = 0; i < sizeof(iDest) / sizeof(int); ++i)
		{
			for (int j = 0; j < sizeof(iInput) / sizeof(int); ++j)
				if (iDest[i] == iInput[j] && i != j)
				{
					++iBall;
					continue;
				}
		}
		cout << '\n' << iStrike << " ��Ʈ����ũ\t" << iBall << " ��\n";
		iStrike = 0; iBall = 0;
	}
	cout << "\n�й�!";
}

bool CheckByLinearSearch(int* arr, const int _size, const int _input)
{
	for (int i = 0; i < _size; i++)
		if (arr[i] == _input)
			return false;
	return true;
}