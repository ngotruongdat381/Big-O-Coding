#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <functional>

using namespace std;
#define MAX 105

const int INF = 1e7;
vector<pair<int, double> > graph[MAX];
vector<double> dist(MAX, INF);
vector<int> path(MAX, -1);
bool visited[MAX];
int N;
double x[MAX], y[MAX];

int getDistance(int i, int j)
{
	return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}

double result()
{
	double ans = 0;
	for (int i = 0; i<N; i++)
	{
		ans += sqrt(dist[i]);
		if (ans >= INF)
		{
			return -1;
		}
	}
	return ans;
}

void prims(int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i<graph[u].size(); i++)
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

void ResetGraph()
{
	for (int i = 0; i < N; i++)
	{
		graph[i].clear();
		visited[i] = false;
		dist[i] = INF;
		path[i] = -1;
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			double a, b;
			cin >> a >> b;
			x[i] = a;
			y[i] = b;
		}

		for (int i = 0; i<N - 1; i++)
		{
			for (int j = i + 1; j<N; j++)
			{
				int w = getDistance(i, j);
				graph[i].push_back(make_pair(j, w));
				graph[j].push_back(make_pair(i, w));
			}
		}
		prims(0);
		double r = result();
		printf("%0.2f\n", r);
		ResetGraph();
	}
	return 0;
}