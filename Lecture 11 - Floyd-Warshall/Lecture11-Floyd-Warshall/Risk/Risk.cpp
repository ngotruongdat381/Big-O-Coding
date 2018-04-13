#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
using namespace std;

#define MAX  20
#define INF  1e9

vector<vector<int>> graph;
vector<vector<int>> dist;
vector<vector<int>> path;

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

void FloydWarshall(vector<vector<int>> &graph, vector<vector<int>> &dist)
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
	graph = vector<vector<int>>(n, vector<int>(n));
	dist = vector<vector<int>>(n, vector<int>(n));
	path = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = INF;
			
		}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int t = 0;
	

	while (true)
	{
		n = 20;

		ResetGraph();

		for (int I = 0; I < 19; I++)
		{
			int X;

			if (!(cin >> X))
			{
				return 0;
			}

			for (int iX = 0; iX < X; iX++)
			{
				int J;
				cin >> J;
				graph[I][J - 1] = 1;
				graph[J - 1][I] = 1;
			}
		}

		FloydWarshall(graph, dist);

		t++;
		cout << "Test Set #" << t << endl;

		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int A;
			int B;

			cin >> A;
			cin >> B;
			int result = dist[A - 1][B - 1];

			if (A < 10)
				cout << " ";

			cout << A;
			cout << " to ";
			
			if (B < 10)
				cout << " ";

			cout << B << ": ";

			cout << result << endl;
		}
		cout << endl;
	}

	return 0;

}