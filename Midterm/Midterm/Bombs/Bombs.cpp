#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_N = 1005;
int a[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int countStep[MAX_N][MAX_N];

int R, C;


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
	queue<point> q;
	//a[s.x][s.y] = 'x';
	visited[s.x][s.y] = true;
	q.push(s);
	countStep[s.x][s.y] = 0;

	while (!q.empty())
	{
		point u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = u.x + dx[i];
			int y = u.y + dy[i];

			if (x >= 0 && x < R && y >= 0 && y < C)		//Check if our moves are inside the maze
			{
				if (!visited[x][y] && a[x][y] != 1)
				{
					visited[x][y] = true;
					countStep[x][y] = countStep[u.x][u.y] + 1;

					if (x == f.x && y == f.y)
						return true;
					
					point temp;
					temp.x = x;
					temp.y = y;

					q.push(temp);
					
				}
			}
		}
	}

	return false;
}

void clear()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			visited[i][j] = false;
			a[i][j] = 0;
			countStep[i][j] = 0;
		}
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	

	int nr;

	while (true)
	{
		cin >> R >> C;

		if (R == 0 && C == 0)
			return 0;

		clear();

		cin >> nr;
		int row, nc, col;

		for (int ir = 0; ir < nr; ir++)
		{
			cin >> row >> nc;

			for (int ic = 0; ic < nc; ic++)
			{
				cin >> col;
				a[row][col] = 1;
			}

		}

		point s, f;
		cin >> s.x >> s.y >> f.x >> f.y;

		BFS2DChecking(s, f);

		cout << countStep[f.x][f.y] << endl;
	}
	return 0;

}