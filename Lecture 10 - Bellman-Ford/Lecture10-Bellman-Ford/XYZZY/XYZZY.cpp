#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

#define MAX 40005
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
int busyness[MAX];
int n, m;

bool negativeLoop[MAX];

bool BellmanFord(int s, vector<triad> &graph)
{
	int u, v, w;
	dist[s] = 0;

	for (int i = 1; i <= n - 1; i++)
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

	////Check negative cycle

	//for (int j = 0; j < m; j++)
	//{
	//	u = graph[j].s;
	//	v = graph[j].t;
	//	w = graph[j].w;

	//	if (dist[u] != INF && (dist[u] + w < dist[v]))
	//	{
	//		//return false;
	//		negativeLoop[u] = true;
	//		negativeLoop[v] = true;
	//	}
	//		
	//}

	return true;
}

void clear()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		path[i] = -1;
		negativeLoop[i] = false;
	}
	//dist = vector<int>(n, INF);
	graph.clear();
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		int n;
		cin >> n;

		if (n == -1)
		{
			return 0;
		}

		for (int in = 1; in <= n; in++)
		{
			int w, nDoors;
			cin >> w >> nDoors;

			for (int idoor = 0; idoor < nDoors; idoor++)
			{
				triad tmp;
				tmp.s = in;
				tmp.w = w;
				cin >> tmp.t;

			}
		}
		
		cout << "Case " << iT << ":" << endl;
		cin >> n;
		clear();

		for (int i = 1; i <= n; i++)
			cin >> busyness[i];

		cin >> m;

		for (int i = 0; i < m; i++)
		{
			triad temp;
			cin >> temp.s >> temp.t;
			temp.w = pow((busyness[temp.t] - busyness[temp.s]), 3);
			graph.push_back(temp);
		}
		bool possible = BellmanFord(1, graph);

		int q;
		cin >> q;

		for (int i = 0; i < q; i++)
		{
			int t;
			cin >> t;

			if (dist[t] < 3 || dist[t] == INF)
				cout << "?" << endl;
			else
				cout << dist[t] << endl;
		}
	}

	return 0;
}