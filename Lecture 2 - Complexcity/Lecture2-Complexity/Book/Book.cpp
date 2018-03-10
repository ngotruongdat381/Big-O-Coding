#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define maxn 1111111
int a[maxn], b[maxn], c[maxn];


int main()
{

	freopen("INPUT.INP", "rt", stdin);
	int n, t;
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	//==================

	int total_time = 0;
	int max_book = 0;
	int book = 0;
	//int max_i_begin = 0, max_i_end = 0;

	int i_end = 0;
	for (int i_begin = 1; i_begin <= n - max_book; i_begin++)
	{
		while (i_end < n && total_time <= t - a[i_end + 1])		//Dang le dung nay: total_time < t - a[i_end + 1] ma so sai nen dung break
		{
			i_end++;
			total_time += a[i_end];
			book++;
		}
		if (book > max_book)
		{
			max_book = book;
		}
		total_time -= a[i_begin];
		book--;
	}

	cout << max_book;

	cin >> n;
	return 0;
}