#include "230221.h"

void q1()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// ����
	//1~25���� 2�� for�� & �迭�� �̿��Ͽ� 5*5 ���·� ���
	int iArray[25] = {};
	for (int i = 0; i < 25; i++)
		iArray[i] = i + 1;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << iArray[5 * i + j] << '\t';
		}
		cout << '\n';
	}
}