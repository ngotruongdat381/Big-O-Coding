#include<vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	int n;
	vector<int> a;
	int index_min = 0, index_max = 0;
	int index_left, index_right;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		a.push_back(number);
		if (number > a[index_max])
			index_max = i;
		if (number < a[index_min])
			index_min = i;
	}

	if (index_min < index_max)
	{
		index_left = index_min;
		index_right = index_max;
	}
	else 
	{
		index_left = index_max;
		index_right = index_min;
	}

	if (index_left > n - 1 - index_right)
		cout << index_right;
	else
		cout << n - (index_left + 1);

	return;
}