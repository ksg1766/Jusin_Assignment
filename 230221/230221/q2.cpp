#include "230221.h"
#include <ctime>

void q2()
{
	ios_base::sync_with_stdio(false);
	cin >> fixed;
	cout << fixed;

	// ����2: �ζ� - �迭�� �� 45��¥�� ���� ������ (1~45) ���� 6���� �̾� �ζǸ� �ϼ�.
	// �� 5ȸ�� ���. �� ȸ������ �ߺ��� ���ڴ� ������ �� ����.
	// ���������� �̿��Ͽ� �������� ���ĵ� �غ���.

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
		cout << i + 1 << " ȸ�� : ";
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