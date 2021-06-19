#include "Book.h"

Book::Book()
{
	strName = "";
	strNumber = "";

	price = 0;

	isRent = true;
}

Book::~Book()
{
}

void Book::print(vector<Book> book)
{
	if (book.empty())
	{
		cout << "å�� �����ϴ�." << endl;
	}

	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			cout << "����: " << book[i].strName << endl;
			cout << "å ��ȣ: " << book[i].strNumber << endl;
			cout << "�뿩�ݾ�: " << book[i].price << endl;

			if (book[i].isRent)
			{
				cout << "�뿩����" << endl << endl;
			}

			else
			{
				cout << "�뿩 �Ұ���" << endl << endl;
			}
		}
	}
}

vector<Book> Book::Insert(vector<Book>& _book)
{
	cout << "����: ";
	cin.ignore(1024, '\n');
	getline(cin, strName);

	cout << "å ��ȣ: ";
	getline(cin, strNumber);

	cout << "�뿩�ݾ�: ";

	cin >> price;

	_book.push_back(*this);

	return _book;
}

void Book::Rent(vector<Book>& _book)
{
	string name;
	string number;

	if (_book.empty())
	{
		cout << "å�� �����ϴ�" << endl;

		return;
	}

	cout << "����: ";
	cin.ignore(1024, '\n');
	getline(cin, name);

	cout << "å ��ȣ: ";
	getline(cin, number);

	for (int i = 0; i < _book.size(); i++)
	{
		if ((name == _book[i].strName) && (number == _book[i].strNumber))
		{
			_book[i].isRent = false;

			return;
		}
	}

	cout << "�뿩 ������ å�� �����ϴ�." << endl;
}

void Book::Return(vector<Book>& _book)
{
	string name;
	string number;

	if (_book.empty())
	{
		cout << "å�� �����ϴ�" << endl;

		return;
	}

	cout << "����: ";
	cin.ignore(1024, '\n');
	getline(cin, name);

	cout << "å ��ȣ: ";
	getline(cin, number);

	for (int i = 0; i < _book.size(); i++)
	{
		if ((name == _book[i].strName) && (number == _book[i].strNumber))
		{
			_book[i].isRent = true;

			return;
		}
	}

	cout << "�ݳ� ������ å�� �����ϴ�." << endl;
}
