#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include<string>
using namespace std;

#define maxn 99999999
int cnt[maxn], ok[maxn];

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int index = 0;

	while(true)
	{ 
		int p, c;
		cin >> p >> c;
		//cin.ignore(1);

		if (p == 0 && c == 0)
			return 0;

		index++;
		cout << "Case " << index << ":" << endl;

		char command;
		deque<int> citizens;

		for (int i = 1; i <= min(p, c); i++)
		{
			citizens.push_back(i);
		}
		
		for (int i = 0; i < c; i++)
		{
			int front = citizens.front();

			cin >> command;

			if (command == 'N')
			{

				while (ok[front] == false && cnt[front] > 0)
				{
					cnt[front]--;
					citizens.pop_front();
					front = citizens.front();
				}
				
				cout << citizens.front() << endl;
				citizens.push_back(citizens.front());
				citizens.pop_front();
				ok[front] = false;
			}

			if (command == 'E')
			{
				int x;
				cin >> x;
				citizens.push_front(x);
				cnt[x]++;
				ok[x] = true;
			}

		}
	}
	return 0;
}