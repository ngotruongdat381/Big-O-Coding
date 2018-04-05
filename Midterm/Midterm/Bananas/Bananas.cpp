#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

#define maxn 200
int a[maxn];


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	long long k, n, w;
	cin >> k >> n >> w;

	long long cost = k * ((w*(w + 1)) / 2);

	long long res = cost - n;

	cout << max((int)res, 0);


	return 0;
}