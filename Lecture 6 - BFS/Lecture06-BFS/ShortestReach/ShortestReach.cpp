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
int countStep[MAX];				//Extra counting stuff
vector<int> graph[MAX];

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
		countStep[i] = -1;
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);
	countStep[s] = 0;				

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
				countStep[v] = countStep[u] + 1;
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
void shortestReach(int s)
{
	for (int i = 1; i <= V; i++)
	{
		if (s != i)
		{
			//int step = steps(s, i);
			int step = countStep[i];
			if (step == -1)
				cout << -1 << " ";
			else
				cout << step * 6 << " ";
		}
			
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int q, s;
	cin >> q;
	for (int iq = 0; iq < q; iq++)
	{
		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int start, end;
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		cin >> s;

		BFS(s);
		shortestReach(s);
		cout << endl;

		clear(V);
		
	}
	return 0;
}