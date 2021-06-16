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

		cout << "1. 학생등록" << endl;
		cout << "2. 학생삭제" << endl;
		cout << "3. 학생탐색" << endl;
		cout << "4. 학생출력" << endl;
		cout << "5. 종료" << endl;

		cout << "메뉴를 선택하세요: ";

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

			cout << "================ 학생추가 ================" << endl;

			_tagStudent StudentArr;

			cout << "이름: ";
			cin >> StudentArr.strName;

			cout << "주소: ";
			cin.ignore(1024, '\n');
			getline(cin, StudentArr.strAddress);

			cout << "전화번호: ";
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
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}

		system("pause");
	}
}