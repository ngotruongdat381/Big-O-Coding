#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		int n;
		priority_queue<int, vector<int>, greater<int> > pq;

		cin >> n;

		if (n == 0)
		{
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			pq.push(num);
		}

		if (n < 2)
		{
			cout << 0 << endl;
			continue;
		}

		int cost = pq.top();
		pq.pop();

		cost += pq.top();
		pq.pop();

		int sum = cost;
		while (!pq.empty())
		{
			cost += pq.top();
			sum += cost;
			pq.pop();
		}

		cout << sum << endl;
		
	}

	return 0;
}