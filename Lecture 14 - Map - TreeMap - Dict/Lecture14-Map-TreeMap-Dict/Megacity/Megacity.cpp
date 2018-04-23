#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

struct Point
{
	double x;
	double y;
};

double distanceFromOrigin(Point a)
{
	double res = sqrt(pow(a.x, 2) + pow(a.y, 2));
	return res;
}

int main() {
	freopen("INPUT.INP", "rt", stdin);
	int n;
	long long s;
	cin >> n;
	cin >> s;

	long long rest = 1000000 - s;

	map<double, long long > m;
	map<double, long long>::iterator it;

	for (int i = 0; i < n; i++)
	{
		Point p;
		long long k;
		
		cin >> p.x >> p.y;
		cin >> k;

		double dist = distanceFromOrigin(p);
		m[dist] += k;
	}

	long long sum = 0LL;

	for (it = m.begin(); it != m.end(); it++)
	{
		sum += it->second;
		if (sum >= rest)
		{
			cout << fixed;
			cout << setprecision(7);
			cout << it->first;
			return 0;
		}
			
	}
	cout << -1;

	return 0;
}
