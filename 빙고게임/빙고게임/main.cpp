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

int main()
{
	srand(time(NULL));

	vector<int> number;
	vector<int> AI;

	for (int i = 0; i < 25; i++)
	{
		number.push_back(i + 1);
		AI.push_back(i + 1);
	}

	random_shuffle(number.begin(), number.end());
	random_shuffle(AI.begin(), AI.end());

	int Bingo = 0;
	int AIBingo = 0;

	int mode;

	while (true)
	{
		system("cls");

		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;

		cout << "AI 모드를 선택하세요: ";

		cin >> mode;
		
		if (mode >= AM_EASY && mode <= AM_HARD)
		{
			break;
		}
	}

	vector<int> AISelect;

	while (true)
	{
		system("cls");

		cout << "============= Player =============" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (number[i * 5 + j] == INT_MAX)
				{
					cout << "*" << "\t";
				}

				else
				{
					cout << number[i * 5 + j] << "\t";
				}				
			}

			cout << endl;
		}

		cout << "Bingo Line: " << Bingo << endl;

		cout << endl;

		cout << "============= AI =============" << endl;

		switch (mode)
		{
		case AM_EASY:
			cout << "AIMode: Easy" << endl;

			break;

		case AM_HARD:
			cout << "AIMode: Hard" << endl;

			break;

		default:
			break;
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (AI[i * 5 + j] == INT_MAX)
				{
					cout << "*" << "\t";
				}

				else
				{
					cout << AI[i * 5 + j] << "\t";
				}
			}

			cout << endl;
		}

		cout << "AIBingo Line: " << AIBingo << endl;

		if (Bingo >= 5)
		{
			cout << "Player 승리" << endl;

			break;
		}

		else if (AIBingo >= 5)
		{
			cout << "AI 승리" << endl;

			break;
		}

		cout << "숫자를 입력하세요(0: 종료): ";
		int input;

		cin >> input;

		if (input == 0)
		{
			break;
		}

		else if (input < 1 || input > 25)
		{
			continue;
		}

		bool bAcc = true;

		for (int i = 0; i < number.size(); i++)
		{
			if (input == number[i])
			{
				bAcc = false;

				number[i] = INT_MAX;

				break;
			}
		}

		if (bAcc)
		{
			continue;
		}

		for (int i = 0; i < AI.size(); i++)
		{
			if (input == AI[i])
			{
				bAcc = false;

				AI[i] = INT_MAX;

				break;
			}
		}

		switch (mode)
		{
		case AM_EASY:
			AISelect.clear();
			for (int i = 0; i < AI.size(); i++)
			{
				if (AI[i] != INT_MAX)
				{
					AISelect.push_back(AI[i]);
				}
			}

			random_shuffle(AISelect.begin(), AISelect.end());

			input = AISelect.front();

			break;
		case AM_HARD:
			int iLine = 0;
			int iStarCount = 0;
			int iSaveCount = 0;

			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;

				for (int j = 0; j < 5; j++)
				{
					if (AI[i * 5 + j] == INT_MAX)
					{
						iStarCount++;
					}
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i;
					iSaveCount = iStarCount;
				}
			}

			for (int i = 0; i < 5; i++)
			{
				iStarCount = 0;

				for (int j = 0; j < 5; j++)
				{
					if (AI[j * 5 + i] == INT_MAX)
					{
						iStarCount++;
					}
				}

				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i + 5;
					iSaveCount = iStarCount;
				}
			}

			iStarCount = 0;

			for (int i = 0; i < 25; i += 6)
			{
				if (AI[i] == INT_MAX)
				{
					iStarCount++;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}


			iStarCount = 0;

			for (int i = 4; i <= 20; i += 4)
			{
				if (AI[i] == INT_MAX)
				{
					iStarCount++;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			if (iLine <= LN_H5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (AI[iLine * 5 + i] != INT_MAX)
					{
						input = AI[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				for (int i = 0; i < 5; i++)
				{
					if (AI[i * 5 + (iLine - 5)] != INT_MAX)
					{
						input = AI[i * 5 + iLine];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (AI[i] != INT_MAX)
					{
						input = AI[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 4; i < 20; i += 4)
				{
					if (AI[i] != INT_MAX)
					{
						input = AI[i];
						break;
					}
				}
			}
		}

		for (int i = 0; i < number.size(); i++)
		{
			if (input == number[i])
			{
				bAcc = false;

				number[i] = INT_MAX;

				break;
			}
		}

		for (int i = 0; i < AI.size(); i++)
		{
			if (input == AI[i])
			{
				bAcc = false;

				AI[i] = INT_MAX;

				break;
			}
		}

		Bingo = 0;

		int check1 = 0;
		int check2 = 0;

		int AIcheck1 = 0;
		int AIcheck2 = 0;

		for (int i = 0; i < 5; i++)
		{
			check1 = 0;
			check2 = 0;

			AIcheck1 = 0;
			AIcheck2 = 0;

			for (int j = 0; j < 5; j++)
			{
				if (number[i * 5 + j] == INT_MAX)
				{
					check1++;
				}

				if (number[j * 5 + i] == INT_MAX)
				{
					check2++;
				}

				if (AI[i * 5 + j] == INT_MAX)
				{
					AIcheck1++;
				}

				if (AI[j * 5 + i] == INT_MAX)
				{
					AIcheck2++;
				}
			}

			if (check1 == 5)
			{
				Bingo++;
			}

			if (check2 == 5)
			{
				Bingo++;
			}

			if (AIcheck1 == 5)
			{
				AIBingo++;
			}

			if (AIcheck2 == 5)
			{
				AIBingo++;
			}
		}

		check1 = 0;
		AIcheck1 = 0;

		for (int i = 0; i < 25; i += 6)
		{
			if (number[i] == INT_MAX)
			{
				check1++;
			}

			if (AI[i] == INT_MAX)
			{
				AIcheck1++;
			}
		}

		if (check1 == 5)
		{
			Bingo++;
		}

		if (AIcheck1 == 5)
		{
			AIBingo++;
		}

		check1 = 0;
		AIcheck1 = 0;

		for (int i = 4; i <= 20; i += 4)
		{
			if (number[i] == INT_MAX)
			{
				check1++;
			}

			if (AI[i] == INT_MAX)
			{
				AIcheck1++;
			}
		}

		if (check1 == 5)
		{
			Bingo++;
		}

		if (AIcheck1 == 5)
		{
			AIBingo++;
		}
	}
}