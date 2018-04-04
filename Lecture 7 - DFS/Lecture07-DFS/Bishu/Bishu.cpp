#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
using namespace std;
#define MAX 1005
int V;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];
int dist[MAX];


void DFS(int src)
{
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		path[i] = -1;
	}
	stack<int> s;
	visited[src] = true;
	dist[src] = 0;
	s.push(src);
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];

			if (!visited[v])
			{
				visited[v] = true;
				s.push(v);
				dist[v] = dist[u] + 1;
				path[v] = u;
			}
		}
	}
}
int main()
{
	//freopen("INPUT.INP", "rt", stdin); 
	int E, u, v;
	cin >> V;
	E = V - 1;
	for (int i = 0; i<E; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);
	int Q;
	cin >> Q;
	int mini = MAX; int index;

	while (Q--) {
		int u;
		cin >> u;

		if (mini > dist[u]) {
			mini = dist[u];
			index = u;
		}
	}

	cout << index;
	return 0;
}