#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;


#define MAX 200005
int parent[MAX];
int c[MAX];

int findSet(int u)
{
	while (u != parent[u])
		u = parent[u];
	return u;
}

void unionSet(int u, int v)
{
	int up = findSet(u);
	int vp = findSet(v);
	if (up != vp)
	{
		parent[vp] = up;
		c[up] = c[up] + c[vp];
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T;
	cin >> T;

	int F, M, x, y;

	string friendA, friendB;

	int t;
	for (t = 0; t < T; t++)
	{

		cin >> F;

		int no = 1;
		map<string, int> m;
		map<string, int>::iterator it;

		for (int i = 1; i <= F*2; i++)
		{
			parent[i] = i;
			c[i] = 1;
		}

		for (int i = 1; i <= F; i++)
		{
			cin >> friendA >> friendB;

			it = m.find(friendA);
			if (it == m.end())
				m[friendA] = no++;
				

			it = m.find(friendB);
			if (it == m.end())
				m[friendB] = no++;

			unionSet(m[friendA], m[friendB]);

			cout << c[findSet(m[friendA])] << endl;
		}

	}

	return 0;
}