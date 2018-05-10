#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;




vector<int> repeatedNumber(const vector<int> &A) {
	
	vector<int> tmp(A);
	tmp.push_back(0);
	sort(tmp.begin(), tmp.end());

	int doub = 0;
	int missing = 0;

	for (int i = 0; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] == 0)
		{
			doub = tmp[i];
		}
		else if ((tmp[i + 1] - tmp[i]) == 2)
		{
			missing = (tmp[i + 1] + tmp[i]) / 2;
		}
	}
	vector<int> res = vector<int>();
	res.push_back(doub);
	res.push_back(missing);
	return res;
}

vector<int> repeatedNumber2(const vector<int> &A) {
	int a[100001];
	fill_n(a, A.size(), 0);

	int doub = 0;
	int missing = 0;

	for (int i = 0; i < A.size(); i++)
	{
		a[A[i]]++;
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (a[i] == 2)
			doub = i;
		if (a[i] == 0)
			missing = i;
	}

	vector<int> res = vector<int>();
	res.push_back(doub);
	res.push_back(missing);
	return res;
}



int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	vector<int> list;
	while (cin >> n)
	{
		list.push_back(n);
	}

	repeatedNumber2(list);

	return 0;
}