#include "230221.h"

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
	// 숙제 1:
	// 2차원 배열을 90도 시계 방향으로 회전(4회전)

	// 숙제 2:
	// 야구게임 만들기
	// 1~9 사이의 숫자 중 무작위 3개 추출(정렬x)
	// 숫자를 총 3개 입력하여 앞서 추출한 숫자와 비교하여 스트라이크와 볼을 만듭니다.
	/*
	결과 :	8 1 7
	-------------------------------
	1회차	1 2 3	1볼
	2회차	8 2 3	1스트라이크
	3회차	8 7 1	1스트라이크 2볼
	*/
	// 0 0 7
	// 1 0 0
	//9회차가 지나도록 3스트라이크 완성하면 승리, 완성하지 못할 경우 패배
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