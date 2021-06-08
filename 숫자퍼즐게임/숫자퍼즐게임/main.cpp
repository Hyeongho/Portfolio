#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <Windows.h>

#include "PuzzleGame.h"

using namespace std;

int main()
{
	srand(time(NULL));

	PuzzleGame puzzleGame;

	vector<vector<int>> number(5, vector<int>(5, 0));

	puzzleGame.Shuffle(number);

	bool isPlay = true;	

	int input;

	bool isWin = false;

	int x = 4;
	int y = 4;

	while (isPlay)
	{
		int temp;

		system("cls");

		puzzleGame.Board(number);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i != 4 && j != 4)
				{
					if (number[i][j] == 1 + j + (i * 5))
					{
						isWin = true;
					}

					else
					{
						isWin = false;

						break;
					}
				}

				if (isWin)
				{
					if (number[4][4] == INT_MAX)
					{
						isWin = true;
					}

					else
					{
						isWin = false;
					}
				}			
			}
		}

		if (isWin)
		{
			cout << "숫자를 모두 맞췄습니다." << endl << endl;

			cout << "게임을 새로 시작하겠습니까?(Y, N)";
		}

		input = _getch();

		if (!isWin)
		{
			if (input == 224 || input == 0)
			{
				input = _getch();

				switch (input)
				{
				case 72:
					if (y > 0)
					{
						temp = number[y][x];
						number[y][x] = number[y - 1][x];
						number[y - 1][x] = temp;
						y--;
					}
					break;

				case 80:
					if (y < 4)
					{
						temp = number[y][x];
						number[y][x] = number[y + 1][x];
						number[y + 1][x] = temp;
						y++;
					}
					break;

				case 75:
					if (x > 0)
					{
						temp = number[y][x];
						number[y][x] = number[y][x - 1];
						number[y][x - 1] = temp;
						x--;
					}
					break;

				case 77:
					if (x < 4)
					{
						temp = number[y][x];
						number[y][x] = number[y][x + 1];
						number[y][x + 1] = temp;
						x++;
					}
					break;

				default:
					break;
				}
			}
		}

		else
		{
			switch (input)
			{
			case 'y':
			case 'Y':
				puzzleGame.Shuffle(number);
				break;

			case 'n':
			case 'N':
				isPlay = false;
				break;

			default:
				break;
			}
		}
	}

	return 0;
}