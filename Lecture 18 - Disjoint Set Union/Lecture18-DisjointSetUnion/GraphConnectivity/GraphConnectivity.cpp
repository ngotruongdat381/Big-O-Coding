#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


#define MAX 30
int parent[MAX];
int c[MAX];
int n;



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

int calculateSubgraph()
{
	for (int i = 1; i <= n; i++)
	{
		int p = findSet(i);
		c[p]++;
	}

	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		if (c[i] > 0)
			sum++;
	}

	return sum;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T;
	cin >> T;
	getchar();

	string str;
	getline(cin, str);

	int t;
	for (t = 0; t < T; t++)
	{
		for (int i = 1; i <= MAX - 1; i++)
		{
			parent[i] = i;
			c[i] = 0;
		}
		
		while (getline(cin, str))
		{
			if (str.size() == 0)
				break;

			if (str.size() == 1)
				n = str[0] - 65 + 1;
			else
				unionSet(str[0] - 64, str[1] - 64);
		}

		cout << calculateSubgraph() << endl;
		if (t < T - 1)
			cout << endl;
	}

	return 0;
}