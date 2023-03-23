#include "230221.h"

void q1()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// 숙제
	//1~25까지 2중 for문 & 배열을 이용하여 5*5 형태로 출력
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