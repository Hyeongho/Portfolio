#include "PuzzleGame.h"

PuzzleGame::PuzzleGame()
{
	for (int i = 0; i < 24; i++)
	{
		v.push_back(i + 1);
	}

	v.push_back(INT_MAX);
}

PuzzleGame::~PuzzleGame()
{
}

vector<vector<int>> PuzzleGame::Shuffle(vector<vector<int>> &NumList)
{
	sort(v.begin(), v.end());

	//random_shuffle(v.begin(), v.end() - 1);

	int a = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			NumList[i][j] = v[a];

			a++;
		}
	}

	return NumList;
}

void PuzzleGame::Board(vector<vector<int>> NumList)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (NumList[i][j] == INT_MAX)
			{
				cout << "*\t";
			}

			else
			{
				cout << NumList[i][j] << "\t";
			}
		}

		cout << endl << endl;
	}
}