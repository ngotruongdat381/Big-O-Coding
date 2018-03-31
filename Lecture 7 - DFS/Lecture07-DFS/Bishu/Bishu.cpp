#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;


#define MAX 1001
int V, E;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];

char c[25][25];
int m, n;

void clear(int v)
{
	for (int i = 1; i <= v; i++)
	{
		visited[i] = false;
		path[i] = -1;
		graph[i].clear();
	}


}
void BFS(int s)
{
	for (int i = 1; i <= V; i++)
	{
		visited[i] = false;
		path[i] = -1;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
				path[v] = u;
			}
		}
	}
}

int steps(int s, int f)
{
	if (s == f)
		return 0;
	else
	{
		if (path[f] == -1)
			return -1;
		else
		{
			int step = steps(s, path[f]);
			if (step == -1)
				return -1;
			else
				return 1 + step;
		}
	}
}

bool checkEntryAndExit(int xs, int ys, int xf, int yf)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (c[i][0] == '.')
		{
			xs = i;
			ys = 0;
			count++;
		}

		if (c[i][m - 1] == '.')
		{
			xs = i;
			ys = m - 1;
			count++;
		}
	}

	for (int i = 0; i < m; i++)
	{
		if (c[0][i] == '.')
		{
			xs = 0;
			ys = i;
			count++;
		}

		if (c[n - 1][i] == '.')
		{
			xs = n - 1;
			ys = i;
			count++;
		}
	}

	if (count = 2)
		return true;
	return false;
}

bool findTheWay(int xs, int ys, int xf, int yf)
{
	if (xs == xf && ys == yf)
		return true;
	bool a = findTheWay(min(xs + 1, n), ys, xf, yf);
	bool b = findTheWay(max(xs - 1, 0), ys, xf, yf);
	bool c = findTheWay(xs, min(ys + 1, m), xf, yf);
	bool d = findTheWay(xs, min(ys - 1, 0), xf, yf);

	return a || b || c || d;
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int t;
	cin >> t;
	for (int it = 0; it < t; it++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> c[i][j];

			}
		}

		int xs, ys, xf, yf;

		if (!checkEntryAndExit(xs, ys, xf, yf))
		{
			cout << "invalid" << endl;
			continue;
		}


	}
	return 0;
}