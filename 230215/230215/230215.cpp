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
		cout << "문제의 번호를 입력하세요(문제: 1~4, 종료: 5): ";
		iQuestion = CheckInputRange(1, 5);	// range check
		if (iQuestion == 5)
			break;

		cout << '\n' << iQuestion << "번 문제\n\n\n";

		switch (iQuestion)
		{
		case 1:	// 문제 1
			question1();
			break;

		case 2:	// 문제 2
			question2();
			break;

		case 3:	// 문제 3
			question3();
			break;

		case 4:	// 문제 4
			question4();
			break;
		}
		system("pause");
		system("cls");
	}
}
