#include "questions.h"

void question2()
{
	int iBalance;
	string iMenu[3] = { "�ݶ�", "���̴�", "ȯŸ" };
	int iPrices[3] = { 100, 200, 300 };
	cout << "������ �Է�: ";

	cin >> iBalance;

	while (true)
	{
		cout << "\n�ܾ�: " << iBalance << " ��\n\n";
		cout << "---�޴�--- \n\n";
		for (int i = 0; i < sizeof(iMenu) / sizeof(string); i++)
			cout << i + 1 << '.' << iMenu[i] << ":  " << iPrices[i] << " ��\n";
		cout << '\n';

		int selected;

		cout << "���� �� ��ǰ�� ��ȣ�� �����ϼ���(��ȯ: 4): ";
		selected = CheckInputRange(1, 4);	// range check

		int iIndex = selected - 1;

		if (selected == 4)
		{
			cout << "\n�Ž������� " << iBalance << " ���Դϴ�.\n\n";
			break;
		}

		int iTemp = iBalance - iPrices[iIndex];
		if (iTemp >= 0)
		{
			iBalance = iTemp;
			cout << '\n' << iMenu[iIndex] << " ���� �Ϸ�.\n";
		}
		else
			cout << "\n�ܾ��� �����մϴ�.\n";

		cout << '\n';
		system("pause");
		system("cls");
	}
}