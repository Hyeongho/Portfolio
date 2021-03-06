#define NAME_SIZE 32

#include <iostream>
#include <time.h>
#include <string>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE, 
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NOME, 
	MT_EASY, 
	MT_NORMAL, 
	MT_HARD, 
	MT_BACK
};

enum  JOB
{
	JOB_NONE, 
	JOB_KNIGHT, 
	JOB_ARCHER, 
	JOB_WIZARD, 
	JOB_END
};

struct _tagPlayer
{
	string strName;
	string strJobName;

	JOB eJOB;

	int iAttackMin;
	int iAttackMax;

	int iArmorMin;
	int iArmorMax;

	int iHP;
	int iHPMax;

	int iMP;
	int iMPMax;

	int iExp;

	int iLevel;
};

struct _tagMonster
{
	string strName;

	int iAttackMin;
	int iAttackMax;

	int iArmorMin;
	int iArmorMax;

	int iHP;
	int iHPMax;

	int iMP;
	int iMPMax;

	int iExp;

	int iLevel;

	int iGoldMin;
	int iGoldMax;
};

int main()
{
	srand(time(NULL));

	// 캐릭터 생성

	_tagPlayer tPlayer;

	cout << "이름:  ";
	getline(cin, tPlayer.strName);

	int iJop = JOB_NONE;

	while (iJop == JOB_NONE)
	{
		system("cls");

		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;

		cout << "직업을 선택하세요: ";

		cin >> iJop;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJop <= JOB_NONE || iJop >= JOB_END)
		{
			iJop = JOB_NONE;
		}
	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;

	tPlayer.eJOB = (JOB)iJop;

	switch (tPlayer.eJOB)
	{
	case JOB_KNIGHT:
		tPlayer.strJobName = "기사";

		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;

		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;

		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;

		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;

		break;

	case JOB_ARCHER:
		tPlayer.strJobName = "궁수";

		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;

		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;

		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;

		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;

		break;

	case JOB_WIZARD:
		tPlayer.strJobName = "마법사";

		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;

		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;

		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;

		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;

		break;

	default:
		break;
	}

	// 몬스터 생성

	_tagMonster tMonsterArr[MT_BACK - 1];

	// 고블린 생성

	tMonsterArr[0].strName = "고블린";
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;

	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;

	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;

	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;

	tMonsterArr[0].iLevel = 1;

	tMonsterArr[0].iExp = 1000;

	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤 생성

	tMonsterArr[1].strName = "트롤";
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
				
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
				
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
				
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
				
	tMonsterArr[1].iLevel = 5;
				
	tMonsterArr[1].iExp = 7000;
				
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	// 드래곤 생성

	tMonsterArr[2].strName = "드래곤";
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
				
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
				
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
				
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
				
	tMonsterArr[2].iLevel = 10;
				
	tMonsterArr[2].iExp = 30000;
				
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	while (true)
	{
		system("cls");

		cout << "*********************** 로비 ***********************" << endl;

		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;

		cout << "메뉴를 선택하세요: ";

		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');

			continue;
		}

		if (iMenu == MM_EXIT)
		{
			break;
		}

		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");

				cout << "*********************** 맵 ***********************" << endl;

				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;

				cout << "맵을 선택하세요: ";

				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');

					continue;
				}

				if (iMenu == MT_BACK)
				{
					break;
				}

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
				{
					switch (iMenu)
					{
					case MT_EASY:
						cout << "*********************** 쉬움 ***********************" << endl;

						break;

					case MT_NORMAL:
						cout << "*********************** 보통 ***********************" << endl;

						break;

					case MT_HARD:
						cout << "*********************** 어려움 ***********************" << endl;

						break;

					default:
						break;
					}
				}
			}

			break;

		case MM_STORE:
			break;

		case MM_INVENTORY:
			break;

		default:
			break;
		}

	}
}