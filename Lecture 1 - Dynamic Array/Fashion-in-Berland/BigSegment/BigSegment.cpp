#include<vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void main()
{
	int n;
	int min_l, max_r;
	vector<int> L, R;

	cin >> n;
	cin >> min_l;
	cin >> max_r;
	L.push_back(min_l);
	R.push_back(max_r);

	//Find min of l and max of r
	for (int i = 1; i < n; i++)
	{
		int l, r;
		cin >> l;
		cin >> r;

		L.push_back(l);
		R.push_back(r);
		
		if (l < min_l)
			min_l = l;
		if (r > max_r)
			max_r = r;
	}

	//The one have the smallest left barrier and the biggest right barrier is the one which covers all other
	for (int i = 0; i < n; i++)
	{
		if (L[i] == min_l && R[i] == max_r)
		{
			cout << i + 1;
			return;
		}
	}
	cout << "-1";
	return;
}