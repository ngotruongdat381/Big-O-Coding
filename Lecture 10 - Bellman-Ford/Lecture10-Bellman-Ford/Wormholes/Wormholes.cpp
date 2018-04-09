#include <iostream>
#include <vector>
using namespace std;

#define MAX 2005
const int INF = 1e9;

struct triad
{
	int s;
	int t;
	int w;
};

vector<int> dist(MAX, INF);
vector<triad> graph;
int path[MAX];
int n, m;

bool BellmanFord(int s, vector<triad> &graph)
{
	int u, v, w;
	dist[s] = 0;

	for (int i = 1; i <= n - 1; i++ )
	{
		for (int j = 0; j < m; j++)
		{
			u = graph[j].s;
			v = graph[j].t;
			w = graph[j].w;

			if (dist[u] != INF && (dist[u] + w < dist[v]))
			{
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}

	//Check negative cycle

	for (int j = 0; j < m; j++)
	{
		u = graph[j].s;
		v = graph[j].t;
		w = graph[j].w;

		if (dist[u] != INF && (dist[u] + w < dist[v]))
			return false;
	}

	return true;
}

void clear()
{
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		path[i] = -1;
	}
	//dist = vector<int>(n, INF);
	graph.clear();
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int c;
	cin >> c;

	for (int ic = 0; ic < c; ic++)
	{
		cin >> n >> m;
		clear();
		for (int i = 0; i < m; i++)
		{
			triad temp;
			cin >> temp.s >> temp.t >> temp.w;
			graph.push_back(temp);
		}
		if (BellmanFord(0, graph))
			cout << "not possible" << endl;
		else
			cout << "possible" << endl;

	}

	return 0;
}