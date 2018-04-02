#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;


struct topic
{
	int ID;
	long long z_new;
	long long z_change;


	bool operator() (const topic &a, const topic &b) const
	{
		return a.z_change > b.z_change || (a.z_change == b.z_change && a.ID < b.ID);
	}
};


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	int ID;
	long long Z, P, L, C, S;
	cin >> n;
	priority_queue<topic, vector<topic>, topic> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> ID >> Z >> P >> L >> C >> S;

		long long z_new = P * 50 + L * 5 + C * 10 + S * 20;
		topic t;
		t.ID = ID;
		t.z_new = z_new;
		t.z_change = Z - z_new;
		pq.push(t);

	}

	for (int i = 0; i < 5 && !pq.empty() ; i++)
	{
		cout << pq.top().ID << " " << pq.top().z_new << endl;
		pq.pop();
	}

	return 0;
}