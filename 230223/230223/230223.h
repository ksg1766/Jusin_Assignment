#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

static bool cache[2][11] = {};

void q1();
void ShowBoard(int _board[][10], int _size, int& _count);
void SelectOne(int _board[][10], int _size, bool& _isMyTurn);
void CountBingo(int _board[][10], int _size, int& _count);

void q2();
int GetPos(int _board[][5], int _size);
void Move(int _board[][5], int _size, int loc, char _input);
void Swap(int* _left, int* _right);
void ShowBoard(int _board[][5], int _size);
