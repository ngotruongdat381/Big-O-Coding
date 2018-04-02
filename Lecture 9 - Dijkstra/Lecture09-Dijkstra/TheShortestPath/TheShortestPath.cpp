#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include<string>

using namespace std;

#define MAX 11111
const long long INF = 1e9;

vector < vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];
string name[MAX];
int s, n, p, nr, cost, r;
string NAME, NAME1, NAME2;


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

int checkName(string name_)
{
	for (int i = 1; i <= n; i++)
	{
		if (name[i] == name_)
			return i;
	}
	return -1;
}

int main()
{
	//freopen("INPUT.INP", "rt", stdin);
	cin >> s;

	for (int is = 0; is < s; is++)
	{
		graph = vector < vector<pair<int, int>>>(MAX + 1, vector<pair<int, int>>());
		std::fill(name, name + n + 1, 0);

		cin >> n;		//number of cities
		for (int in = 1; in <= n; in++)
		{
			cin.ignore(1);
			getline(cin, NAME);	
			name[in] = NAME;

			cin >> p;//number of neighbors

			for (int ip = 0; ip < p; ip++)
			{
				cin >> nr >> cost;
				graph[in].push_back(pair<int, int>(nr, cost));
			}

		}

		cin >> r;
		for (int ir = 0; ir < r; ir++)
		{
			std::fill(path, path + n + 1, 0);
			dist = vector<int>(MAX, INF);

			cin.ignore(1);
			cin >> NAME1;
			cin >> NAME2;

			int start = checkName(NAME1);
			int end = checkName(NAME2);

			Dijkstra(start, graph);
			cout << dist[end] << endl;
		}
	}

	return 0;
}