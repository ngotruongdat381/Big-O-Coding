#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		int n;
		stack<int> sideStreet;

		cin >> n;		
		
		if (n == 0)
		{
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int rightOrder = 1;
		int i = 0;

		while(true)
		{
			if (i < n && a[i] == rightOrder)
			{
				rightOrder++;
				i++;

			}
			else if (!sideStreet.empty() && sideStreet.top() == rightOrder)
			{
				sideStreet.pop();
				rightOrder++;

			}
			else if (i < n)
			{
				sideStreet.push(a[i]);
				i++;
			}
			else
				break;
		}

		if (rightOrder == n + 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}