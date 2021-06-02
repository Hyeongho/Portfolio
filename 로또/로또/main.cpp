#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(NULL));

	vector <int> v;

	for (int i = 1; i < 46; i++)
	{
		v.push_back(i);
	}

	random_shuffle(v.begin(), v.end());

	cout << "로또 번호: ";

	for (int i = 0; i < 6; i++)
	{
		cout << v[i] << " ";
	}
	
	cout << "보너스 번호: " << v[6] << endl;
}