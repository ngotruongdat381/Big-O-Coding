#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 55;

int n, m, k;
char a[MAX_N][MAX_N];
char b[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

struct point {
	int x, y, c;

	bool operator < (const point &hs) const {
		return (c < hs.c);
	}
};

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

vector <point> res;
int cnt;

bool BFS2DChecking(point s, point f)
{
	//for (int i = 1; i <= V; i++)
	//{
	//	visited[i.x][i.y] = false;
	//	path[i] = -1;
	//}

	queue<point> q;
	//a[s.x][s.y] = 'x';
	visited[s.x][s.y] = true;
	q.push(s);

	while (!q.empty())
	{
		point u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = u.x + dx[i];
			int y = u.y + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m)		//Check if our moves are inside the maze
			{
				if (!visited[x][y] && a[x][y] != 'x')
				{
					visited[x][y] = true;

					if (x == f.x && y == f.y)
						return true;

					q.push(point(x, y));
					//path[v] = u;
				}
			}
		}
	}

	return false;
}


void DFS_recursion(int x, int y) {
	a[x][y] = '*';
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nxtx = x + dx[i];
		int nxty = y + dy[i];

		if (nxtx >= 1 && nxtx <= n && nxty >= 1 && nxty <= m && a[nxtx][nxty] == '.') 
			DFS_recursion(nxtx, nxty);
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int R, C;

	int nr;

	while (true)
	{
		cin >> R >> C;

		if (R == 0 && C == 0)
			return 0;

		cin >> nr;
		int row, nc, col;

		for (int ir = 0; ir < nr; ir++)
		{
			cin >> row >> nc;

			for (int ic = 0; ic < nc; ic++)
			{
				cin >> col;
				a[row][col] = 'x';
			}

		}

	}


	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') {
				cnt = 0;
				DFS(i, j);
				point temp;
				temp.x = i;
				temp.y = j;
				temp.c = cnt;
				res.push_back(temp);
			}
		}
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		a[i][j] = b[i][j];

	sort(res.begin(), res.end());

	int d = res.size() - k;

	int sum = 0;

	for (int i = 0; i < d; i++) {
		sum += res[i].c;

		DFS(res[i].x, res[i].y);
	}

	cout << sum << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;

}