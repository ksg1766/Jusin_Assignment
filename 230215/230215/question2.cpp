#include "questions.h"

void question2()
{
	int iBalance;
	string iMenu[3] = { "콜라", "사이다", "환타" };
	int iPrices[3] = { 100, 200, 300 };
	cout << "소지금 입력: ";

	cin >> iBalance;

	while (true)
	{
		cout << "\n잔액: " << iBalance << " 원\n\n";
		cout << "---메뉴--- \n\n";
		for (int i = 0; i < sizeof(iMenu) / sizeof(string); i++)
			cout << i + 1 << '.' << iMenu[i] << ":  " << iPrices[i] << " 원\n";
		cout << '\n';

		int selected;

		cout << "구매 할 상품의 번호를 선택하세요(반환: 4): ";
		selected = CheckInputRange(1, 4);	// range check

		int iIndex = selected - 1;

		if (selected == 4)
		{
			cout << "\n거스름돈은 " << iBalance << " 원입니다.\n\n";
			break;
		}

		int iTemp = iBalance - iPrices[iIndex];
		if (iTemp >= 0)
		{
			iBalance = iTemp;
			cout << '\n' << iMenu[iIndex] << " 구매 완료.\n";
		}
		else
			cout << "\n잔액이 부족합니다.\n";

		cout << '\n';
		system("pause");
		system("cls");
	}
}