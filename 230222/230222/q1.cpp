#include "230221.h"

void q1()
{
	int iRow, iCol;
	cout << "행과 열을 입력하세요 : ";
	cin >> iRow >> iCol;

	srand(unsigned(time(NULL)));

	int iArr2D[50][50] = { 0 };
	//vector<int> iVec2D;
	for (int i = 0; i < iRow; i++)
		for (int j = 0; j < iCol; j++)
			iArr2D[i][j] = rand() % 9 + 1;

	int iMax = max(iRow, iCol);
	for (int i = 0; i < iMax; i++)
	{
		if (!iArr2D[i][0])
			continue;
		for (int j = 0; j < iMax; j++)
			if (iArr2D[i][j])
				cout << iArr2D[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';

	Rotate90(iArr2D, &iRow, &iCol);
	Rotate90(iArr2D, &iRow, &iCol);
	Rotate90(iArr2D, &iRow, &iCol);
	Rotate90(iArr2D, &iRow, &iCol);
}

void Rotate90(int arr[][50], int* _row, int* _col)
{
	int tempArr[50][50] = { 0 };
	int iMax = max(*_row, *_col);
	for (int i = 0; i < iMax; i++)
		for (int j = 0; j < iMax; j++)
			//tempArr[iMax - 1 - j][i] = arr[i][j];	// 반시계
			tempArr[i][j] = arr[iMax - 1 - j][i];	// 시계

	int temp = *_row;
	*_row = *_col;
	*_col = temp;

	for (int i = 0; i < iMax; i++)
		for (int j = 0; j < iMax; j++)
			arr[i][j] = tempArr[i][j];

	for (int i = 0; i < iMax; i++)
	{
		for (int j = 0; j < iMax; j++)
			if (arr[i][j])
				cout << arr[i][j] << ' ';
		cout << '\n';
	}
	cout << '\n';
}