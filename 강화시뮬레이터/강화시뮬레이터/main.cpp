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
				cout << "방어구 종류를 선택해 주세요" << endl;
				cout << "(1. 모자 2. 상의 3. 한벌옷, 4. 하의 5. 신발, 6. 장갑, 7. 망토, 8. 벨트, 9. 어께장식, 10. 얼굴 장식 " << endl;
				cout << "11. 눈장식, 12. 귀고리, 13. 반지, 14. 팬던트, 15. 기계심장 ): ";
			}
		}

		else
		{

		}
	}

}