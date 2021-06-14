#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

class BingoGame
{
	vector<int> number;
	vector<int> AI;

	int Bingo = 0;
	int AIBingo = 0;

	int mode = 0;

	vector<int> AISelect;

public:
	BingoGame();
	~BingoGame();

	void SelectMode();

	void Print();

	void IsWin(int *win, int *lose);

	bool InputPlayer(int input);
	void InputAI();

	void CheckBingo();
};

