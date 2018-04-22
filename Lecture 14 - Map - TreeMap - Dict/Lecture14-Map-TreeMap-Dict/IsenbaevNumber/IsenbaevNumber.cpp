#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

#include <string>
#include <map>
#include <sstream>

using namespace std;

#define MAX 1111
const long long INF = 1e9;

vector < vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];


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

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	dist = vector<int>(MAX, INF);
	graph = vector < vector<pair<int, int>>>(MAX + 1, vector<pair<int, int>>());

		
	int N;
	cin >> N;		
	cin.ignore(1);

	string team;
	int no = 0;
	map<string, int> m;
	map<string, int>::iterator it;
	int s;

	for (int iN = 0; iN < N; iN++)
	{
		getline(cin, team);

		vector<string> players;

		istringstream ss(team);
		string token;
		while (getline(ss, token, ' ')) {
			players.push_back(token);

			it = m.find(token);
			if (it == m.end())
				m[token] = no++;
		}

		int first = m[players[0]];
		int second = m[players[1]];
		int third = m[players[2]];

		graph[first].push_back(pair<int, int>(second, 1));
		graph[second].push_back(pair<int, int>(first, 1));

		graph[first].push_back(pair<int, int>(third, 1));
		graph[third].push_back(pair<int, int>(first, 1));

		graph[second].push_back(pair<int, int>(third, 1));
		graph[third].push_back(pair<int, int>(second, 1));
			
	}

	it = m.find("Isenbaev");
	if (it == m.end())
	{
		for (it = m.begin(); it != m.end(); it++)
		{
			cout << it->first << " " << "undefined" << endl;
		}
	}
	else
	{
		s = m["Isenbaev"];
		Dijkstra(s, graph);

		for (it = m.begin(); it != m.end(); it++)
		{

			cout << it->first << " ";
			if (dist[it->second] == INF)
				cout << "undefined" << endl;
			else
				cout << dist[it->second] << endl;
		}
	}


	return 0;
}