#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;

#define MAX 200005
#define INF 1e17

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	set<long long> s;

	long long min = INF;

	for (int i = 0; i < n; i++)
	{
		long long p;
		cin >> p;
		s.insert(p);

		set<long long>::iterator it = s.upper_bound(p);
		long long dif;

		if (i != 0 && it != s.end())
		{
			dif = *it - p;

			if (dif < min)
				min = dif;
		}


	}
	cout << min << endl;


	return 0;
}