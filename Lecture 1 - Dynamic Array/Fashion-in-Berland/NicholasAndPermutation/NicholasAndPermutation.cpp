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
	//Input and find min and max of array
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

	//Find between index of min and index of max, which one is in the left, which.
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

	//compare between the distance from begining to the left position and the one from the right position to ending
	if (index_left > n - 1 - index_right)
		cout << index_right;
	else
		cout << n - (index_left + 1);

	return;
}