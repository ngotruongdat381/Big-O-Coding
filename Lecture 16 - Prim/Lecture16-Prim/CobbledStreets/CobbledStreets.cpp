#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
using namespace std;

#define MAX 1005
const int INF = 1e9;

vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N;

void printMST()
{
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (path[i] == -1)
			continue;
		ans += dist[i];
		//cout << path[i] << " - " << i << ": " << dist[i] << endl;
	}
	cout << ans << endl;
}

int getMST()
{
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (path[i] == -1)
			continue;
		ans += dist[i];
	}
	return ans;
}


void Prim(int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;

		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w)
			{
				dist[v] = w;
				pq.push(make_pair(w, v));
				path[v] = u;
			}
		}
	}
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int t, p, M, u, v, w;
	cin >> t;
	while (t--)
	{
		cin >> p >> N >> M;

		memset(path, -1, sizeof(path));
		for (int i = 0; i < N; i++) {
			graph[i].clear();
			visited[i] = false;
			dist[i] = INF;
		}

		for (int i = 0; i < M; i++)
		{
			cin >> u >> v >> w;
			graph[u - 1].push_back(make_pair(v - 1, w));
			graph[v - 1].push_back(make_pair(u - 1, w));
		}

		int s = 0;
		Prim(s);
		cout << getMST() * p << endl;
	}

	return 0;
}