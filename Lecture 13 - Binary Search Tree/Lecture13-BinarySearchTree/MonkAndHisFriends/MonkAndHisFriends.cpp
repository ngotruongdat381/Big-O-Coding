#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T, N, M;
	cin >> T;

	for (int iT = 0; iT < T; iT++)
	{
		cin >> N >> M;

		unordered_set<long long> s;

		for (int i = 0; i < N; i++)
		{
			long long  num;
			cin >> num;
			s.insert(num);
		}

		for (int i = 0; i < M; i++)
		{
			long long num;
			cin >> num;
			unordered_set<long long>::iterator it = s.find(num);
			if (it != s.end())
				cout << "YES" << endl;
			else
			{
				cout << "NO" << endl;
				s.insert(num);
			}
		}
	}

	return 0;
}