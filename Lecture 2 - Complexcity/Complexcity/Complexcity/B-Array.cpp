#include<vector>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <set>
using namespace std;


int checkSetSize(int l, int r, vector<int> arr)
{

	std::set<int> s = std::set<int>(arr.begin() + l, arr.end() - arr.size() + 1 + r);

	return s.size();

}

void main()
{
	int n, k;
	vector<int> arr;
	vector<int> set;
	vector<int> res;

	cin >> n;
	cin >> k;
	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}

	int l = 0;
	int r = k - 1;
	int cur_size = 0;

	while (cur_size < k)
	{
		cur_size = checkSetSize(l, r, arr);
		if (cur_size < k)
		{
			r += (k - cur_size);
		}
	}

	for (int i = 0; i < r; i++)
	{
		if (arr[i] != arr[i+1])
		{
			l = i;
			break;
		}
	}

	cout << l + 1 << r + 1;
	return;
}