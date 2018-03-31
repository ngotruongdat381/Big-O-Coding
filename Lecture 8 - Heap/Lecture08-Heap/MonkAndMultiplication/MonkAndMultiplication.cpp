#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;


#define maxn 1111111
//int a[maxn];


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	long long a, b, c = 0;
	priority_queue<long long> pq;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);

		if (pq.size() < 3)
		{
			cout << -1 << endl;
		}
		else
		{
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			c = pq.top();
			pq.pop();

			cout << a*b*c << endl;
			
			pq = priority_queue<long long>();
			pq.push(a);
			pq.push(b);
			pq.push(c);
		}
	}

	return 0;
}