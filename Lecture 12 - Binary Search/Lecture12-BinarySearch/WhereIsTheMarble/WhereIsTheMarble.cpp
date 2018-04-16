#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
using namespace std;


#define MAX 1005

vector<int> v;

int main()
{
	freopen("INPUT.INP", "rt", stdin); 
	int T = 1;

	while (true)
	{
		int N, Q;
		cin >> N >> Q;

		if (N == 0 && Q == 0)
		{
			return 0;
		}

		v = vector<int>();

		cout << "CASE# " << T++ << ":" << endl;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;

			v.push_back(num);
		}

		sort(v.begin(), v.end());


		for (int i = 0; i < Q; i++)
		{
			int q;
			cin >> q;
			vector<int>::iterator lb;

			lb = lower_bound(v.begin(), v.end(), q);
			if (*lb == q)
			{
				cout << q << " found at " << (lb - v.begin()) + 1 << endl;
			}
			else
			{
				cout << q << " not found" << endl;
			}

		}
		
	}
	return 0;
}