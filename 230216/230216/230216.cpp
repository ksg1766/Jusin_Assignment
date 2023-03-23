#include <iostream>
#include <ctime>
using namespace std;

enum RSP 
{
	����,
	����,
	��,
};

void main()
{
	ios::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	int iInput, iRand;

	int iRound(3), iWin(0), iLose(0);
	srand(unsigned(time(NULL)));
	while (iRound--)
	{
		cout << "������ ���ðڽ��ϱ�?(����: 1, ����: 2, ��: 3)" << endl;
		cin >> iInput;
		while (iInput < 1 || iInput > 3)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			cout << "�߸��� ���Դϴ�. �ٽ� �����ϼ���.\n";
			cin >> iInput;
		}

		--iInput;
		iRand = rand() % 3;

		switch (iInput)
		{
		case ����:
			cout << "\n��: ����\n";
			break;
		case ����:
			cout << "\n��: ����\n";
			break;
		case ��:
			cout << "\n��: ��\n";
			break;
		}

		switch (iRand)
		{
		case ����:
			cout << "���: ����\n";
			break;
		case ����:
			cout << "���: ����\n";
			break;
		case ��:
			cout << "���: ��\n";
			break;
		}

		int iResult = ((iInput + 3) - iRand) % 3;
		if (iResult == 1)
		{
			cout << "\n�¸�!\n\n";
			++iWin;
			continue;
		}
		else if (iResult == 2)
		{
			cout << "\n�й�!\n\n";
			++iLose;
			continue;
		}
		else
		{
			cout << "\n���º�! �ٽ� �����ϼ���.\n\n";
			++iRound;
			continue;
		}
		system("pause");
		system("cls");
	}

	cout << '\n' << iWin << " ��  " << iLose << " ��\n";
}