#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


priority_queue<long long, vector<long long>, greater<long long>> pq;

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

void pop(long long v)
{
	priority_queue<long long, vector<long long>, greater<long long>> tmp;;

	while (v != pq.top())
	{
		tmp.push(pq.top());
		pq.pop();
	}

	pq.pop();

	if (pq.size() > tmp.size())
	{
		while (!tmp.empty())
		{
			pq.push(tmp.top());
			tmp.pop();
		}	
	}
	else
	{
		while (!pq.empty())
		{
			tmp.push(pq.top());
			pq.pop();
		}
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	long long a, b, c = 0;


	for (int i = 0; i < n; i++)
	{
		long query, v;
		cin >> query;
		
		if (query == 1 || query == 2)
			cin >> v;

		if (query == 1)
			pq.push(v);
		if (query == 2)
			pop(v);
		if (query == 3)
			cout << pq.top() << endl;
		
	}

	return 0;
}