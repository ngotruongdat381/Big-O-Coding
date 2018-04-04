#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 55;

int n, m, k;
char a[MAX_N][MAX_N];
char b[MAX_N][MAX_N];

struct point {
	int x, y, c;

	bool operator < (const point &hs) const {
		return (c < hs.c);
	}
};

int dx[] = { 0 , 0 , -1 , 1 };
int dy[] = { 1 , -1 , 0 , 0 };

vector <point> res;
int cnt;

void DFS(int x, int y)
{
	cnt++;

	stack<point> s;
	a[x][y] = '*';

	point temp;
	temp.x = x;
	temp.y = y;

	s.push(temp);
	while (!s.empty())
	{
		point u = s.top();
		s.pop();

		for (int i = 0; i < 4; i++)
		{
			point v;
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];

			if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m &&a[v.x][v.y] == '.')
			{
				cnt++;
				a[v.x][v.y] = '*';
				s.push(v);

			}
		}
	}
}

void DFS_recursion(int x, int y) {
	a[x][y] = '*';
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nxtx = x + dx[i];
		int nxty = y + dy[i];

		if (nxtx >= 1 && nxtx <= n && nxty >= 1 && nxty <= m && a[nxtx][nxty] == '.') DFS_recursion(nxtx, nxty);
	}
}

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == '.') 
			DFS(i, 0);

		if (a[i][m - 1] == '.') 
			DFS(i, m - 1);
	}

	for (int j = 0; j < m; j++) 
	{
		if (a[0][j] == '.') 
			DFS(0, j);
		
		if (a[n - 1][j] == '.') 
			DFS(n, j);
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