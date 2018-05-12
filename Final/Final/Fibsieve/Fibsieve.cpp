#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	long long int n, t, j = 0, count = 1;
	cin >> t;

	while (t--)
	{
		cin >> n;
		long long int sq = ceil(sqrt(n));
		long long int r = sq*sq - n;
		long long int x, y;
		if (r < sq)
		{
			y = r + 1;
			x = sq;
		}
		else
		{
			x = 2 * sq - r - 1;
			y = sq;
		}
		if (sq % 2 == 1)
			swap(x, y);
		cout << "Case " << count++ << ": "<< x << " " << y << endl;

	}
	return 0;

}