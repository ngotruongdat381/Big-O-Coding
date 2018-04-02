#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include<string>

using namespace std;

#define MAX 20009
const long long INF = 1e9;

vector < vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];
int N, n, m, S, T;



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
	cin >> N;

	for (int iN = 1; iN <= N; iN++)
	{

		cin >> n >> m >> S >> T;		

		graph = vector < vector<pair<int, int>>>(MAX + 1, vector<pair<int, int>>());
		std::fill(path, path + n + 1, 0);
		dist = vector<int>(MAX, INF);


		for (int im = 0; im < m; im++)
		{
			int s, f, w;
			cin >> s >> f >> w;
			graph[f].push_back(pair<int, int>(s, w));
			graph[s].push_back(pair<int, int>(f, w));
		}

		Dijkstra(S, graph);

		cout << "Case #" << iN << ": ";

		if (dist[T] == INF)
			cout << "unreachable" << endl;
		else
			cout << dist[T] << endl;
	}

	return 0;
}