#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define maxn 111111
int a[maxn], sorted_a[maxn];


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sorted_a[i] = a[i];
	}

	sort(sorted_a, sorted_a + n);
	
	int l = 0, r = 0;

	for (int i = 0; i < n; i++)
	{
		if (sorted_a[i] != a[i])
		{
			l = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (sorted_a[i] != a[i])
		{
			r = i;
			break;
		}
	}

	reverse(a + l, a + r + 1);

	for (int i = l; i <= r; i++)
	{
		if (sorted_a[i] != a[i])
		{
			cout << "no";
			return 0;
		}
	}
	
	if (l == 0 && r == 0)
		cout << "yes" << endl << 1 << " " << 1;
	else
		cout << "yes" << endl << l + 1 << " " << r + 1;

	cin >> l;
	return 0;
}