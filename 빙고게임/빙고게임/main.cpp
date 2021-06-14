#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "BingoGame.h"

using namespace std;

int main()
{
	srand(time(NULL));

	BingoGame bingoGame;

	bingoGame.SelectMode();

	int isWin = false;
	int isLose = false;

	while (true)
	{
		system("cls");

		bingoGame.Print();

		bingoGame.IsWin(&isWin, &isLose);

		if (isWin)
		{
			cout << "Player 승리" << endl;

			break;
		}

		else if(isLose)
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

		if (bingoGame.InputPlayer(input))
		{
			continue;
		}

		bingoGame.InputAI();

		bingoGame.CheckBingo();
	}
}