#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define maxn 1111111
int a[maxn];

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	while (true)
	{
		int n;
		stack<int> sideStreet;
		stack<int> street;
		bool done = false;

		cin >> n;

		int rightOrder = 1;
		int lastMobile;
		

		if (n == 0)
		{
			return 0;
		}

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < n; i++)
		{
			int mobile;
			mobile = a[i];

			if (mobile != rightOrder)
			{
				if (sideStreet.empty() || mobile == sideStreet.top() - 1)
				{
					sideStreet.push(mobile);
				}
				else
				{
					cout << "no" << endl;
					done = true;
					break;
				}
			}
			else
			{
				if (street.empty() || mobile == street.top() + 1)
				{
					street.push(mobile);
					rightOrder++;

					//extra
					while (!sideStreet.empty() && street.top() + 1 == sideStreet.top())
					{
						street.push(sideStreet.top());
						sideStreet.pop();
						rightOrder++;
					}
					
				}
				else
				{
					cout << "no" << endl;
					done = true;
					break;
				}
			}

		}

		if (!done && (sideStreet.empty() || street.top() < sideStreet.top()) )
		{
			cout << "yes" << endl;
		}

	}

	return 0;
}