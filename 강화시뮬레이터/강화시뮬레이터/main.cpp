#include <iostream>

#include "Equipment.h"

using namespace std;

int main()
{
	int collect;

	Equipment equipment;

	while (1)
	{
		cout << "��� ������ ����ּ���(1. ���� 2. ��): ";

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
			cout << "�ٽ� ��� �ּ���" << endl;
			break;
		}

		if (equipment.getWeapon())
		{
			while (1)
			{
				cout << "���� ������ ������ �ּ���(1. �ֹ��� 2. �����α� 3. ��������, �ҿ︵ 4. ���� 5. ����): ";

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