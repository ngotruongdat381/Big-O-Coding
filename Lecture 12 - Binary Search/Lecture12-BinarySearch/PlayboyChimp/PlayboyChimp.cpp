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
	int N;
	cin >> N;

	v = vector<int>();

	for (int i = 0; i < N; i++)
	{
		int h;
		cin >> h;

		v.push_back(h);
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		vector<int>::iterator lb, ub;

		lb = lower_bound(v.begin(), v.end(), q);
		if (lb == v.begin())
		{
			cout << "X ";
		}
		else
		{
			cout << *(lb - 1) << " ";
		}

		ub = upper_bound(v.begin(), v.end(), q);

		if (ub == v.end())
		{
			cout << "X";
		}
		else
		{
			cout << *ub;
		}

		cout << endl;
	}
	
	return 0;
}