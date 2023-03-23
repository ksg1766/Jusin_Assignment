#pragma once
#include <iostream>
using namespace std;

enum PlayerClass {
	���� = 1,
	������,
	����,
};

typedef enum PlayerState {
	����,
	�ߵ�,
	���
}STATE;

typedef struct Creature {
	int iState = ����;

	char szClass[10] = "";
	int iHp = 0;
	int iAttack = 0;
	int iDeffense = 0;
	int iItemCount = 0;
	char cItems[10][10];
}CREATURE, * PCREATURE;

typedef struct Inventory {
	//char cItems[10][10];
	//string szItems[10];
	void ShowPlayerItems(PCREATURE _player)
	{
		if (!_player->iItemCount)
			cout << "�������� �������� �����ϴ�.\n";
		for (int i = 0; i < _player->iItemCount; i++)
			cout << i+1 << ". " << _player->cItems[i] << '\n';
	}
}INVEN, * PINVEN;

void CreatePlayer();
void SelectField(PCREATURE _player);
void EnterField(int _field, PCREATURE _player);

void LoadData(PCREATURE* _player);
PCREATURE InitWarrior();
PCREATURE InitMagician();
PCREATURE InitThief();

const void ShowPlayerCondition(const PCREATURE _player);
int CheckInputRange(int iFloor, int iCeiling);