#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <string>
#include<math.h>
using namespace std;

#define MAX  1005
#define INF  1e9


vector<vector<int>> graphY;
vector<vector<int>> graphM;
vector<vector<int>> distY;
vector<vector<int>> distM;
int v[150];
vector<char> minPoint[2000];

int n;

void FloydWarshall(vector<vector<int>> &graph, vector<vector<int>> &dist)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			dist[i][j] = graph[i][j];
			//if (graph[i][j] != INF && i != j)
			//{
			//	path[i][j] = i;
			//}
			//else
			//{
			//	path[i][j] = -1;
			//}
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
					//path[i][j] = path[k][j];
				}
			}
		}
	}

}


void ResetGraph()
{
	graphY = vector<vector<int>>(26, vector<int>(26));
	graphM = vector<vector<int>>(26, vector<int>(26));
	distY = vector<vector<int>>(26, vector<int>(26));
	distM = vector<vector<int>>(26, vector<int>(26));
	//path = vector<vector<int>>(26, vector<int>(26));

	std::fill_n(v, 150, -1);
	std::fill_n(minPoint, 2000, vector<char>());

	for (int i = 0; i < 26; i++)
	for (int j = 0; j < 26; j++)
		{
			graphY[i][j] = INF;
			graphM[i][j] = INF;

			if (i == j)
			{
				graphY[i][j] = 0;
				graphM[i][j] = 0;
			}
		}
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
			return 0;

		ResetGraph();

		int index = 0;

		for (int i = 0; i < N; i++)
		{
			char ageType, directionType;
			cin >> ageType >> directionType;
			
			char S, T;
			cin >> S >> T;

			if (v[S] == -1)
			{
				v[S] = index;
				index++;
			}
			
			if (v[T] == -1)
			{
				v[T] = index;
				index++;
			}
			
			int w;
			cin >> w;

			if (S != T)
			{
				if (ageType == 'Y')
				{
					graphY[v[S]][v[T]] = w;
					if (directionType == 'B')
					{
						graphY[v[T]][v[S]] = w;
					}
				}
				else
				{
					graphM[v[S]][v[T]] = w;
					if (directionType == 'B')
					{
						graphM[v[T]][v[S]] = w;
					}
				}
			}
		}

		int count = 0;
		for (int i = 'A'; i <= 'Z'; i++)
		{
			if (v[i] > -1)
			{
				count++;
			}
		}

		n = count;

		FloydWarshall(graphM, distM);
		FloydWarshall(graphY, distY);

		char s, t;
		cin >> s >> t;

		int minDistance = INF;
		char minV;

		if (v[s] != -1 && v[t] != -1)
		{
			for (int i = 'A'; i <= 'Z'; i++)
			{
				if (v[i] > -1)
				{
					int sum = distY[v[s]][v[i]] + distM[v[t]][v[i]];
					if (sum != INF && sum <= minDistance)
					{
						minDistance = distY[v[s]][v[i]] + distM[v[t]][v[i]];
						minPoint[minDistance].push_back(i);
						//minV = i;
					}
				}

			}
		}

		if (minDistance == INF)
		{
			cout << "You will never meet." << endl;
		}
		else
		{
			cout << minDistance;
			
			for (int i = 0; i < minPoint[minDistance].size(); i++)
			{
				cout << " " << minPoint[minDistance][i];
			}
			cout << endl;
		}
				
	}

	return 0;

}