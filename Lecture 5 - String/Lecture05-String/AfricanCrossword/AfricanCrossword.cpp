#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int n, m;
	char table[100][100];
	int okay[100][100];

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//Row
			for (int k = j + 1; k < m; k++)
			{
				if (table[i][k] == table[i][j])
				{
					okay[i][k] = -1;
					okay[i][j] = -1;
				}
			}

			//Column
			for (int k = i + 1; k < n; k++)
			{
				if (table[k][j] == table[i][j])
				{
					okay[k][j] = -1;
					okay[i][j] = -1;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (okay[i][j] != -1)
				cout << table[i][j];
		}
	}

	return 0;
}