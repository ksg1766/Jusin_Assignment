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
		cout << "������ ��ȣ�� �Է��ϼ��� : ";
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
	// ���� 1:
	// 2���� �迭�� 90�� �ð� �������� ȸ��(4ȸ��)

	// ���� 2:
	// �߱����� �����
	// 1~9 ������ ���� �� ������ 3�� ����(����x)
	// ���ڸ� �� 3�� �Է��Ͽ� �ռ� ������ ���ڿ� ���Ͽ� ��Ʈ����ũ�� ���� ����ϴ�.
	/*
	��� :	8 1 7
	-------------------------------
	1ȸ��	1 2 3	1��
	2ȸ��	8 2 3	1��Ʈ����ũ
	3ȸ��	8 7 1	1��Ʈ����ũ 2��
	*/
	// 0 0 7
	// 1 0 0
	//9ȸ���� �������� 3��Ʈ����ũ �ϼ��ϸ� �¸�, �ϼ����� ���� ��� �й�
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