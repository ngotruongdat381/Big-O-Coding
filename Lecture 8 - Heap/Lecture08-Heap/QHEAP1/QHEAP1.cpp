#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


priority_queue<long long, vector<long long>, greater<long long>> pq;
priority_queue<long long, vector<long long>, greater<long long>> pq_remove;

void pop(long long v)
{
	vector<long long> vec;

	while (v != pq.top())
	{
		vec.push_back(pq.top());
		pq.pop();
	}

	pq.pop();

	for (int i = 0; i < vec.size(); i++)
		pq.push(vec[i]);
}

void print()
{
	while (!pq_remove.empty() && !pq.empty() && pq.top() == pq_remove.top())
	{
		pq.pop();
		pq_remove.pop();
	}

	cout << pq.top() << endl;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long query, v;
		cin >> query;
		
		if (query == 1 || query == 2)
			cin >> v;

		if (query == 1)
			pq.push(v);
		if (query == 2)
			pq_remove.push(v);
		if (query == 3)
		{
			print();
		}
	}

	return 0;
}