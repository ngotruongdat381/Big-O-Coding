#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


#define maxn 1111111
long long c[maxn];


int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	sort(c, c + n);

	long long ans = 0;
	int learn_time = 1;
	for (int i = 0; i < n; i++)
	{
		learn_time = x - i;
		if (learn_time < 1)
			learn_time = 1;

		ans += c[i] * learn_time;
	}

	cout << ans;

	//cin >> n;
	return 0;
}