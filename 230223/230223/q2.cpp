#include "230223.h"

void q2()
{
// ���� 2.
// ���� �̵���Ű��
// 0~24�� �ش��ϴ� ���� 25���� 5*5�������� ���
// ���ڸ� �Է¹����� �ѹ��е� �ش��ϴ� ������ ������ ���� 0�� �̵��� �Ѵ�. (2. �Ʒ� 4. �� 6.�� 8 ��)
// �̵����� �� �������� �� �̻� �̵��� �� ������ ����ó���� �϶�
// 0	1	2			1	0	2
// 3	4	5	6�Է�	3	4	5
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
		cout << "\n�Է�(w, a, s, d): ";
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
			cout << "�̵��� �Ұ��� �մϴ�.\n";
	else if (_input == 'a')
		if (_col)
			Swap(&_board[_row][_col], &_board[_row][_col - 1]);
		else
			cout << "�̵��� �Ұ��� �մϴ�.\n";
	else if (_input == 's')
		if (_row != _size - 1)
			Swap(&_board[_row][_col], &_board[_row + 1][_col]);
		else
			cout << "�̵��� �Ұ��� �մϴ�.\n";
	else if (_input == 'd')
		if (_col != _size - 1)
			Swap(&_board[_row][_col], &_board[_row][_col + 1]);
		else
			cout << "�̵��� �Ұ��� �մϴ�.\n";
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