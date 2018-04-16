#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

#define MAX 10005
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
int energyLoss[MAX];
int n, m;

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

			if (dist[u] != INF && (dist[u] + w < dist[v]) && (dist[u] + w < 100))
			{
				dist[v] = dist[u] + w;
				path[v] = u;
			}
		}
	}

	//Check negative cycle
	//Continue update dist and path with less conditions than before
	bool res = true;

	for (int j = 0; j < m; j++)
	{
		u = graph[j].s;
		v = graph[j].t;
		w = graph[j].w;

		if (dist[u] != INF && (dist[u] + w < dist[v]))
		{
			res = false;
			dist[v] = dist[u] + w;
			path[v] = u;
		}
	}

	return res;
}

void clear()
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
		path[i] = -1;
	}
	//dist = vector<int>(n, INF);
	graph.clear();
}

bool checkOutOfEnergy(int f)
{
	if (f == 1)
		return true;

	if (dist[f] >= 100)
	{
		return false;
	}
	else
	{
		checkOutOfEnergy(path[f]);
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		cin >> n;
		if (n == -1)
			return 0;

		clear();

		for (int in = 1; in <= n; in++)
		{
			int eLoss;
			cin >> eLoss;

			energyLoss[in] = -eLoss;
			
			int nDoor;
			cin >> nDoor;

			for (int idoor = 0; idoor < nDoor; idoor++)
			{
				triad tmp;
				tmp.s = in;
				cin >> tmp.t;
				if (tmp.t > n)
					continue;
				graph.push_back(tmp);
			}

		}

		m = graph.size();

		for (int i = 0; i < graph.size(); i++)
			graph[i].w = energyLoss[graph[i].t];

		bool possible = BellmanFord(1, graph);
		
		if (possible)
		{
			bool winnable = checkOutOfEnergy(n);
			if (winnable)
				cout << "winnable" << endl;
			else
				cout << "hopeless" << endl;
		}
		else
		{
			if (dist[n] == INF)
				cout << "hopeless" << endl;
			else
				cout << "winnable" << endl;
		}
			
	}

	return 0;
}