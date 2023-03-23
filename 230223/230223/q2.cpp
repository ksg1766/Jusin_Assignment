#include "230223.h"

void q2()
{
// 숙제 2.
// 숫자 이동시키기
// 0~24에 해당하는 숫자 25개를 5*5형식으로 출력
// 숫자를 입력받으면 넘버패드 해당하는 숫자의 방향대로 숫자 0이 이동을 한다. (2. 아래 4. 왼 6.오 8 위)
// 이동방향 맨 끝에서는 더 이상 이동할 수 없도록 예외처리를 하라
// 0	1	2			1	0	2
// 3	4	5	6입력	3	4	5
// 6	7	8			6	7	8
//
	int iSize = 5;
	int iBoard[5][5] = {};
	int iPos = 0;

	char cInput;

	for (int i = 0; i < iSize; i++)
		for (int j = 0; j < iSize; j++)
			iBoard[i][j] = i * iSize + j;

	while (true)
	{
		ShowBoard(iBoard, iSize);
		cout << "\n입력(w, a, s, d): ";
		cin >> cInput;
		Move(iBoard, iSize, iPos, cInput);
		Sleep(1000);
		system("cls");
		iPos = GetPos(iBoard, iSize);
	}
}

int GetPos(int _board[][5], int _size)
{
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			if (!_board[i][j])
				return i * _size + j;
}

void Move(int _board[][5], int _size, int _loc, char _input)
{
	int _row = _loc / _size;
	int _col = _loc % _size;

	if (_input == 'w')
		if (_row)
			Swap(&_board[_row][_col], &_board[_row - 1][_col]);
		else
			cout << "이동이 불가능 합니다.\n";
	else if (_input == 'a')
		if (_col)
			Swap(&_board[_row][_col], &_board[_row][_col - 1]);
		else
			cout << "이동이 불가능 합니다.\n";
	else if (_input == 's')
		if (_row != _size - 1)
			Swap(&_board[_row][_col], &_board[_row + 1][_col]);
		else
			cout << "이동이 불가능 합니다.\n";
	else if (_input == 'd')
		if (_col != _size - 1)
			Swap(&_board[_row][_col], &_board[_row][_col + 1]);
		else
			cout << "이동이 불가능 합니다.\n";
}

void Swap(int* _left, int* _right)
{
	int temp = *_left;
	*_left = *_right;
	*_right = temp;
}

void ShowBoard(int _board[][5], int _size)
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
			cout << _board[i][j] << '\t';
		cout << '\n';
	}
}