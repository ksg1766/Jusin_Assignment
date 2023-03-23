#include "230223.h"

int CheckInputRange(int iFloor, int iCeiling);

void main()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	int iSelectQ = 1;
	while (true)
	{
		cout << "문제의 번호를 입력하세요 : ";
		int iSelectQ = CheckInputRange(1, 2); cout << '\n';

		switch (iSelectQ)
		{
		case 1:
			q1();
			break;
		case 2:
			q2();
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

int CheckInputRange(int iFloor, int iCeiling)
{
	int iInput;
	cin >> iInput;

	while (iInput < iFloor || iInput > iCeiling)
	{
		if (cin.fail())	// 버퍼 초기화
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n잘못된 입력입니다. 다시 선택하세요: ";
		cin >> iInput;
	}
	return iInput;
}