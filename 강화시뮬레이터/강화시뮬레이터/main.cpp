#include <iostream>

#include "Equipment.h"

using namespace std;

int main()
{
	int collect;

	Equipment equipment;

	while (1)
	{
		cout << "장비 종류를 골라주세요(1. 무기 2. 방어구): ";

		cin >> collect;

		switch (collect)
		{
		case 1:
			equipment.setWeapon(true);
			break;

		case 2:
			equipment.setArmor(true);
			break;

		default:
			cout << "다시 골라 주세요" << endl;
			break;
		}

		if (equipment.getWeapon())
		{
			while (1)
			{
				cout << "무기 종류를 선택해 주세요(1. 주무기 2. 보조부기 3. 포스쉴드, 소울링 4. 방패 5. 엠블럼): ";

				cin >> collect;
			}
		}

		else if (equipment.getArmor())
		{
			while (1)
			{

			}
		}

		else
		{

		}
	}

}