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

			if (tStudentArr.size() == STUDENT_MAX)
			{
				break;
			}

			_tagStudent StudentArr;

			cout << "이름: ";
			cin >> StudentArr.strName;

			cout << "주소: ";
			cin.ignore(1024, '\n');
			getline(cin, StudentArr.strAddress);

			cout << "전화번호: ";
			getline(cin, StudentArr.strPhoneNumber);

			cout << "국어: ";
			cin >> StudentArr.iKor;

			cout << "영어: ";
			cin >> StudentArr.iEng;

			cout << "수학: ";
			cin >> StudentArr.iMath;

			StudentArr.iTotal = StudentArr.iKor + StudentArr.iEng + StudentArr.iMath;

			StudentArr.fAvg = StudentArr.iTotal / 3.0f;

			StudentArr.iNumber = iStdNumber;
			iStdNumber++;

			tStudentArr.push_back(StudentArr);

			cout << "학생 추가 완료" << endl;

			break;
		}
		case MENU_DELETE:
		{
			system("cls");

			cout << "================ 학생탐색 ================" << endl;

			string strSearchName;
			cin.ignore(1024, '\n');
			cout << "삭제할 이름을 입력하세요: ";
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

			cout << "================ 학생탐색 ================" << endl;

			string strSearchName;
			cin.ignore(1024, '\n');
			cout << "탐색한 이름을 입력하세요: ";
			getline(cin, strSearchName);

			for (int i = 0; i < tStudentArr.size(); i++)
			{
				if (strSearchName == tStudentArr[i].strName)
				{
					cout << "이름: " << tStudentArr[i].strName << endl;
					cout << "전화번호: " << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소: " << tStudentArr[i].strAddress << endl;
					cout << "학번: " << tStudentArr[i].iNumber << endl;
					cout << "국어: " << tStudentArr[i].iKor << endl;
					cout << "영어: " << tStudentArr[i].iEng << endl;
					cout << "수학: " << tStudentArr[i].iMath << endl;
					cout << "총점: " << tStudentArr[i].iTotal << endl;
					cout << "평균: " << tStudentArr[i].fAvg << endl;

					cout << endl;

					break;
				}
			}

			break;
		}		
		case MENU_OUTPUT:
			system("cls");

			cout << "================ 학생출력 ================" << endl;

			for (int i = 0; i < tStudentArr.size(); i++)
			{
				cout << "이름: " << tStudentArr[i].strName << endl;
				cout << "전화번호: " << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소: " << tStudentArr[i].strAddress << endl;
				cout << "학번: " << tStudentArr[i].iNumber << endl;
				cout << "국어: " << tStudentArr[i].iKor << endl;
				cout << "영어: " << tStudentArr[i].iEng << endl;
				cout << "수학: " << tStudentArr[i].iMath << endl;
				cout << "총점: " << tStudentArr[i].iTotal << endl;
				cout << "평균: " << tStudentArr[i].fAvg << endl;

				cout << endl;
			}

			break;
		default:
			cout << "메뉴를 잘못 선택했습니다." << endl;
			break;
		}

		system("pause");
	}
}