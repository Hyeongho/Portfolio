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
		cout << "책이 없습니다." << endl;
	}

	else
	{
		for (int i = 0; i < book.size(); i++)
		{
			cout << "제목: " << book[i].strName << endl;
			cout << "책 번호: " << book[i].strNumber << endl;
			cout << "대여금액: " << book[i].price << endl;

			if (book[i].isRent)
			{
				cout << "대여가능" << endl << endl;
			}

			else
			{
				cout << "대여 불가능" << endl << endl;
			}
		}
	}
}

vector<Book> Book::Insert(vector<Book>& _book)
{
	cout << "제목: ";
	cin.ignore(1024, '\n');
	getline(cin, strName);

	cout << "책 번호: ";
	getline(cin, strNumber);

	cout << "대여금액: ";

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
		cout << "책이 없습니다" << endl;

		return;
	}

	cout << "제목: ";
	cin.ignore(1024, '\n');
	getline(cin, name);

	cout << "책 번호: ";
	getline(cin, number);

	for (int i = 0; i < _book.size(); i++)
	{
		if ((name == _book[i].strName) && (number == _book[i].strNumber))
		{
			_book[i].isRent = false;

			return;
		}
	}

	cout << "대여 가능한 책이 없습니다." << endl;
}

void Book::Return(vector<Book>& _book)
{
	string name;
	string number;

	if (_book.empty())
	{
		cout << "책이 없습니다" << endl;

		return;
	}

	cout << "제목: ";
	cin.ignore(1024, '\n');
	getline(cin, name);

	cout << "책 번호: ";
	getline(cin, number);

	for (int i = 0; i < _book.size(); i++)
	{
		if ((name == _book[i].strName) && (number == _book[i].strNumber))
		{
			_book[i].isRent = true;

			return;
		}
	}

	cout << "반납 가능한 책이 없습니다." << endl;
}
