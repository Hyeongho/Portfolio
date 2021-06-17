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

	int iStdNumber = 1;

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

			if (tStudentArr.size() == STUDENT_MAX)
			{
				break;
			}

			_tagStudent StudentArr;

			cout << "�̸�: ";
			cin >> StudentArr.strName;

			cout << "�ּ�: ";
			cin.ignore(1024, '\n');
			getline(cin, StudentArr.strAddress);

			cout << "��ȭ��ȣ: ";
			getline(cin, StudentArr.strPhoneNumber);

			cout << "����: ";
			cin >> StudentArr.iKor;

			cout << "����: ";
			cin >> StudentArr.iEng;

			cout << "����: ";
			cin >> StudentArr.iMath;

			StudentArr.iTotal = StudentArr.iKor + StudentArr.iEng + StudentArr.iMath;

			StudentArr.fAvg = StudentArr.iTotal / 3.0f;

			StudentArr.iNumber = iStdNumber;
			iStdNumber++;

			tStudentArr.push_back(StudentArr);

			cout << "�л� �߰� �Ϸ�" << endl;

			break;
		}
		case MENU_DELETE:
		{
			system("cls");

			cout << "================ �л�Ž�� ================" << endl;

			string strSearchName;
			cin.ignore(1024, '\n');
			cout << "������ �̸��� �Է��ϼ���: ";
			getline(cin, strSearchName);

			for (int i = 0; i < tStudentArr.size(); i++)
			{
				if (strSearchName == tStudentArr[i].strName)
				{
					tStudentArr.erase(tStudentArr.begin() + i);
				}
			}

			break;
		}			
		case MENU_SEARCH:
		{
			system("cls");

			cout << "================ �л�Ž�� ================" << endl;

			string strSearchName;
			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ���: ";
			getline(cin, strSearchName);

			for (int i = 0; i < tStudentArr.size(); i++)
			{
				if (strSearchName == tStudentArr[i].strName)
				{
					cout << "�̸�: " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ: " << tStudentArr[i].strPhoneNumber << endl;
					cout << "�ּ�: " << tStudentArr[i].strAddress << endl;
					cout << "�й�: " << tStudentArr[i].iNumber << endl;
					cout << "����: " << tStudentArr[i].iKor << endl;
					cout << "����: " << tStudentArr[i].iEng << endl;
					cout << "����: " << tStudentArr[i].iMath << endl;
					cout << "����: " << tStudentArr[i].iTotal << endl;
					cout << "���: " << tStudentArr[i].fAvg << endl;

					cout << endl;

					break;
				}
			}

			break;
		}		
		case MENU_OUTPUT:
			system("cls");

			cout << "================ �л���� ================" << endl;

			for (int i = 0; i < tStudentArr.size(); i++)
			{
				cout << "�̸�: " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ: " << tStudentArr[i].strPhoneNumber << endl;
				cout << "�ּ�: " << tStudentArr[i].strAddress << endl;
				cout << "�й�: " << tStudentArr[i].iNumber << endl;
				cout << "����: " << tStudentArr[i].iKor << endl;
				cout << "����: " << tStudentArr[i].iEng << endl;
				cout << "����: " << tStudentArr[i].iMath << endl;
				cout << "����: " << tStudentArr[i].iTotal << endl;
				cout << "���: " << tStudentArr[i].fAvg << endl;

				cout << endl;
			}

			break;
		default:
			cout << "�޴��� �߸� �����߽��ϴ�." << endl;
			break;
		}

		system("pause");
	}
}