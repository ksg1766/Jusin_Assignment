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
	string iMenu[3] = { "�ݶ�", "���̴�", "ȯŸ" };
	int iPrices[3] = { 100, 200, 300 };
	cout << "������ �Է�: ";

	cin >> iBalance;

	SelectItem(iMenu, iPrices, iBalance);
}

int CheckInputRange(int iFloor, int iCeiling)
{
	int iInput;
	cin >> iInput;

	while (iInput < iFloor || iInput > iCeiling)
	{
		if (cin.fail())	// ���� �ʱ�ȭ
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n�߸��� �Է��Դϴ�. �ٽ� �����ϼ���: ";
		cin >> iInput;
	}
	return iInput;
}
void ShowMenu(string _menu[], int _prices[])
{
	cout << "---�޴�--- \n\n";
	for (int i = 0; i < sizeof(_menu) / sizeof(int); i++)
		cout << i + 1 << '.' << _menu[i] << ":  " << _prices[i] << " ��\n";
	cout << '\n';
}

void SelectItem(string _menu[], int _prices[], int _balance)
{
	while (true)
	{
		cout << "\n�ܾ�: " << _balance << " ��\n\n";
		MyFunc(_menu, _prices);
		cout << "���� �� ��ǰ�� ��ȣ�� �����ϼ���(��ȯ: 4): ";
		int selected = FUNC(1, 4);	// range check


		if (selected % 4)
		{
			if (_balance >= _prices[--selected])
			{
				_balance -= _prices[selected];
				cout << '\n' << _menu[selected] << " ���� �Ϸ�.\n";
			}
			else
				cout << "\n�ܾ��� �����մϴ�.\n";
		}
		else
		{
			cout << "\n�Ž������� " << _balance << " ���Դϴ�.\n\n";
			break;
		}

		cout << '\n';
		system("pause");
		system("cls");
	}
}