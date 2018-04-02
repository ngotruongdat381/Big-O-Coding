#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX 500

const int INF = 1e9;

vector < vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

void Dijkstra(int s, vector<vector<pair<int, int>>> &graph)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(pair<int, int>(0, s));
	dist[s] = 0;

	while (!pq.empty())
	{
		pair<int, int> top = pq.top();
		pq.pop();
		int node = top.second;
		int d = top.first;
		
		for (int i = 0; i < graph[node].size(); i++)
		{
			pair<int, int> neighbor = graph[node][i];
			if (d + neighbor.second < dist[neighbor.first])
			{
				dist[neighbor.first] = d + neighbor.second;
				pq.push(pair<int, int>(dist[neighbor.first], neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}

}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int n;
	cin >> n;

	graph = vector < vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
	for (int i = 0; i < n; i++)
	{
		int s, f, d;
		cin >> s >> f >> d;
		graph[s].push_back(pair<int, int>(f, d));
		graph[f].push_back(pair<int, int>(s, d));
	}

	int u, q;
	cin >> u >> q;

	Dijkstra(u, graph);

	for (int i = 0; i < q; i++)
	{
		int v;
		cin >> v;
		if (dist[v] != INF)
			cout << dist[v] << endl;
		else
			cout << "NO PATH" << endl;
	}

	return 0;
}