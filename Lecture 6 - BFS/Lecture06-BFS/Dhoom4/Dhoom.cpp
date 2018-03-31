#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;


#define MAX 100001
bool visited[MAX];
int path[MAX];
int countStep[MAX];				//Extra counting stuff

int key[1001];
int samarpit, lock, n;


bool BFSNewVersion(int s, int f)
{
	queue<int> q;
	visited[s] = true;
	q.push(s);
	countStep[s] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			long long value = ((long long)u*(long long)key[i]);
			int v = value % 100000;
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				path[v] = u;
				countStep[v] = countStep[u] + 1;
				if (v == f)
					return true;
			}
		}
	}
	return false;
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	cin >> samarpit >> lock >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> key[i];
	}
	//memset(countStep, -1, sizeof(countStep));

	

	if (BFSNewVersion(samarpit, lock))
		cout << countStep[lock] << endl;
	else
		cout << -1 << endl;
	
	return 0;
}