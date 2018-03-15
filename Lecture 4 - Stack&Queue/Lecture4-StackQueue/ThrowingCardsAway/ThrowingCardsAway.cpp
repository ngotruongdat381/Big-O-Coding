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
		bool done = false;
		queue<int> q;
		vector<int> a;
		cin >> n;

		int rightOrder = 1;
		int lastMobile;


		if (n == 0)
		{
			return 0;
		}

		if (n == 1)
		{
			cout << "Discarded cards:" << endl;
			cout << "Remaining card: 1" << endl;
			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			//int num;
			//cin >> num;
			q.push(i);

		}

		while (true)
		{	
			if (q.size() == 1)
				break;
			a.push_back(q.front());
			q.pop();

			if (q.size() == 1)
				break;
			q.push(q.front());
			q.pop();
		}

		cout << "Discarded cards: ";

		for (int i = 0; i < int(a.size()) - 1; i++)
			cout << a[i] << ", ";
		cout << a[a.size() - 1] << endl;

		cout << "Remaining card: " << q.front() << endl;
		

	}

	return 0;
}