#include "questions.h"
#include <ctime>

void question3()
{
	int round = 3;
	int iWin(0), iLose(0);
	while (round--)
	{
		srand(unsigned(time(NULL)));

		int iRandom = rand() % 10;
		int iInput;

		cout << "---" << 3 - round << " ����---\n\n" << "Ȧ��? ¦��? (Ȧ��: 1 �Է�,  ¦��: 2 �Է�): ";

		iInput = CheckInputRange(1, 2);	// range check

		if (((iRandom + iInput) % 2))	// ���� ����ٸ� ���� ������ ¦��, Ʋ�ȴٸ� Ȧ������ �̿�
		{
			cout << "\n��!!!!!\nrand = " << iRandom << "\n\n\n";
			++iLose;
		}
		else
		{
			cout << "\n����!!!!!\nrand = " << iRandom << "\n\n\n";
			++iWin;
		}
	}
	cout << "��: " << iWin << "\t��: " << iLose << '\n';
}