#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class PuzzleGame
{
	vector<int> v;

public:
	PuzzleGame();
	~PuzzleGame();

	vector<vector<int>> Shuffle(vector<vector<int>>& NumList);

	void Board(vector<vector<int>> NumList);
};

