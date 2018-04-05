#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


priority_queue<int> pq;
queue<int> q;


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		q = queue<int>();
		pq = priority_queue<int>();

		int n, m;
		cin >> n >> m;

		for (int in = 0; in < n; in++)
		{
			int x;
			cin >> x;
			q.push(x);
			pq.push(x);
		}
		int count = 0;

		while (true)
		{
			while (q.front() == pq.top())
			{
				count++;
				if (m == 0)
				{
					cout << count << endl;
					m--;
					break;
				}
				else
				{
					m--;
				}
				q.pop();
				pq.pop();

			}

			if (m == -1)
			{
				break;
			}

			int num = q.front();
			q.push(num);
			q.pop();

			if (m == 0)
			{
				m = q.size() - 1;
			}
			else
			{
				m--;
			}
		}

	}

	return 0;
}