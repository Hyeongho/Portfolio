#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum MENU
{
	MENU_NONE,
	MENU_INSERT, 
	MENU_RENT,
	MENU_RETURN,
	MENU_OUTPUT,
	MENU_EXIT
};

class Book
{
	string strName;
	string strNumber;
	
	int price;

	bool isRent;

public:
	Book();
	~Book();

	void print(vector<Book> book);

	vector<Book> Insert(vector<Book>& _book);
	void Rent(vector<Book>& _book);
	void Return(vector<Book>& _book);
};

