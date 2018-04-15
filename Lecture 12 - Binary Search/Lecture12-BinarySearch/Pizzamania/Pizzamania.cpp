#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <vector> 
using namespace std;


#define MAX 1005

vector<int> v;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int t;
	cin >> t;

	for (int it = 0; it < t; it++)
	{
		int n, m;
		cin >> n >> m;

		v = vector<int>();

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;

			v.push_back(num);
		}

		sort(v.begin(), v.end());

		vector<int>::iterator lb;
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			int rest = m - v[i];

			lb = lower_bound(v.begin(), v.end(), rest);
			if (lb != v.end() && *lb == rest && lb != v.begin()+i)
			{
				count++;
			}
		}
		cout << count / 2 << endl;
	}

	return 0;
}