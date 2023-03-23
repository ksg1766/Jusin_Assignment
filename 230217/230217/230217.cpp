#include <iostream>
using namespace std;

int CheckInputRange(int iFloor, int iCeiling);
void ShowMenu(string _menu, int _prices);
void SelectItem(string _menu[], int _prices[], int _balance);

typedef int(*FUNC)(int, int);
FUNC = &CheckInputRange;
int (*MyFunc)(string, int);

void main()
{
	ios::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
			cout << i << " * " << j << " = " << a * b << '\n';
		cout << '\n';
	}

	int iBalance;
	string iMenu[3] = { "콜라", "사이다", "환타" };
	int iPrices[3] = { 100, 200, 300 };
	cout << "소지금 입력: ";

	cin >> iBalance;

	SelectItem(iMenu, iPrices, iBalance);
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
void ShowMenu(string _menu[], int _prices[])
{
	cout << "---메뉴--- \n\n";
	for (int i = 0; i < sizeof(_menu) / sizeof(int); i++)
		cout << i + 1 << '.' << _menu[i] << ":  " << _prices[i] << " 원\n";
	cout << '\n';
}

void SelectItem(string _menu[], int _prices[], int _balance)
{
	while (true)
	{
		cout << "\n잔액: " << _balance << " 원\n\n";
		MyFunc(_menu, _prices);
		cout << "구매 할 상품의 번호를 선택하세요(반환: 4): ";
		int selected = FUNC(1, 4);	// range check


		if (selected % 4)
		{
			if (_balance >= _prices[--selected])
			{
				_balance -= _prices[selected];
				cout << '\n' << _menu[selected] << " 구매 완료.\n";
			}
			else
				cout << "\n잔액이 부족합니다.\n";
		}
		else
		{
			cout << "\n거스름돈은 " << _balance << " 원입니다.\n\n";
			break;
		}

		cout << '\n';
		system("pause");
		system("cls");
	}
}