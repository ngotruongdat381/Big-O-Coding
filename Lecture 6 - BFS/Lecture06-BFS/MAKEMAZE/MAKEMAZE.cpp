#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;


#define MAX 25
bool visited[MAX][MAX];
char maze[MAX][MAX];
int m, n;

//Direction
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


struct Point
{
	int x, y;
	Point(int a = 0, int b = 0)
	{
		x = a;
		y = b;
	};
};


bool BFS2DChecking(Point s, Point f)
{
	//for (int i = 1; i <= V; i++)
	//{
	//	visited[i.x][i.y] = false;
	//	path[i] = -1;
	//}

	queue<Point> q;
	visited[s.x][s.y] = true;
	q.push(s);

	while (!q.empty())
	{
		Point u = q.front();
		q.pop();
		//for (int i = 0; i < graph[u].size(); i++)		//we dont use graph[u] here since we know there are only 4 ways of moving
		for (int i = 0; i < 4; i++)
		{
			//int v = graph[u][i];
			int x = u.x + dx[i];
			int y = u.y + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m)		//Check if our moves are inside the maze
			{
				if (!visited[x][y] && maze[x][y] == '.')
				{
					visited[x][y] = true;

					if (x == f.x && y == f.y)
						return true;

					q.push(Point(x, y));
					//path[v] = u;
				}
			}
		}
	}

	return false;
}


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int t;
	cin >> t;
	vector<Point> points;

	for (int it = 0; it < t; it++)
	{
		cin >> n >> m;
		points.clear();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> maze[i][j];

				if (maze[i][j] == '.' && (i == 0 || i == (n - 1) || j == 0 || j == (m - 1)))
				{
					points.push_back(Point(i, j));
				}
				visited[i][j] = false;
			}
		}
		
		if (points.size() == 2 && BFS2DChecking(points[0], points[1]) == true)
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;

	}
	return 0;
}