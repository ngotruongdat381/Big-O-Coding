#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
using namespace std;
#define MAX 100000
int V;
bool visited[MAX];
int path[MAX];
vector<int> graph[MAX];


void DFS(int src)
{
	stack<int> s;
	visited[src] = true;
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
				path[v] = u;
			}
		}
	}
}
int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T = 0;
	cin >> T;
	while (T--)
	{
		int E, u, v;
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int count = 0;

		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
			path[i] = -1;
		}

		for (int i = 0; i < V; i++)
		{
			if (visited[i] == false)
			{
				DFS(i);
				count++;
			}
		}
		cout << count << endl;
		for (int i = 0; i < V; i++)
			graph[i].clear();
	}
	return 0;

}