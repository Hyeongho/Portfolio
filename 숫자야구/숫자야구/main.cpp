#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

int main()
{
	srand(time(NULL));

	vector<int> v;

	int arr[3];

	int ball = 0;
	int strike = 0;
	int out = 0;

	bool isTrue = false;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	while (1)
	{
		isTrue = false;

		random_shuffle(v.begin(), v.end());

		vector<int> answer;

		for (int i = 0; i < 3; i++)
		{
			answer.push_back(v[i]);
		}

		cout << "* * *" << endl;

		while (!isTrue)
		{
			for (int i = 0; i < 3; i++)
			{
				cin >> arr[i];
			}

			for (int i = 0; i < answer.size(); i++)
			{
				if (arr[i] == answer[i])
				{
					strike++;
				}

				else
				{
					for (int j = 0; j < answer.size(); j++)
					{
						if (i != j)
						{
							if (arr[i] == answer[j])
							{
								ball++;
							}
						}
					}
				}
			}

			cout << strike << "strike " << ball << "ball" << endl;

			if (strike == 3)
			{
				cout << "정답입니다~~" << endl;

				Sleep(1000);

				system("cls");

				isTrue = true;
			}

			strike = 0;
			ball = 0;
		}
	}
}