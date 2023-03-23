#include "230227.h"

void CreatePlayer()
{
	PCREATURE player = nullptr;
	while (true)
	{
		system("cls");
		int iClass;
		cout << "==========================================================";
		cout << "\n������ �����ϼ���: 0. �ҷ�����   1. ����   2. ������   3. ����   4. ����\n";
		iClass = CheckInputRange(0, 4);

		if (iClass == 0)
		{
			LoadData(&player);
		}
		else if (iClass == ����)
			player = InitWarrior();
		else if (iClass == ������)
			player = InitMagician();
		else if (iClass == ����)
			player = InitThief();
		else
		{
			if (player != nullptr)
			{
				delete player;
				player = nullptr;
			}
			return;
		}

		SelectField(player);
	}
}

void SelectField(PCREATURE _player)
{
	while (true)
	{
		system("cls");
		if (_player->iState == STATE::���)	// �÷��̾ ��� ���¶�� �ٽ� �ʱ�ȭ
			break;
		if (_player->iState == STATE::�ߵ�)	// ��� ����� ����
			_player->iState = STATE::����;
		ShowPlayerCondition(_player);

		int iInput;
		cout << "\n1. �����   2. �� �ܰ�\n";
		iInput = CheckInputRange(1, 2);
		if (iInput == 1)
		{
			system("cls");
			ShowPlayerCondition(_player);
			cout << "\n0. ����   1. �ʱ�   2. �߱�   3. ���   4. �� �ܰ�\n";
			iInput = CheckInputRange(0, 4);
			switch (iInput)
			{
			case 0:
			{				
				FILE* fp = nullptr;
				errno_t err = fopen_s(&fp, "../Data/Saved_Data.txt", "wb");
				if (!err)
				{
					cout << "���� ���� ����\n";
					fwrite(_player, sizeof(CREATURE), 1, fp);
					cout << "������ ���� ����\n";
					fclose(fp);
				}
				else
				{
					cout << "���� ���� ����\n";
					system("pause");
				}
				break;
			}
			case 1:
				EnterField(1, _player);
				break;
			case 2:
				EnterField(2, _player);
				break;
			case 3:
				EnterField(3, _player);
				break;
			case 4:
				break;
			}
		}
		else
			break;
	}
}

void EnterField(int _field, PCREATURE _player)
{
	PCREATURE monster = new CREATURE;
	monster->iAttack = 3 * _field;
	monster->iHp = 30 * _field;
	if (_field == 1)
		monster->szClass = "�ʱ�";
	else if (_field == 2)
		monster->szClass = "�߱�";
	else
		monster->szClass = "���";

	int iMonsterHp = 30 * _field;
	int iMonsterAttack = 3 * _field;
	int iInput;

	while (true)
	{
		system("cls");
		ShowPlayerCondition(_player);
		cout << "\n�̸� : " << monster->szClass << '\n' << "ü�� : " << iMonsterHp << "\t" << "���ݷ� : " << iMonsterAttack;
		cout << "\n==========================================================";

		if (_player->iState == STATE::���)							// ���ʹ� ����ִµ� �÷��̾ �׾��ٸ�
		{
			cout << "\n�÷��̾� ���\n";
			delete monster;
			monster = nullptr;
			system("pause");
			break;
		}

		cout << "\n1. ����   2. �κ��丮   3. ���� : \n";
		iInput = CheckInputRange(1, 3);

		if (iInput == 1)								// ���� �Լ��� �� ���� �ʰ���
		{
			iMonsterHp -= _player->iAttack;

			if (iMonsterHp > 0)							// ���Ͱ� ����ִٸ� ����
			{
				if (iMonsterAttack > _player->iDeffense)
					_player->iHp -= (iMonsterAttack - _player->iDeffense);	// ������ ������ ���ݷº��� ���ٸ� ü���� ȸ���� �� �����Ƿ� �ǳʶٱ�

				if (_field == 3)						// ��� �ʵ��� �ǰ� �� �ߵ����� �ο�
				{
					if (_player->iState == STATE::�ߵ�)
						_player->iHp -= 5;
					else
						_player->iState = STATE::�ߵ�;	// ù �� ���� ���� ü�� �ϴ� 5�� ����
				}

				if (_player->iHp < 0)							// ���ʹ� ����ִµ� �÷��̾ �׾��ٸ�
				{
					_player->iHp = 0;							// �÷��̾� ü�� 0���� ����
					_player->iState = STATE::���;
					continue;
				}
			}
			else										// ���ʹ� �װ� �÷��̾�� ����ִٸ� �¸� �� ����� ����
			{
				delete monster;
				monster = nullptr;
				strcpy_s(_player->cItems[_player->iItemCount], 10, "ȸ����");
				++_player->iItemCount;
				cout << "ȸ������ ȹ���Ͽ����ϴ�.\n\n";
				cout << "�¸�\n";
				system("pause");
				break;
			}
		}
		else if (iInput == 2)
		{
			PINVEN inven = new INVEN;	// ShowPlayerItems�� �̿��غ���
			inven->ShowPlayerItems(_player);

			cout << "\n1. ȸ���� ���   2. ������ ���ư���\n";
			iInput = CheckInputRange(1, 2);
			if (iInput == 1)
			{
				if (!_player->iItemCount)
				{
					cout << "�������� �����ϴ�\n";
					system("pause");
					delete inven;
					inven = nullptr;
					continue;
				}
				//strcpy_s(_player->cItems[_player->iItemCount - 1], 10,  "");
				--_player->iItemCount;
				_player->iHp += 30;
				cout << "ü���� 30 ȸ���Ǿ����ϴ�.";
				delete inven;
				inven = nullptr;
				system("pause");
				continue;
			}
			else
			{
				delete inven;
				inven = nullptr;
				continue;
			}
		}

		else
		{
			delete monster;
			monster = nullptr;
			break;		// ��������� �ߴٸ� ����� �������� �̵�
		}
	}
}
/*
void LoadData(PCREATURE _player)
{
	FILE* fp = nullptr;
	PCREATURE tagTempData = nullptr;
	tagTempData = new CREATURE;
	errno_t err = fopen_s(&fp, "../Data/Saved_Data.txt", "rb");

	if (!err)
	{
		cout << "���� ���� ����\n";

		fread(tagTempData, sizeof(CREATURE), 1, fp);

		fclose(fp);		// ������ ������ �� ��������� �Ҹ�

		_player->iState = tagTempData->iState;
		_player->iItemCount = tagTempData->iItemCount;
		for (int i = 0; i < tagTempData->iItemCount; ++i)
			strcpy_s(_player->cItems[i], sizeof(char)*10, tagTempData->cItems[i]);
		_player->szClass = tagTempData->szClass;
		_player->iHp = tagTempData->iHp;
		_player->iAttack = tagTempData->iAttack;
		_player->iDeffense = tagTempData->iDeffense;
		_player->iItemCount = tagTempData->iItemCount;

		cout << "�ҷ����� ����\n";
	}
	else
	{
		cout << "���� ���� ����\n";
	}
	
	//return tagTempData;
}
*/
void LoadData(PCREATURE* _player)
{
	FILE* fp = nullptr;
	
	*_player = new CREATURE;
	errno_t err = fopen_s(&fp, "../Data/Saved_Data.txt", "rb");

	if (!err)
	{
		cout << "���� ���� ����\n";

		fread(*_player, sizeof(CREATURE), 1, fp);

		//fclose(fp);		// ������ ������ �� ��������� �Ҹ�

		cout << "�ҷ����� ����\n";
	}
	else
	{
		cout << "���� ���� ����\n";
	}
}

PCREATURE InitWarrior()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "����";
	tagTemp->iHp = 120;
	tagTemp->iAttack = 10;
	tagTemp->iDeffense = 5;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

PCREATURE InitMagician()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "������";
	tagTemp->iHp = 90;
	tagTemp->iAttack = 15;
	tagTemp->iDeffense = 0;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

PCREATURE InitThief()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "����";
	tagTemp->iHp = 100;
	tagTemp->iAttack = 12;
	tagTemp->iDeffense = 1;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

const void ShowPlayerCondition(const PCREATURE _player)
{
	cout << "==========================================================";
	cout << "\n�̸� : " << _player->szClass << '\n' << "ü�� : " << _player->iHp << "\t���ݷ� : " << _player->iAttack << "\t���� : " << _player->iDeffense;

	if (_player->iState == STATE::�ߵ�)
		cout << "\n!!!�ߵ� �����Դϴ�!!!";
	cout << "\n==========================================================";
}

int CheckInputRange(int iFloor, int iCeiling)
{
	int iInput;
	cin >> iInput;

	while (iInput < iFloor || iInput > iCeiling)
	{
		if (cin.fail())	// ���� �ʱ�ȭ
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n�߸��� �Է��Դϴ�. �ٽ� �����ϼ���: ";
		cin >> iInput;
	}
	return iInput;
}

