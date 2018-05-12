#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


#define MAX 50005
int parent[MAX];
int check[MAX];

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

	int N, count = 1;

	long long M;
	int friendA, friendB;

	while (true)
	{
		cin >> N >> M;
		if (M == 0 && N == 0)
			return 0;

		cout << "Case " << count++ << ": ";
		
		for (int i = 1; i <= N; i++)
		{
			parent[i] = i;
			check[i] = 0;
		}

		for (long long i = 1; i <= M; i++)
		{
			cin >> friendA >> friendB;
			unionSet(friendA, friendB);
		}

		for (int i = 1; i <= N; i++)
		{
			int parent = findSet(i);
			check[parent]++;
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (check[i] > 0)
				cnt++;
		}
		cout << cnt << endl;

	}

	return 0;
}