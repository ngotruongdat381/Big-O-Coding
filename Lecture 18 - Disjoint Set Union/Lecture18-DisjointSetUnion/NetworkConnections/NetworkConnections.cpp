#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


#define MAX 1111
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
	freopen("INPUT.INP", "rt", stdin);
	int T;
	cin >> T;

	int n, x, y, success, unsuccess;

	string q;

	//input n for the 1st time
	cin >> n;
	int t;
	for (t = 0; t < T; t++)
	{
		success = unsuccess = 0;

		for (int i = 1; i <= n; i++)
			parent[i] = i;

		while (cin >> q)
		{			
			if (isalpha(q[0]))
			{
				cin >> x >> y;

				if (q == "c")
					unionSet(x, y);

				if (q == "q")
				{
					int parentX = findSet(x);
					int parentY = findSet(y);
					if (parentX == parentY)
						success++;
					else
						unsuccess++;
				}

			}
			else
			{
				n = stoi(q);
				break;
			}
		}

		cout << success << "," << unsuccess << endl;
		if (t < T - 1)
			cout << endl;

	}

	return 0;
}