#include "questions.h"
#include <ctime>

void question3()
{
	int round = 3;
	int iWin(0), iLose(0);
	while (round--)
	{
		srand(unsigned(time(NULL)));

		int iRandom = rand() % 10;
		int iInput;

		cout << "---" << 3 - round << " ¶ó¿îµå---\n\n" << "È¦¼ö? Â¦¼ö? (È¦¼ö: 1 ÀÔ·Â,  Â¦¼ö: 2 ÀÔ·Â): ";

		iInput = CheckInputRange(1, 2);	// range check

		if (((iRandom + iInput) % 2))	// ´äÀ» ¸ÂÃè´Ù¸é ÇÕÀº ¹«Á¶°Ç Â¦¼ö, Æ²·È´Ù¸é È¦¼öÀÓÀ» ÀÌ¿ë
		{
			cout << "\n¶¯!!!!!\nrand = " << iRandom << "\n\n\n";
			++iLose;
		}
		else
		{
			cout << "\nÁ¤´ä!!!!!\nrand = " << iRandom << "\n\n\n";
			++iWin;
		}
	}
	cout << "½Â: " << iWin << "\tÆÐ: " << iLose << '\n';
}