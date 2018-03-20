#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;

string table[3000][2];
string lecture[3000];

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int n, m;
	cin >> n >> m;
	cin.ignore(1);

	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;

		if (a.length() <= b.length())
		{
			table[i][0] = a;
			table[i][1] = b;
		}
		else
		{
			table[i][0] = b;
			table[i][1] = a;
		}
			
	}

	for (int i = 0; i < n; i++)
	{
		cin >> lecture[i];

		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				if (table[x][y] == lecture[i])
				{
					cout << table[x][0] << " ";
					x = m;
					break;
				}
			}
		}
	}


	return 0;
}