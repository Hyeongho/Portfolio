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
			cout << "���� ������ ������ �ּ���(1. �ֹ��� 2. �����α� 3. ��������, �ҿ︵ 4. ���� 5. ����): ";

			cin >> collect;
			break;

		case 2:
			cout << "�� ������ ������ �ּ���" << endl;
			cout << "(1. ���� 2. ���� 3. �ѹ���, 4. ���� 5. �Ź�, 6. �尩, 7. ����, 8. ��Ʈ, 9. ����, 10. �� ��� " << endl;
			cout << "11. �����, 12. �Ͱ�, 13. ����, 14. �Ҵ�Ʈ, 15. ������ ): ";

			break;

		default:
			cout << "�ٽ� ��� �ּ���" << endl;
			break;
		}
	}

}