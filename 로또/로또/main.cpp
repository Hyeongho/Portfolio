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

	cout << "�ζ� ��ȣ: ";

	for (int i = 0; i < 6; i++)
	{
		cout << v[i] << " ";
	}
	
	cout << "���ʽ� ��ȣ: " << v[6] << endl;
}