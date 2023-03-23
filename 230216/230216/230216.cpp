#include <iostream>
#include <ctime>
using namespace std;

enum RSP 
{
	가위,
	바위,
	보,
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
		cout << "무엇을 내시겠습니까?(가위: 1, 바위: 2, 보: 3)" << endl;
		cin >> iInput;
		while (iInput < 1 || iInput > 3)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			cout << "잘못된 값입니다. 다시 선택하세요.\n";
			cin >> iInput;
		}

		--iInput;
		iRand = rand() % 3;

		switch (iInput)
		{
		case 가위:
			cout << "\n나: 가위\n";
			break;
		case 바위:
			cout << "\n나: 바위\n";
			break;
		case 보:
			cout << "\n나: 보\n";
			break;
		}

		switch (iRand)
		{
		case 가위:
			cout << "상대: 가위\n";
			break;
		case 바위:
			cout << "상대: 바위\n";
			break;
		case 보:
			cout << "상대: 보\n";
			break;
		}

		int iResult = ((iInput + 3) - iRand) % 3;
		if (iResult == 1)
		{
			cout << "\n승리!\n\n";
			++iWin;
			continue;
		}
		else if (iResult == 2)
		{
			cout << "\n패배!\n\n";
			++iLose;
			continue;
		}
		else
		{
			cout << "\n무승부! 다시 선택하세요.\n\n";
			++iRound;
			continue;
		}
		system("pause");
		system("cls");
	}

	cout << '\n' << iWin << " 승  " << iLose << " 패\n";
}