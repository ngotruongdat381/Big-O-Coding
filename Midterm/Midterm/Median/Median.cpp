#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <functional>  
using namespace std;

#define maxn 1000005
int a[maxn];


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	std::sort(a, a + n, std::greater<int>());


	cout << a[n / 2];

	return 0;
}