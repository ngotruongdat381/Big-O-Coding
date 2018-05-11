#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>
#include <map>

using namespace std;

const int MAX_N = 105;

int dist[MAX_N];
bool mark[MAX_N][MAX_N][3 * MAX_N];

struct edge {
	int u, v, c;
};

vector <edge> save, tmp;
vector <pair <int, int> > V[MAX_N];
bool visited[MAX_N];
int path[MAX_N];
int n, m, test;
int cnt[MAX_N];

const int inf = 1e8;

int Prim(int source, vector <edge> &save) {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
		visited[i] = false;
		path[i] = -1;
	}

	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;

	pq.push(make_pair(0, source));

	dist[source] = 0;

	while (!pq.empty()) {
		pair <int, int> K = pq.top();
		pq.pop();

		int u = K.second;
		visited[u] = true;

		for (int i = 0; i < V[u].size(); i++) {
			pair <int, int> K = V[u][i];

			int v = K.first;
			int c = K.second;

			if (visited[v]) continue;
			if (mark[u][v][c]) continue;
			if (dist[v] <= c) continue;

			dist[v] = c;
			path[v] = u;

			pq.push(make_pair(c, v));
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i++)
		if (dist[i] == inf) return -1;

	for (int i = 1; i <= n; i++) res += dist[i];

	for (int i = 1; i <= n; i++) {
		int u = path[i];

		if (u != -1)
		{
			edge temp;
			temp.u = u;
			temp.v = i;
			temp.c = dist[i];
			save.push_back(temp);
		}
	}

	return res;
}

int main() {
	scanf("%d", &test);

	while (test--) {
		for (int i = 1; i < MAX_N; i++)
			for (int j = 1; j < MAX_N; j++)
				for (int x = 1; x < 3 * MAX_N; x++) mark[i][j][x] = false;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) V[i].clear();

		while (m--) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			cnt[u]++;
			cnt[v]++;

			V[u].push_back(make_pair(v, c));
			V[v].push_back(make_pair(u, c));
		}

		save.clear();

		int mini0 = Prim(1, save);

		printf("%d ", mini0);

		int mini = inf;

		for (int i = 0; i < save.size(); i++) {
			int u = save[i].u;
			int v = save[i].v;
			int c = save[i].c;

			mark[u][v][c] = mark[v][u][c] = true;
			cnt[u]--; cnt[v]--;

			tmp.clear();

			int x;

			for (int i = 1; i <= n; i++)
				if (cnt[i]) {
					x = i;
					break;
				}

			int K = Prim(x, tmp);

			if (K >= 0) mini = min(mini, K);

			mark[u][v][c] = mark[v][u][c] = false;
			cnt[u]++; cnt[v]++;
		}

		if (mini == inf) mini = mini0;

		printf("%d\n", mini);
	}
	return 0;
}