#include "Book.h"

int main()
{
	Book book;

	vector<Book> vBook;

	while (true)
	{
		system("cls");

		cout << "1. 책등록" << endl;
		cout << "2. 책대여" << endl;
		cout << "3. 책반납" << endl;
		cout << "4. 책출력" << endl;
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

			system("cls");

			cout << "================ 책등록 ================" << endl;

			book.Insert(vBook);

			break;
		case MENU_RENT:

			system("cls");

			cout << "================ 책대여 ================" << endl;

			book.Rent(vBook);

			break;
		case MENU_RETURN:

			system("cls");

			cout << "================ 책반납 ================" << endl;

			book.Return(vBook);

			break;
		case MENU_OUTPUT:

			system("cls");

			cout << "================ 책출력 ================" << endl;

			book.print(vBook);

			break;
		default:
			break;
		}

		system("pause");
	}
}