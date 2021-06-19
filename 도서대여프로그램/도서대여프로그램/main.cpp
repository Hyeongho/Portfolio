#include "Book.h"

int main()
{
	Book book;

	vector<Book> vBook;

	while (true)
	{
		system("cls");

		cout << "1. å���" << endl;
		cout << "2. å�뿩" << endl;
		cout << "3. å�ݳ�" << endl;
		cout << "4. å���" << endl;
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

			system("cls");

			cout << "================ å��� ================" << endl;

			book.Insert(vBook);

			break;
		case MENU_RENT:

			system("cls");

			cout << "================ å�뿩 ================" << endl;

			book.Rent(vBook);

			break;
		case MENU_RETURN:

			system("cls");

			cout << "================ å�ݳ� ================" << endl;

			book.Return(vBook);

			break;
		case MENU_OUTPUT:

			system("cls");

			cout << "================ å��� ================" << endl;

			book.print(vBook);

			break;
		default:
			break;
		}

		system("pause");
	}
}