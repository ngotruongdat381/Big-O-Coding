#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


#define MAX 30005
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

	int N, M, x, y;

	string q;

	int t;
	for (t = 0; t < T; t++)
	{
		cin >> N >> M;

		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
			c[i] = 1;
		}
			
		for (int i = 1; i <= M; i++)
		{
			cin >> x >> y;
			unionSet(x, y);
		}

		int maxi = 0;
		for (int i = 1; i <= N; i++)
		{
			maxi = max(maxi, c[i]);
		}

		cout << maxi << endl;
	}

	return 0;
}