#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


#define maxn 1111111
int a[maxn];


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	double w;
	cin >> n >> w;

	for (int i = 0; i < n*2; i++)
	{
		cin >> a[i];
	}

	sort(a, a + 2*n);
	double capacity_girl_min = a[0];
	double capacity_boy_min = a[n];
	double threshold = w / (3 * n);

	double capacity_girl = min(min(capacity_girl_min, capacity_boy_min / 2), threshold);
	
	double total = capacity_girl * 3 * n;

	cout << setprecision(10) << total;

	cin >> total;
	return 0;
}