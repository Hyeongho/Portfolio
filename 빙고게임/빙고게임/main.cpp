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
			cout << "Player �¸�" << endl;

			break;
		}

		else if(isLose)
		{
			cout << "AI �¸�" << endl;

			break;
		}

		cout << "���ڸ� �Է��ϼ���(0: ����): ";
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