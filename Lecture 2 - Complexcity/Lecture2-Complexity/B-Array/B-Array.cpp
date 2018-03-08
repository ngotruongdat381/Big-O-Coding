#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define maxn 111111
int a[maxn], c[maxn];
int cnt;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int j = 0;
	
	//for (int i = 1; i <= n; i++)
	//{
	//	c[a[i]]++;
	//	if (c[a[i]] == 1)
	//	{
	//		cnt++;
	//	}

	//	while (cnt == k)
	//	{
	//		j++;
	//		c[a[j]]--;
	//		if (c[a[j]] == 0)
	//		{
	//			cout << j << " " << i;
	//			return 0;
	//		}
	//		
	//	}
	//}


	for (int i = 1; i <= n; i++)
	{
		c[a[i]]++;
		if (c[a[i]] == 1)
			cnt++;
		
		while (cnt == k)
		{
			j++;
			c[a[j]]--;
			if (c[a[j]] == 0)
			{
				cout << j << " " << i;
				return 0;
			}
		}

	}

	cout << "-1 -1";

	return 0;
}