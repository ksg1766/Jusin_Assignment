#include "230223.h"
#include <ctime>

void q1()
{
	// 숙제 1.
	// 5 * 5 배열을 만들고 빙고게임
	// 1~25로 숫자 25개를 5*5형식으로 출력
	// 숫자 입력 받아서 일치하는 숫자는 *로 출력
	// 가로 || 세로 || 대각선 별 5개인 경우 빙고 ++1
	// 5빙고 되면 승리 & 종료
	// 가능하다면 대전 형식으로도 만들어 보자

	srand(unsigned(time(NULL)));
	string szPlayers[2] = { "컴퓨터", "플레이어" };
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
	cout << '\n' << szPlayers[isMyTurn] << " 승리!\n";
}

void ShowBoard(int _board[][10], int _size, int& _count)
{
	cout << "완성된 빙고의 수: " << _count << "\n\n";
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
		cout << "\n플레이어의 차례 입니다: ";
		cin >> iInput;
	}
	else
	{
		cout << "\n컴퓨터의 차례입니다: ";
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
	{									// 행 빙고
		if (!cache[0][i] && !_board[i][0])	// 0열이 *이면
		{
			for (int j = 1; j < _size; j++)	// 마지막열까지 탐색
			{
				if (_board[i][j])			// 0이 아닌 열이 있으면
					break;					// 반복문 탈출
				if (j == _size - 1)			// 마지막 열까지 이상 없으면
				{
					++_count;				// 카운트 1 증가
					cache[0][i] = 1;
				}
			}
		}
										// 열 빙고
		if (!cache[1][i] && !_board[0][i])	// 0행이 *이면
		{
			for (int j = 1; j < _size; j++)	// 마지막행까지 탐색
			{
				if (_board[j][i])			// 0이 아닌 행이 있으면
					break;					// 반복문 탈출
				if (j == _size - 1)			// 마지막 행까지 이상없으면
				{
					++_count;				// 카운트 1 증가
					cache[1][i] = 1;
				}
			}
		}
	}

									// 대각선 빙고
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