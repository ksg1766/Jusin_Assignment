#include "230221.h"
#include <ctime>

void q2()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// 숙제2: 로또 - 배열을 총 45개짜리 만들어서 무작위 (1~45) 숫자 6개를 뽑아 로또를 완성.
	// 총 5회차 출력. 한 회차에서 중복된 숫자는 존재할 수 없다.
	// 버블정렬을 이용하여 오름차순 정렬도 해보자.

	srand(unsigned(time(NULL)));

	int iNumbers[45] = {};
	int iLottery[5][6] = {};

	for (int i = 0; i < 45; i++)
		iNumbers[i] = i + 1;

	int iRand;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			iRand = rand() % 45;
			if (CheckByLinearSearch(iLottery[i], 6, iRand + 1))
				iLottery[i][j] = iNumbers[iRand];
			else
				--j;
		}
		BubbleSort(iLottery[i], 6);
	}

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " 회차 : ";
		for (int j = 0; j < 6; j++)
			cout << iLottery[i][j] << '\t';
		cout << '\n';
	}
}

bool CheckByLinearSearch(int* arr, const int _size, const int _input)
{
	for (int i = 0; i < _size; i++)
		if (arr[i] == _input)
			return false;
	return true;
}

void BubbleSort(int* arr, const int _size)
{
	for (int i = 0; i < _size - 1; i++)
		for (int j = 0; j < _size - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
}

void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}