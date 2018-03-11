#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define maxn 2000
int h[maxn], c[maxn];


int main()
{

	freopen("INPUT.INP", "rt", stdin);
	int n, a, b;
	cin >> n >> a >> b;
	
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}

	sort(h, h + n);
	int ans;
	ans = h[b] - h[b - 1];
	cout << ans;

	cin >> ans;
	return 0;
}