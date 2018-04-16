#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <vector> 
using namespace std;


#define MAX 1005

vector<int> v;

int main()
{
	freopen("INPUT.INP", "rt", stdin);
	
	int n, k;
	cin >> n >> k;

	v = vector<int>();

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	vector<int>::iterator lb;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		int lookup01 = k + v[i];
		int lookup02 = v[i] - k;
		lb = lower_bound(v.begin(), v.end(), lookup01);
		if (lb != v.end() && *lb == lookup01 && lb != v.begin() + i)
		{
			count++;
		}

		lb = lower_bound(v.begin(), v.end(), lookup02);
		if (lb != v.end() && *lb == lookup02 && lb != v.begin() + i)
		{
			count++;
		}
	}
	cout << count / 2 << endl;

	return 0;
}