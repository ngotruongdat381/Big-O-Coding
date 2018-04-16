#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <iomanip>
#include<math.h>
using namespace std;

#define MAX  1005
#define INF  1e9


struct Point
{
	int x;
	int y;
};


vector<vector<double>> graph;
vector<vector<double>> dist;
vector<vector<int>> path;
vector<Point> locations;


int n;

void printPath(int s, int t)
{
	int b[MAX];
	int m = 0;

	while (s != t)
	{
		b[m++] = t;
		t = path[s][t];
	}
	b[m++] = s;

	for (int i = m - 1; i >= 0; i--)
	{
		cout << b[i] << " ";
	}

}

void FloydWarshall(vector<vector<double>> &graph, vector<vector<double>> &dist)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			dist[i][j] = graph[i][j];
			if (graph[i][j] != INF && i != j)
			{
				path[i][j] = i;
			}
			else
			{
				path[i][j] = -1;
			}
		}
	}

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}

}


void ResetGraph()
{
	graph = vector<vector<double>>(n, vector<double>(n));
	dist = vector<vector<double>>(n, vector<double>(n));
	path = vector<vector<int>>(n, vector<int>(n));
	locations = vector<Point>();

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		graph[i][j] = INF;

	}
}


double Distance(Point x, Point y)
{
	return pow((x.x - y.x)*(x.x - y.x) + (x.y - y.y)*(x.y - y.y), 0.5);
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int N;
	cin >> N;
	int T = 0;

	for (int iN = 0; iN < N; iN++)
	{
		cin >> n;

		ResetGraph();

		for (int i = 0; i < n; i++)
		{
			Point tmp;
			cin >> tmp.x >> tmp.y;
			locations.push_back(tmp);
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				double d = Distance(locations[i], locations[j]);

				if (d <= 10)
				{
					graph[i][j] = d;
					graph[j][i] = d;
				}
				else
				{
					graph[i][j] = INF;
					graph[j][i] = INF;
				}
			}
		}

		FloydWarshall(graph, dist);

		
		double max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][j] > max)
				{
					max = dist[i][j];
				}
			}
		}

		T++;
		cout << "Case #" << T << ":" << endl;
		if (max != INF)
		{
			std::cout << std::fixed;
			std::cout << std::setprecision(4);
			cout << max << endl;
		}
		else
			cout << "Send Kurdy" << endl;
		cout << endl;
	}

	return 0;

}