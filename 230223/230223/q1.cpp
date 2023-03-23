#include "230223.h"
#include <ctime>

void q1()
{
	// ���� 1.
	// 5 * 5 �迭�� ����� �������
	// 1~25�� ���� 25���� 5*5�������� ���
	// ���� �Է� �޾Ƽ� ��ġ�ϴ� ���ڴ� *�� ���
	// ���� || ���� || �밢�� �� 5���� ��� ���� ++1
	// 5���� �Ǹ� �¸� & ����
	// �����ϴٸ� ���� �������ε� ����� ����

	srand(unsigned(time(NULL)));
	string szPlayers[2] = { "��ǻ��", "�÷��̾�" };
	int iBoard[10][10] = {};
	int iSize = 10;
	int iBingoCount = 0;
	bool isMyTurn = false;

	for (int i = 0; i < iSize; i++)
		for (int j = 0; j < iSize; j++)
			iBoard[i][j] = i * iSize + j + 1;

	while (iBingoCount < 5)
	{
		ShowBoard(iBoard, iSize, iBingoCount);
		SelectOne(iBoard, iSize, isMyTurn);
		CountBingo(iBoard, iSize, iBingoCount);
		system("cls");
	}
	ShowBoard(iBoard, iSize, iBingoCount);
	cout << '\n' << szPlayers[isMyTurn] << " �¸�!\n";
}

void ShowBoard(int _board[][10], int _size, int& _count)
{
	cout << "�ϼ��� ������ ��: " << _count << "\n\n";
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (!_board[i][j])
				cout << '*' << '\t';
			else
				cout << _board[i][j] << '\t';
		}
		cout << "\n\n";
	}
}

void SelectOne(int _board[][10], int _size, bool& _isMyTurn)
{
	int iInput = 0;
	_isMyTurn = !_isMyTurn;

	if (_isMyTurn)
	{
		cout << "\n�÷��̾��� ���� �Դϴ�: ";
		cin >> iInput;
	}
	else
	{
		cout << "\n��ǻ���� �����Դϴ�: ";
		while (!iInput || !_board[iInput / _size][iInput % _size - 1])
			iInput = rand() % (_size*_size) + 1;
		cout << iInput << '\n';
		Sleep(1000);
	}

	_board[iInput / _size][iInput % _size - 1] = 0;
}

void CountBingo(int _board[][10], int _size, int& _count)
{
	for (int i = 0; i < _size; i++)
	{									// �� ����
		if (!cache[0][i] && !_board[i][0])	// 0���� *�̸�
		{
			for (int j = 1; j < _size; j++)	// ������������ Ž��
			{
				if (_board[i][j])			// 0�� �ƴ� ���� ������
					break;					// �ݺ��� Ż��
				if (j == _size - 1)			// ������ ������ �̻� ������
				{
					++_count;				// ī��Ʈ 1 ����
					cache[0][i] = 1;
				}
			}
		}
										// �� ����
		if (!cache[1][i] && !_board[0][i])	// 0���� *�̸�
		{
			for (int j = 1; j < _size; j++)	// ����������� Ž��
			{
				if (_board[j][i])			// 0�� �ƴ� ���� ������
					break;					// �ݺ��� Ż��
				if (j == _size - 1)			// ������ ����� �̻������
				{
					++_count;				// ī��Ʈ 1 ����
					cache[1][i] = 1;
				}
			}
		}
	}

									// �밢�� ����
	if (!cache[0][10] && !_board[0][0])
	{
		for (int i = 1; i < _size; ++i)
		{
			if (_board[i][i])
				break;
			if (i == _size - 1)
			{
				++_count;
				cache[0][10] = 1;
			}
		}
	}

	if (!cache[1][10] && !_board[0][_size])
	{
		for (int i = 1; i < _size; ++i)
		{
			if (_board[i][_size - i])
				break;
			if (i == _size - 1)
			{	
				++_count;
				cache[1][10] = 1;
			}
		}
	}
}