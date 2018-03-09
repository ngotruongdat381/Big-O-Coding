#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define maxn 1111111
int a[maxn], b[maxn], c[maxn];


int main()
{

	freopen("INPUT.INP", "rt", stdin);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
	}


	//
	for (int i = 1; i <= n; i++)
	{
		c[a[i]] = 1;
	}

	for (int i = 1; i <= m; i++)
	{
		if (c[b[i]] == 1)
		{
			c[b[i]] = 0;
			b[i] = 0;
		}
	}

	int ib = 0;
	for (int ia = 1; ia <= n; ia++)
	{
		if (c[a[ia]] == 1)
		{
			while (ib <= m)
			{
				ib++;
				if (b[ib] > a[ia])
				{
					c[a[ia]] = 0;
					break;
				}
			}
		}
	}


	int sum = 0;

	for (int i = 1; i < maxn; i++)
	{
		sum += c[i];
	}

	cout << sum;
	cin >> n;
	return 0;
}