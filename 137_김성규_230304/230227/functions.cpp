#include "230227.h"

void CreatePlayer()
{
	PCREATURE player = nullptr;
	while (true)
	{
		system("cls");
		int iClass;
		cout << "==========================================================";
		cout << "\n직업을 선택하세요: 0. 불러오기   1. 전사   2. 마법사   3. 도적   4. 종료\n";
		iClass = CheckInputRange(0, 4);

		if (iClass == 0)
		{
			LoadData(&player);
		}
		else if (iClass == 전사)
			player = InitWarrior();
		else if (iClass == 마법사)
			player = InitMagician();
		else if (iClass == 도적)
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
		if (_player->iState == STATE::사망)	// 플레이어가 사망 상태라면 다시 초기화
			break;
		if (_player->iState == STATE::중독)	// 모든 디버프 해제
			_player->iState = STATE::생존;
		ShowPlayerCondition(_player);

		int iInput;
		cout << "\n1. 사냥터   2. 전 단계\n";
		iInput = CheckInputRange(1, 2);
		if (iInput == 1)
		{
			system("cls");
			ShowPlayerCondition(_player);
			cout << "\n0. 저장   1. 초급   2. 중급   3. 고급   4. 전 단계\n";
			iInput = CheckInputRange(0, 4);
			switch (iInput)
			{
			case 0:
			{				
				FILE* fp = nullptr;
				errno_t err = fopen_s(&fp, "../Data/Saved_Data.txt", "wb");
				if (!err)
				{
					cout << "파일 개방 성공\n";
					fwrite(_player, sizeof(CREATURE), 1, fp);
					cout << "데이터 저장 성공\n";
					fclose(fp);
				}
				else
				{
					cout << "파일 개방 실패\n";
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
		monster->szClass = "초급";
	else if (_field == 2)
		monster->szClass = "중급";
	else
		monster->szClass = "고급";

	int iMonsterHp = 30 * _field;
	int iMonsterAttack = 3 * _field;
	int iInput;

	while (true)
	{
		system("cls");
		ShowPlayerCondition(_player);
		cout << "\n이름 : " << monster->szClass << '\n' << "체력 : " << iMonsterHp << "\t" << "공격력 : " << iMonsterAttack;
		cout << "\n==========================================================";

		if (_player->iState == STATE::사망)							// 몬스터는 살아있는데 플레이어가 죽었다면
		{
			cout << "\n플레이어 사망\n";
			delete monster;
			monster = nullptr;
			system("pause");
			break;
		}

		cout << "\n1. 공격   2. 인벤토리   3. 도망 : \n";
		iInput = CheckInputRange(1, 3);

		if (iInput == 1)								// 굳이 함수로 또 빼지 않겠음
		{
			iMonsterHp -= _player->iAttack;

			if (iMonsterHp > 0)							// 몬스터가 살아있다면 공격
			{
				if (iMonsterAttack > _player->iDeffense)
					_player->iHp -= (iMonsterAttack - _player->iDeffense);	// 방어력이 몬스터의 공격력보다 높다면 체력이 회복될 수 있으므로 건너뛰기

				if (_field == 3)						// 고급 필드라면 피격 시 중독상태 부여
				{
					if (_player->iState == STATE::중독)
						_player->iHp -= 5;
					else
						_player->iState = STATE::중독;	// 첫 턴 이후 부터 체력 턴당 5씩 감소
				}

				if (_player->iHp < 0)							// 몬스터는 살아있는데 플레이어가 죽었다면
				{
					_player->iHp = 0;							// 플레이어 체력 0으로 고정
					_player->iState = STATE::사망;
					continue;
				}
			}
			else										// 몬스터는 죽고 플레이어는 살아있다면 승리 후 사냥터 선택
			{
				delete monster;
				monster = nullptr;
				strcpy_s(_player->cItems[_player->iItemCount], 10, "회복약");
				++_player->iItemCount;
				cout << "회복약을 획득하였습니다.\n\n";
				cout << "승리\n";
				system("pause");
				break;
			}
		}
		else if (iInput == 2)
		{
			PINVEN inven = new INVEN;	// ShowPlayerItems를 이용해보자
			inven->ShowPlayerItems(_player);

			cout << "\n1. 회복약 사용   2. 전투로 돌아가기\n";
			iInput = CheckInputRange(1, 2);
			if (iInput == 1)
			{
				if (!_player->iItemCount)
				{
					cout << "아이템이 없습니다\n";
					system("pause");
					delete inven;
					inven = nullptr;
					continue;
				}
				//strcpy_s(_player->cItems[_player->iItemCount - 1], 10,  "");
				--_player->iItemCount;
				_player->iHp += 30;
				cout << "체력이 30 회복되었습니다.";
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
			break;		// 도망가기로 했다면 사냥터 선택으로 이동
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
		cout << "파일 개방 성공\n";

		fread(tagTempData, sizeof(CREATURE), 1, fp);

		fclose(fp);		// 개방한 파일을 다 사용했으면 소멸

		_player->iState = tagTempData->iState;
		_player->iItemCount = tagTempData->iItemCount;
		for (int i = 0; i < tagTempData->iItemCount; ++i)
			strcpy_s(_player->cItems[i], sizeof(char)*10, tagTempData->cItems[i]);
		_player->szClass = tagTempData->szClass;
		_player->iHp = tagTempData->iHp;
		_player->iAttack = tagTempData->iAttack;
		_player->iDeffense = tagTempData->iDeffense;
		_player->iItemCount = tagTempData->iItemCount;

		cout << "불러오기 성공\n";
	}
	else
	{
		cout << "파일 개방 실패\n";
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
		cout << "파일 개방 성공\n";

		fread(*_player, sizeof(CREATURE), 1, fp);

		//fclose(fp);		// 개방한 파일을 다 사용했으면 소멸

		cout << "불러오기 성공\n";
	}
	else
	{
		cout << "파일 개방 실패\n";
	}
}

PCREATURE InitWarrior()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "전사";
	tagTemp->iHp = 120;
	tagTemp->iAttack = 10;
	tagTemp->iDeffense = 5;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

PCREATURE InitMagician()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "마법사";
	tagTemp->iHp = 90;
	tagTemp->iAttack = 15;
	tagTemp->iDeffense = 0;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

PCREATURE InitThief()
{
	PCREATURE tagTemp = new CREATURE;

	tagTemp->szClass = "도적";
	tagTemp->iHp = 100;
	tagTemp->iAttack = 12;
	tagTemp->iDeffense = 1;
	tagTemp->iItemCount = 0;

	return tagTemp;
}

const void ShowPlayerCondition(const PCREATURE _player)
{
	cout << "==========================================================";
	cout << "\n이름 : " << _player->szClass << '\n' << "체력 : " << _player->iHp << "\t공격력 : " << _player->iAttack << "\t방어력 : " << _player->iDeffense;

	if (_player->iState == STATE::중독)
		cout << "\n!!!중독 상태입니다!!!";
	cout << "\n==========================================================";
}

int CheckInputRange(int iFloor, int iCeiling)
{
	int iInput;
	cin >> iInput;

	while (iInput < iFloor || iInput > iCeiling)
	{
		if (cin.fail())	// 버퍼 초기화
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << '\n';
		}
		cout << "\n잘못된 입력입니다. 다시 선택하세요: ";
		cin >> iInput;
	}
	return iInput;
}

