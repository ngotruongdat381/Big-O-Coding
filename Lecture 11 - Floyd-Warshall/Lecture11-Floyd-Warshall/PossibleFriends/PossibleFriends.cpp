#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX  1005
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
				if (dist[i][j] == INF && dist[i][k] != INF && dist[i][k] != 2 
					&& dist[k][j] != INF && dist[k][j] != 2)
				{
					dist[i][j] = 2;
					path[i][j] = path[k][j];
				}
			}
		}
	}

}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int T;
	cin >> T;

	for (int iT = 0; iT < T; iT++)
	{
		string firstInput;
		cin >> firstInput;
		
		int temp;
		n = firstInput.size();
		
		graph = vector<vector<int>>(n, vector<int>(n));
		dist = vector<vector<int>>(n, vector<int>(n));
		path = vector<vector<int>>(n, vector<int>(n));


		for (int j = 0; j < n; j++)
		{
			if (firstInput[j] == 'N' && 0 != j)
				graph[0][j] = INF;
			else
				graph[0][j] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			string input;
			cin >> input;

			for (int j = 0; j < n; j++)
			{
				if (input[j] == 'N' && i != j)
					graph[i][j] = INF;
				else
					graph[i][j] = 1;
			}
		}

		FloydWarshall(graph, dist);

		int ID = 0;
		int maxPF = 0;
		for (int i = 0; i < n; i++)
		{
			int count = 0;
			for (int j = 0; j < n; j++)
			{
				if (path[i][j] != -1 && path[i][j] != i)
				{
					count++;
				}
			}

			if (count > maxPF)
			{
				maxPF = count;
				ID = i;
			}
		}

		cout << ID << " " << maxPF << endl;

	}


	return 0;

}