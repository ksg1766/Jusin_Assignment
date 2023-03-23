#include "questions.h"

void main()
{
#pragma region
	ios::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;
#pragma endregion
	while (true)
	{
		int iQuestion;
		cout << "������ ��ȣ�� �Է��ϼ���(����: 1~4, ����: 5): ";
		iQuestion = CheckInputRange(1, 5);	// range check
		if (iQuestion == 5)
			break;

		cout << '\n' << iQuestion << "�� ����\n\n\n";

		switch (iQuestion)
		{
		case 1:	// ���� 1
			question1();
			break;

		case 2:	// ���� 2
			question2();
			break;

		case 3:	// ���� 3
			question3();
			break;

		case 4:	// ���� 4
			question4();
			break;
		}
		system("pause");
		system("cls");
	}
}
