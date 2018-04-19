#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;


int main()
{
	freopen("INPUT.INP", "rt", stdin);
	int T, N, X;
	cin >> T;

	for (int iT = 0; iT < T; iT++)
	{
		cin >> N >> X;

		set<int> s;

		for (int i = 0; i < N; i++)
		{
			int num;
			cin >> num;
			s.insert(num);
		}

		if (s.size() == X)
			cout << "Good" << endl;
		else if (s.size() < X)
			cout << "Bad" << endl;
		else
			cout << "Average" << endl;
	}
	return 0;
}