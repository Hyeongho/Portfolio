#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define NAME_SIZE 32
#define STUDENT_MAX 10

using namespace std;

struct _tagStudent
{
	string strName;
	string strAddress;
	string strPhoneNumber;
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE, 
	MENU_INSERT, 
	MENU_DELETE, 
	MENU_SEARCH, 
	MENU_OUTPUT, 
	MENU_EXIT
};

int main()
{
	//_tagStudent tStudentArr[STUDENT_MAX];

	vector<_tagStudent> tStudentArr;

	while (true)
	{
		system("cls");

		cout << "1. �л����" << endl;
		cout << "2. �л�����" << endl;
		cout << "3. �л�Ž��" << endl;
		cout << "4. �л����" << endl;
		cout << "5. ����" << endl;

		cout << "�޴��� �����ϼ���: ";

		int iMenu;

		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();

			cin.ignore(1024, '\n');

			continue;
		}

		if (iMenu == MENU_EXIT)
		{
			break;
		}

		switch (iMenu)
		{
		case MENU_INSERT:
		{
			system("cls");

			cout << "================ �л��߰� ================" << endl;

			_tagStudent StudentArr;

			cout << "�̸�: ";
			cin >> StudentArr.strName;

			cout << "�ּ�: ";
			cin.ignore(1024, '\n');
			getline(cin, StudentArr.strAddress);

			cout << "��ȭ��ȣ: ";
			cin.ignore(1024, '\n');
			getline(cin, StudentArr.strPhoneNumber);

			tStudentArr.push_back(StudentArr);

			break;
		}
		case MENU_DELETE:
			break;
		case MENU_SEARCH:
			break;
		case MENU_OUTPUT:
			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;
		}

		system("pause");
	}
}