#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX 200

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
	//freopen("INPUT.INP", "rt", stdin);
	int n, e, t, m;
	cin >> n >> e >> t >> m;

	dist = vector<int>(MAX, INF);
	graph = vector < vector<pair<int, int>>>(MAX + 1, vector<pair<int, int>>());

	for (int i = 0; i < m; i++)
	{
		int s, f, d;
		cin >> s >> f >> d;
		graph[f].push_back(pair<int, int>(s, d));
	}

	Dijkstra(e, graph);

	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] <= t)
			count++;
	}
	cout << count << endl;

	return 0;
}