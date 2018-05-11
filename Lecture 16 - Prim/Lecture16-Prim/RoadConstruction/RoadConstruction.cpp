#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
#include <map>
using namespace std;

#define MAX 105
const int INF = 1e7;

vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, m;
map <string, int> my_map;


void Prim(int src)
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
		visited[i] = false;
		path[i] = -1;
	}

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;

		for (int i = 0; i < graph[u].size(); i++)
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

	int res = 0;
	for (int i = 1; i <= N; i++)
		res += dist[i];

	if (res >= INF) {
		cout << "Impossible\n";
	}
	else {
		cout << res << endl;
	}
}


int main()
{
	freopen("INPUT.INP" , "r" , stdin);
	int test;
	cin >> test;
	int t = test;

	while (test--) {
		cout << "Case " << t - test << ": ";
		cin >> m;

		my_map.clear();
		N = 0;

		for (int i = 1; i <= 2 * m; i++)
			graph[i].clear();

		for (int i = 1; i <= m; i++) {
			string s1, s2;
			int w;

			cin >> s1 >> s2 >> w;
			if (my_map.find(s1) == my_map.end()) {
				my_map[s1] = ++N;
			}

			if (my_map.find(s2) == my_map.end()) {
				my_map[s2] = ++N;
			}

			int u = my_map[s1];
			int v = my_map[s2];
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}
		Prim(1);
	}
	return 0;
}