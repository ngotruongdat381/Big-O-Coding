#include<iostream> 
#include <list> 
#include <stack> 
#include <vector>
#include <algorithm>
#include <vector> 
using namespace std;


#define MAX 1000005

int a[MAX];
long long dif[MAX];

int main()
{
	freopen("INPUT.INP", "rt", stdin);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		a[i] = num;
	}

	sort(a, a + N);

	dif[0] = a[N - 1] - a[N - 2];

	for (int i = N - 1; i > 0; i--)
	{
		dif[N - i - 1] = dif[N - i - 2] + (a[i] - a[i - 1])*(N - i);
	}

	dif[N - 1] = dif[N - 2] + a[0] * N;

	vector<long long> v(dif, dif + N);

	vector<long long>::iterator lb;
	lb = lower_bound(v.begin(), v.end(), M);
	if (lb == v.end())
		cout << "0";
	else
	{
		int index = lb - v.begin();

		int rest = *lb - M;

		int tmp = rest / (index + 1);

		int res = a[N - index - 2] + tmp;

		cout << res;
	}
	
	return 0;
}