#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


#define MAX 1111111
int parent[MAX];

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
	parent[vp] = up;
}

int main()
{
	int q, x, y, z;
	cin >> q;
	for (int i = 1; i <= MAX; i++)
		parent[i] = i;

	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y >> z;
		if (z == 1)
		{
			unionSet(x, y);
		}

		if (z == 2)
		{
			int parentX = findSet(x);
			int parentY = findSet(y);
			if (parentX == parentY)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}
	return 0;
}